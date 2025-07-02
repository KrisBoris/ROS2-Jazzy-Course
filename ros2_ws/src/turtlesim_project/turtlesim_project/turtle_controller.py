#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from std_msgs.msg import Bool


class TurtleControllerNode(Node):

    def __init__(self):
        super().__init__("turtle_controller")

        self.__spawned_turtles: list[Pose] = []
        self.__prev_x = 0.0
        self.__prev_y = 0.0

        self.__publisher_velocity = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.__publisher_turtle_kill = self.create_publisher(Bool, "killed_turtle", 10)
        self.__subscriber_spawned_turtle_position = self.create_subscription(Pose, "spawned_turtle", self.callback_subscription_spawned_turtle)   
        self.__subscriber_turtle_postion = self.create_subscription(Pose, "/turtle1/pose", self.callback_subscription_turtle_position)     
        self.get_logger().info("turtle_controller node has been started")

    def callback_subscription_spawned_turtle(self, msg: Pose):
        self.__spawned_turtles.append(msg)            

    def callback_subscription_turtle_position(self, turtle_postion: Pose):
        if len(self.__spawned_turtles) > 0:
            
            if abs(turtle_postion.x - self.__spawned_turtles[0]) < 0.05 and abs(turtle_postion.y - self.__spawned_turtles[0]) < 0.05:
                self.__publisher_turtle_kill()
            else:
                cmd_vel = Twist()

                # Count direction -> set new angular velocity -> reach proper direction -> full speed
                # x and y vectors
                # vectors proportions
                # if x vectors have the same value -> if vel y > dest y -> turn right else turn left

                vel_vec_x = turtle_postion.x - self.__prev_x
                vel_vec_y = turtle_postion.y - self.__prev_y

                dest_vec_x = self.__spawned_turtles[0].x - turtle_postion.x
                dest_vec_y = self.__spawned_turtles[0].y - turtle_postion.y

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