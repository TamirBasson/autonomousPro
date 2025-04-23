import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from builtin_interfaces.msg import Time
import math
# from my_bringup.scripts import calc_pose
from common_interface.msg import RectDepth
class SimpleNav(Node):
    def __init__(self):
        super().__init__('simple_nav_client')

        self.current_pose = None

        self.nav_to_pose_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        self.target_depth = self.create_subscription(RectDepth, 'task/rect_depth', self.exec_callback, 10)
        self.pose_sub = self.create_subscription(
            PoseStamped,
            '/odom',  
            self.pose_callback,
            10
        )

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
        # 1. get ROI center
        rect = msg.rect
        depth = msg.depth  # mm
        if len(rect) != 4:
            self.get_logger().warn("Received invalid rect")
            return
        
        u = (rect[0] + rect[2]) / 2  # xmin + xmax / 2
        v = (rect[1] + rect[3]) / 2  # ymin + ymax / 2

        # 2. camera inner params
        fx = 600.0
        fy = 600.0
        cx = 320.0
        cy = 240.0

        # 3. pinhole estminate
        Z = depth / 1000.0
        X = (u - cx) * Z / fx
        Y = (v - cy) * Z / fy

        self.get_logger().info(f"Estimated target in camera frame: X={X:.2f}, Y={Y:.2f}, Z={Z:.2f}")

        # ⚠️ 4. baselink tf camera link

        # 5. current pose
        if self.current_pose is not None:
            current = self.current_pose
            robot_x = current.position.x
            robot_y = current.position.y
            yaw = self.get_yaw_from_quaternion(current.orientation)

            # 6. 将目标坐标从 base_link 坐标变换到 map 坐标（简单用 2D 旋转平移）
            target_x = robot_x + X * math.cos(yaw) - Z * math.sin(yaw)
            target_y = robot_y + X * math.sin(yaw) + Z * math.cos(yaw)

            self.get_logger().info(f"Sending goal: x={target_x:.2f}, y={target_y:.2f}")
            self.send_goal(target_x, target_y, yaw)
        else:
            self.get_logger().warn("No current pose yet")

    def pose_callback(self, msg):
        self.current_pose = msg.pose
        self.get_logger().info(f"Current position: x={msg.pose.position.x:.2f}, y={msg.pose.position.y:.2f}")

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
