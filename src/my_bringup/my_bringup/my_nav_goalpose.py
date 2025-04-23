import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from builtin_interfaces.msg import Time

class SimpleNav(Node):
    def __init__(self):
        super().__init__('simple_nav_client')
        self.nav_to_pose_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')

        self.pose_sub = self.create_subscription(
            PoseStamped,
            '/amcl_pose',  # You can replace this with /odom based on your actual situation
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

        self.get_logger().info(f"🎯 Sent goal to: x={x}, y={y}, theta={theta}")

    def pose_callback(self, msg):
        position = msg.pose.position
        orientation = msg.pose.orientation
        self.get_logger().info(f"📍 Current position: x={position.x:.2f}, y={position.y:.2f}")

def main(args=None):
    import math
    rclpy.init(args=args)
    node = SimpleNav()
    
    # Wait a moment before sending goal, wait for system to be ready
    import time
    time.sleep(2)
    
    # Example target point: x=1.0, y=1.5, theta=90 degrees
    node.send_goal(1.0, 1.5, math.radians(90))

    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
