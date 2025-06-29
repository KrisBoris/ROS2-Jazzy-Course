#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist


class TurtleControllerNode(Node):

    def __init__(self):
        super().__init__("turtle_controller")

        self.__publisher_velocity = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.__timer_velocity = self.create_timer(1.0, self.callback_timer_velocity)
        self.get_logger().info("turtle_controller node has been started")

    def callback_timer_velocity(self):
        cmd_vel = Twist()
        cmd_vel.linear.x = 1.0
        cmd_vel.angular.z = 1.0

        self.__publisher_velocity.publish(cmd_vel)


def main(args=None):
    rclpy.init(args=args)
    node = TurtleControllerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()