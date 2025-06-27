#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from example_interfaces.msg import Int64

class NumberPublisherNode(Node):

    def __init__(self):
        super().__init__("number_publisher")
        self.declare_parameter("number", 2)
        self.declare_parameter("timer_period", 2.0)
        self.number_ = self.get_parameter("number").value
        self.publisher_ = self.create_publisher(Int64, "number", 10)
        self.timer_ = self.create_timer(self.get_parameter("timer_period").value, self.callback_publish)
        self.add_on_set_parameters_callback(self.callback_parameters)
        self.get_logger().info("number_publisher node has been started")

    def callback_publish(self):
        msg = Int64()
        msg.data = self.number_
        self.publisher_.publish(msg)

    def callback_parameters(self, params: list[Parameter]):
        for param in params:
            if param.name == "number":
                self.number_ = param.value


def main(args=None):
    rclpy.init(args=args)
    node = NumberPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()