#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts

class AddTwoIntsServer(Node):

    def __init__(self):
        super().__init__("add_two_ints")
        self.service = self.create_service(AddTwoInts, "add_two_ints", self.callbackService)
        self.get_logger().info("add_two_ints service has been started")

    def callbackService(self, request: AddTwoInts.Request, response: AddTwoInts.Response):
        response.sum = request.a + request.b
        return response


def main(args=None):
    rclpy.init(args=args)
    node = AddTwoIntsServer()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()