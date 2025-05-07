import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from builtin_interfaces.msg import Time
import math

from tf2_ros import Buffer, TransformListener
from geometry_msgs.msg import TransformStamped


# from my_bringup.scripts import calc_pose
from common_interface.msg import RectDepth
from std_msgs.msg import Int32MultiArray, Float32MultiArray
class SimpleNav(Node):
    def __init__(self):
        super().__init__('simple_nav_client')
        self.diff_x, self.diff_y = [0,0]
        self.theta = 0
        self.current_pose = None

        self.nav_to_pose_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        self.target_depth = self.create_subscription(RectDepth, 'task/rect_depth', self.exec_callback, 10)
        self.pose_sub = self.create_subscription(
            PoseStamped,
            '/odom',  
            self.pose_callback,
            10
        )
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.timer = self.create_timer(0.5, self.update_pose_from_tf) 


    def send_goal(self, x, y, theta=0.0):
        goal_msg = NavigateToPose.Goal()

        goal_msg.pose.header.frame_id = 'map'
        goal_msg.pose.header.stamp = self.get_clock().now().to_msg()

        goal_msg.pose.pose.position.x = x
        goal_msg.pose.pose.position.y = y
        goal_msg.pose.pose.orientation.z = math.sin(theta / 2.0)
        goal_msg.pose.pose.orientation.w = math.cos(theta / 2.0)

        self.nav_to_pose_client.wait_for_server()
        self.nav_to_pose_client.send_goal_async(goal_msg)

        self.get_logger().info(f"Sent goal to: x={x}, y={y}, theta={theta}")

    def exec_callback(self, msg):
        self.diff_x, self.diff_y = msg.coordinate_diff.data
        self.theta = msg.theta
        
        if not self.current_pose is None:
            current = self.current_pose
            robot_x = current.position.x
            robot_y = current.position.y
            robot_yaw = self.get_yaw_from_quaternion(current.orientation)

            # 6. from base_link tf to map 坐标（简单用 2D 旋转平移）
            target_x = robot_x + self.diff_x
            target_y = robot_y + self.diff_y
            target_yaw = robot_yaw + self.theta
            self.get_logger().info(f"Sending goal: x={target_x:.2f}, y={target_y:.2f}, theta={target_yaw:.2f}")
            self.send_goal(target_x, target_y, target_yaw)
        else:
            self.get_logger().warn("No current pose yet")

    def pose_callback(self, msg):
        self.current_pose = msg.pose
        self.get_logger().info(f"Current position: x={msg.pose.position.x:.2f}, y={msg.pose.position.y:.2f}")


    def update_pose_from_tf(self):
        try:
            if not self.tf_buffer.can_transform('map', 'base_link', rclpy.time.Time(), timeout=rclpy.duration.Duration(seconds=2.0)):
                self.get_logger().warn("⚠️ TF transform map→base_link not available yet.")
                return
            from geometry_msgs.msg import PoseStamped, Point, Quaternion
            tf = self.tf_buffer.lookup_transform('map', 'base_link', rclpy.time.Time())
            pose = PoseStamped()
            pose.header = tf.header
            pose.pose.position = Point(
                x=tf.transform.translation.x,
                y=tf.transform.translation.y,
                z=tf.transform.translation.z
            )
            pose.pose.orientation = Quaternion(
                x=tf.transform.rotation.x,
                y=tf.transform.rotation.y,
                z=tf.transform.rotation.z,
                w=tf.transform.rotation.w
            )
            self.current_pose = pose
            self.get_logger().info(f"📍 Global pose: x={pose.pose.position.x:.2f}, y={pose.pose.position.y:.2f}")
        except Exception as e:
            self.get_logger().warn(f"TF lookup failed: {e}")
    def get_yaw_from_quaternion(self, q):
        # 欧拉角提取，返回 yaw（绕Z轴旋转）
        siny_cosp = 2 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
        return math.atan2(siny_cosp, cosy_cosp)


def main(args=None):
    import math
    rclpy.init(args=args)
    node = SimpleNav()
    
    # delay to send goal，waiting for system ready
    import time
    time.sleep(2)

    # send_goal()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
