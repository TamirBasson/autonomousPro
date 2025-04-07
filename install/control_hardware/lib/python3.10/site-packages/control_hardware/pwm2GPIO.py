#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from gpiozero import PWMOutputDevice, DigitalOutputDevice
from common_interface.msg import SerComStruct

class PwmSubNode(Node):
    def __init__(self):
        super().__init__('ser_com_subscriber')
        self.get_logger().info("Node initiated")
        self.sub_ = self.create_subscription(SerComStruct, 'motor_control', self.listener_callback, 20)

        # Pin layout
        self.pwm_l = PWMOutputDevice(18, frequency=500)  # PWM for left wheel
        self.pwm_r = PWMOutputDevice(13, frequency=500)  # PWM for right wheel
        self.is_reverse_l = DigitalOutputDevice(15)      # Reverse state for left wheel
        self.is_reverse_r = DigitalOutputDevice(19)      # Reverse state for right wheel
        self.gear_l = DigitalOutputDevice(14)            # Gear state for left wheel
        self.gear_r = DigitalOutputDevice(26)            # Gear state for right wheel

        self.prev_msg = None  # To track gear state changes

    def listener_callback(self, msg):
        self.is_reverse_l.value =  msg.is_reverse_dir_l
        self.is_reverse_r.value =  msg.is_reverse_dir_r

        # Set PWM values (scale to [0, 1] for gpiozero)
        if self.is_reverse_l.value:
            self.pwm_l.value = min(abs(msg.pwm_l/1000) ,0.52)
        else:
            self.pwm_l.value = min(abs(msg.pwm_l/1000) ,0.52)

        if self.is_reverse_r.value:
            self.pwm_r.value = min(abs(msg.pwm_r/1000) ,0.52)
        else:
            self.pwm_r.value = min(abs(msg.pwm_r/1000) ,0.52)

        self.get_logger().info(f"Sending negative PWM: \nLeft: {self.pwm_l.value}, \tRight: {self.pwm_r.value}\n dir_L:{self.is_reverse_l.value},dir_R{self.is_reverse_r.value}")

        # Set gear values
        self.gear_l.value = msg.gear
        self.gear_r.value = msg.gear
        
        if self.prev_msg != msg.gear:
            self.get_logger().info(f"Gear changed to {'LOW' if msg.gear else 'HIGH'}")
            self.prev_msg = msg.gear


def main(args=None):
    rclpy.init(args=None)
    node = PwmSubNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
