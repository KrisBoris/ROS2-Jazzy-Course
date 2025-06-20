#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64

class NumberPublisherNode(Node):

    def __init__(self):
        super().__init__("number_publisher")
        self.number_ = 2
        self.publisher_ = self.create_publisher(Int64, "number", 10)
        self.timer_ = self.create_timer(2.0, self.callback_publish)
        self.get_logger().info("number_publisher node has been started")

    def callback_publish(self):
        msg = Int64()
        msg.data = self.number_
        self.publisher_.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = NumberPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()