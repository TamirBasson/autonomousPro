#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from robot_common_interfaces.msg import SerComStruct

class CmdVelToPwmNode(Node):
    def __init__(self):
        super().__init__('cmd_vel_to_pwm')
        # Subscribe to '/cmd_vel_muxed'
        self.subscription = self.create_subscription(Twist, '/cmd_vel_muxed', self.cmd_vel_callback, 10)
        # Publish to 'motor_throttle_control'
        self.publisher = self.create_publisher(SerComStruct, '/motor_control', 20)

        self.sens = 1.8
        self.wheel_base = 0.475  # Distance between wheels (meters)

    def cmd_vel_callback(self, msg):
        # Extract linear and angular velocities
        linear_x = msg.linear.x
        angular_z = msg.angular.z
        # Calculate left and right wheel velocities
        v_left = linear_x - (self.wheel_base / 2.0) * angular_z * self.sens
        v_right = linear_x + (self.wheel_base / 2.0) * angular_z * self.sens

        # Convert wheel velocities to PWM (low gear only)
        pwm_left = int(v_left*1000)#self.velocity_to_pwm(v_left)
        pwm_right =int(v_right*1000 )#self.velocity_to_pwm(v_right)

        # Prepare and publish control message
        control_msg = SerComStruct()
        control_msg.pwm_l = abs(pwm_left)
        control_msg.pwm_r = abs(pwm_right)

        control_msg.is_reverse_dir_l = bool(pwm_left < 0)
        control_msg.is_reverse_dir_r = bool(pwm_right < 0)

        control_msg.gear = bool(0)  # Static to low gear

        self.publisher.publish(control_msg)

def main(args=None):
    rclpy.init(args=args)
    node = CmdVelToPwmNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
