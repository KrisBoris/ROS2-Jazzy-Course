#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

class MyNode(Node):     # Change name

    def __init__(self):
        super().__init__("node_name")   # Change name


def main(args=None):
    rclpy.init(args=args)
    node = MyNode()     # Change name
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()