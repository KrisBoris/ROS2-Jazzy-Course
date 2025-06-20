#!/usr/bin/env python3

import rclpy
from rclpy.node import Node


class MyNode(Node):
    
    def __init__(self):
        super().__init__("test_py")
        self.counter = 0
        self.get_logger().info("Hello there")        
        self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        self.get_logger().info("Counter: " + str(self.counter))        
        if(self.counter >= 10):
            self.get_logger().info("General Kenobi!")        
        self.counter += 1


def main(args=None):
    rclpy.init(args=args)
    node = MyNode()      
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()