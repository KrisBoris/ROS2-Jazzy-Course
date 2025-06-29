#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from std_msgs.msg import Bool


class TurtleControllerNode(Node):

    def __init__(self):
        super().__init__("turtle_controller")

        self.__spawned_turtles = []

        self.__publisher_velocity = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.__publisher_turtle_kill = self.create_publisher(Bool, "killed_turtle", 10)
        self.__subscriber_spawned_turtle_position = self.create_subscription(Pose, "spawned_turtle", self.callback_subscription_spawned_turtle)   
        self.__subscriber_turtle_postion = self.create_subscription(Pose, "/turtle1/pose", self.callback_subscription_turtle_position)     
        self.get_logger().info("turtle_controller node has been started")

    def callback_subscription_spawned_turtle(self, msg: Pose):
        self.__spawned_turtles.append(msg)    

    def callback_subscription_turtle_position(self, turtle_postion: Pose):
        cmd_vel = Twist()

        # Count direction -> set new angular velocity -> reach proper direction -> full speed

        self.__publisher_velocity.publish(cmd_vel)

    def publish_turtle_killed(self):
        msg = Bool()
        msg.data = True

        self.__spawned_turtles.pop(0)

        self.__publisher_turtle_kill.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = TurtleControllerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()