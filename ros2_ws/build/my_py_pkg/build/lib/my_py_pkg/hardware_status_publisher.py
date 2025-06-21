#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import HardwareStatus

class HardwareStatusPublisherNode(Node):

    def __init__(self):
        super().__init__("hardware_status_publisher")
        self.publisher_ = self.create_publisher(HardwareStatus, "hardware_status", 10)
        self.timer_ = self.create_timer(1.0, self.callbackTimer)

    def callbackTimer(self):
        msg = HardwareStatus()
        msg.temperature = 113.1
        msg.are_motors_ready = True
        msg.debug_message = "The only thing I know for real..."

        self.publisher_.publish(msg)

    
def main(args=None):
    rclpy.init(args=args)
    node = HardwareStatusPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()