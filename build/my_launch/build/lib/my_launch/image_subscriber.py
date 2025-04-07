import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class ImageSubscriber(Node):
    def __init__(self):
        super().__init__('image_subscriber')
        self.subscription = self.create_subscription(
            Image,
            '/camera/color/image_raw',  # 根据你摄像头话题名进行修改
            self.listener_callback,
            10
        )
        self.bridge = CvBridge()
        self.get_logger().info('Image subscriber with OpenCV started.')

    def listener_callback(self, msg):
        self.get_logger().info('Got an image!')  # 看有没有连续输出
        try:
            # 将ROS图像消息转换为OpenCV格式
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f'Failed to convert image: {e}')
            return

        # 显示图像窗口
        cv2.imshow("Camera Image", cv_image)
        cv2.waitKey(1)  # 必须要有，不然窗口不刷新

def main(args=None):
    rclpy.init(args=args)
    node = ImageSubscriber()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()  # 清理窗口

if __name__ == '__main__':
    main()
