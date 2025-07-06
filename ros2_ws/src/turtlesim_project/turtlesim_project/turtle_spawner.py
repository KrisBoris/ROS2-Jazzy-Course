#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from turtlesim.srv import Spawn
from turtlesim.srv import Kill
from std_msgs.msg import String
from turtlesim_project_interfaces.msg import SpawnedTurtle
from functools import partial
import random
import time

class TurtleSpawnerNode(Node):

    def __init__(self):
        super().__init__("turtle_spawner")

        self.declare_parameter("spawn_pace", 5.0)   # Turtles' spawn pace

        self.__spawn_pace = self.get_parameter("spawn_pace")        

        self.__client_spawn = self.create_client(Spawn, "spawn")
        self.__client_kill = self.create_client(Kill, "kill")
        self.__publisher_spawned_turtle = self.create_publisher(SpawnedTurtle, "spawned_turtle", 10)
        self.__subscriber_killed_turtle = self.create_subscription(String, "killed_turtle", self.callback_subscription_killed_turtle, 10)
        self.__spawn_timer = self.create_timer(self.__spawn_pace.value, self.callback_spawn_timer)        

        random.seed(int(round(time.time())))
        self.get_logger().info("turtle_spawner node has been started")

    def callback_spawn_timer(self):
        while not self.__client_spawn.wait_for_service(1.0):
            self.get_logger().info("Standing here...")

        new_turtle = Spawn.Request()
        new_turtle.x = random.uniform(0, 10)
        new_turtle.y = random.uniform(0, 10)    

        future = self.__client_spawn.call_async(new_turtle)
        future.add_done_callback(partial(self.__callback_service_spawn, request=new_turtle))  

    def __callback_service_spawn(self, future, request):
        response = future.result()        
        
        new_turtle_msg = SpawnedTurtle()
        new_turtle_msg.name = response.name
        new_turtle_msg.pose.x = request.x
        new_turtle_msg.pose.y = request.y

        self.__publisher_spawned_turtle.publish(new_turtle_msg)
        
        self.get_logger().info("Turtle named " + str(response.name) + " has been spawned")

    def __callback_service_kill(self, future):        
        self.get_logger().info("Turtle has been killed")

    def callback_subscription_killed_turtle(self, name: String):        
        while not self.__client_kill.wait_for_service(1.0):
            self.get_logger().info("Standing here...")

        target_turtle = Kill.Request()
        target_turtle.name = name.data

        future = self.__client_kill.call_async(target_turtle)
        future.add_done_callback(self.__callback_service_kill)        


def main(args=None):
    rclpy.init(args=args)
    node = TurtleSpawnerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()