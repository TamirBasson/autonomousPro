#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from common_interface.msg import KeyCtrl
from gpiozero import PWMOutputDevice, DigitalOutputDevice
from builtin_interfaces.msg import Time
class CmdVelToPwmGPIO(Node):
    LINEAR_SCALE = 1.0  # Linear velocity scale factor
    ANGULAR_SCALE = 3.0 # Angular velocity scale factor
    MAX_SPEED = 0.47

    manualCtrl = True
    def __init__(self):
        super().__init__('cmd_vel_to_pwm_gpio')
        self.subscription = self.create_subscription(KeyCtrl, '/cmd_joy', self.cmd_joy_callback, 10)
        self.subscription = self.create_subscription(Twist, '/cmd_vel', self.cmd_vel_callback, 10)
        # Robot parameters
        self.wheel_base = 0.475  # Wheel base (meters)
        # GPIO settings
        try:
            self.pwm_l = PWMOutputDevice(18, frequency=500)
            self.pwm_r = PWMOutputDevice(13, frequency=500)
            self.is_reverse_l = DigitalOutputDevice(15)
            self.is_reverse_r = DigitalOutputDevice(19)
            self.gear_l = DigitalOutputDevice(14)
            self.gear_r = DigitalOutputDevice(26)
        except Exception as e:
            self.get_logger().error(f"GPIO initialization failed: {e}")
            return
        self.timer = self.create_timer(0.4, self.logSpeed)


    def logSpeed(self):
        self.get_logger().info(f"PWM -> Left: {self.pwm_l.value}, Right: {self.pwm_r.value} | mode:{self.manualCtrl}")

    def cmd_joy_callback(self, msg):
        self.manualCtrl = not msg.allow_nav
        if self.manualCtrl:
            """ Process cmd_vel and control GPIO """
            linear_x = msg.manual_spd.linear.x * self.LINEAR_SCALE
            angular_z = msg.manual_spd.angular.z * self.ANGULAR_SCALE

            v_left = linear_x - (self.wheel_base / 2.0) * angular_z
            v_right = linear_x + (self.wheel_base / 2.0) * angular_z
            # self.get_logger().info(f"v_left: {v_left}, v_right: {v_right} | mode:{self.manualCtrl}")

            # Convert speed to PWM
            pwm_left = self.velocity_to_pwm(v_left)
            pwm_right = self.velocity_to_pwm(v_right)

            # Set direction
            self.is_reverse_l.value = pwm_left < 0
            self.is_reverse_r.value = pwm_right < 0

            # Set PWM range 0~1
            self.pwm_l.value = min(abs(pwm_left), self.MAX_SPEED)
            self.pwm_r.value = min(abs(pwm_right), self.MAX_SPEED)

            self.gear_l.value = False
            self.gear_r.value = False
        # self.get_logger().info(f"PWM -> Left: {self.pwm_l.value}, Right: {self.pwm_r.value} | mode:{self.manualCtrl}")
    def cmd_vel_callback(self,msg):
        if not self.manualCtrl:
            linear_x = msg.linear.x * self.LINEAR_SCALE
            angular_z = msg.angular.z * self.ANGULAR_SCALE

            v_left = linear_x - (self.wheel_base / 2.0) * angular_z
            v_right = linear_x + (self.wheel_base / 2.0) * angular_z

            v_left = v_left if v_left >= 0 else 0
            v_right = v_right if v_right >= 0 else 0
            # Convert speed to PWM
            pwm_left = self.velocity_to_pwm(v_left)
            pwm_right = self.velocity_to_pwm(v_right)

            # Set direction
            self.is_reverse_l.value = pwm_left < 0
            self.is_reverse_r.value = pwm_right < 0

            # Set PWM range 0~1
            self.pwm_l.value = min(abs(pwm_left), self.MAX_SPEED)
            self.pwm_r.value = min(abs(pwm_right), self.MAX_SPEED)

            # self.get_logger().info(f"PWM -> Left: {self.pwm_l.value}, Right: {self.pwm_r.value}|mode{self.manualCtrl}")

            self.gear_l.value = False
            self.gear_r.value = False
            
    def velocity_to_pwm(self, velocity):
        """ Convert speed to PWM value """
        threshold = 0.05
        if abs(velocity) < threshold:
            return 0  # Speed too low, stop
        pwm_value = (0.70 * abs(velocity) + 0.36)
        if velocity < 0:
            return -pwm_value 
        else:
            return pwm_value

def main(args=None):
    rclpy.init(args=args)
    node = CmdVelToPwmGPIO()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
