import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from geometry_msgs.msg import PoseStamped
from nav2_msgs.action import FollowWaypoints
import math

class WaypointNav(Node):
    def __init__(self):
        super().__init__('waypoint_nav')
        self._client = ActionClient(self, FollowWaypoints, 'follow_waypoints')

    def send_waypoints(self, points):
        goal_msg = FollowWaypoints.Goal()

        for (x, y, theta_deg) in points:
            pose = PoseStamped()
            pose.header.frame_id = 'map'
            pose.header.stamp = self.get_clock().now().to_msg()
            pose.pose.position.x = x
            pose.pose.position.y = y

            theta = math.radians(theta_deg)
            pose.pose.orientation.z = math.sin(theta / 2.0)
            pose.pose.orientation.w = math.cos(theta / 2.0)

            goal_msg.poses.append(pose)

        self._client.wait_for_server()
        self._client.send_goal_async(goal_msg)
        self.get_logger().info("📌 Sent waypoints to Navigate")

def main(args=None):
    rclpy.init(args=args)
    node = WaypointNav()

    # 目标点列表：(x, y, 朝向角度°)
    waypoints = [
        (1.0, 1.0, 0),       # 第一个点
        (2.0, 1.0, 90),      # 第二个点
        (2.0, 2.0, 180),     # 第三个点
        (1.0, 2.0, -90),     # 第四个点
    ]

    # 稍等一下系统
    import time
    time.sleep(2)

    node.send_waypoints(waypoints)

    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
