#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64
from example_interfaces.srv import SetBool

class NumberCounterNode(Node):

    def __init__(self):
        super().__init__("number_counter")
        self.counter_ = 0
        self.subscriber_ = self.create_subscription(Int64, "number", self.callback_number, 10)
        self.publisher_ = self.create_publisher(Int64, "number_count", 10)
        self.get_logger().info("number_counter node has been started")
        self.service_ = self.create_service(SetBool, "reset_counter", self.callback_service)

    def callback_number(self, number: Int64):
        msg = Int64()
        self.counter_ += number.data
        msg.data = self.counter_
        self.publisher_.publish(msg)

    def callback_service(self, request: SetBool.Request, response: SetBool.Response):
        if(request.data):
            self.counter_ = 0
            response.message = "Counter has been reseted"
        else:
            response.message = "Counter was not reseted"
        
        response.success = True        
        return response


def main(args=None):
    rclpy.init(args=args)
    node = NumberCounterNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()