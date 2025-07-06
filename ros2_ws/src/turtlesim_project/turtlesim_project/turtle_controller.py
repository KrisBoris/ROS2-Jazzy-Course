#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from std_msgs.msg import String
from turtlesim_project_interfaces.msg import SpawnedTurtle
from collections import namedtuple


class TurtleControllerNode(Node):

    def __init__(self):
        super().__init__("turtle_controller")

        self.__Constants = namedtuple("Constants", ["FORWARD_SPEED", "FORWARD_TURNING_SPEED", "TURNING_SPEED", "VECTORS_ALIGNMENT", "TURTLES_DISTANCE"])
        self.__constants = self.__Constants(FORWARD_SPEED=2.0, FORWARD_TURNING_SPEED=0.8, TURNING_SPEED=3.0, VECTORS_ALIGNMENT=1.5, TURTLES_DISTANCE=0.3)

        self.__spawned_turtles: list[SpawnedTurtle] = []
        self.__prev_x = 5.544445    # Turtle's starting x position
        self.__prev_y = 5.544445    # Turtle's starting y position

        self.__publisher_velocity = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.__publisher_turtle_kill = self.create_publisher(String, "killed_turtle", 10)
        self.__subscriber_spawned_turtle_position = self.create_subscription(SpawnedTurtle, "spawned_turtle", self.callback_subscription_spawned_turtle, 10)   
        self.__subscriber_turtle_postion = self.create_subscription(Pose, "/turtle1/pose", self.callback_subscription_turtle_position, 10)     
        self.get_logger().info("turtle_controller node has been started")

    def callback_subscription_spawned_turtle(self, msg: SpawnedTurtle):
        self.__spawned_turtles.append(msg)            

    def callback_subscription_turtle_position(self, turtle_postion: Pose):
        if len(self.__spawned_turtles) > 0:
            
            if (abs(turtle_postion.x - self.__spawned_turtles[0].pose.x) < self.__constants.TURTLES_DISTANCE 
                and abs(turtle_postion.y - self.__spawned_turtles[0].pose.y) < self.__constants.TURTLES_DISTANCE):

                self.publish_turtle_killed()

            else:
                cmd_vel = Twist()               

                vel_vec_x = turtle_postion.x - self.__prev_x
                vel_vec_y = turtle_postion.y - self.__prev_y                

                dest_vec_x = self.__spawned_turtles[0].pose.x - turtle_postion.x
                dest_vec_y = self.__spawned_turtles[0].pose.y - turtle_postion.y                

                if vel_vec_x != 0 and dest_vec_x != 0:                                                           

                    if (self.sign_match(vel_vec_x, dest_vec_x) and self.sign_match(vel_vec_y, dest_vec_y) 
                        and abs(vel_vec_y / vel_vec_x - dest_vec_y / dest_vec_x) < self.__constants.VECTORS_ALIGNMENT):

                        cmd_vel.linear.x = self.__constants.FORWARD_SPEED                                                
                    
                    elif (not self.sign_match(vel_vec_x, dest_vec_x) and not self.sign_match(vel_vec_y, dest_vec_y) 
                        and abs(vel_vec_y / vel_vec_x - dest_vec_y / dest_vec_x) < self.__constants.VECTORS_ALIGNMENT):
                                                
                        cmd_vel.angular.z = 10.0
                        cmd_vel.linear.x = 10.0
                        
                    else:                    

                        cmd_vel.linear.x = self.__constants.FORWARD_TURNING_SPEED

                        # Turning the turtle
                        if vel_vec_x > 0 and dest_vec_x > 0 or vel_vec_x < 0 and dest_vec_x < 0:
                            if vel_vec_y / vel_vec_x > dest_vec_y / dest_vec_x:
                                # Turn right (clockwise)
                                cmd_vel.angular.z = -self.__constants.TURNING_SPEED                            
                            else:
                                # TUrn left (anticlockwise)
                                cmd_vel.angular.z = self.__constants.TURNING_SPEED
                        elif vel_vec_x > 0 and dest_vec_x < 0:
                            if vel_vec_y > 0 and dest_vec_y > 0:
                                # Turn left (anticlockwise)
                                cmd_vel.angular.z = self.__constants.TURNING_SPEED
                            elif vel_vec_y < 0 and dest_vec_y < 0:
                                # Turn right (clockwise)
                                cmd_vel.angular.z = -self.__constants.TURNING_SPEED
                            elif vel_vec_y / vel_vec_x > dest_vec_y / dest_vec_x:
                                # Turn left (anticlockwise)
                                cmd_vel.angular.z = self.__constants.TURNING_SPEED
                            elif vel_vec_y / vel_vec_x < dest_vec_y / dest_vec_x:
                                # Turn right (clockwise)
                                cmd_vel.angular.z = -self.__constants.TURNING_SPEED
                        elif vel_vec_x < 0 and dest_vec_x > 0:
                            if vel_vec_y > 0 and dest_vec_y > 0:
                                # Turn right (clockwise)
                                cmd_vel.angular.z = -self.__constants.TURNING_SPEED
                            elif vel_vec_y < 0 and dest_vec_y < 0:
                                # Turn left (clockwise)
                                cmd_vel.angular.z = self.__constants.TURNING_SPEED
                            elif vel_vec_y / vel_vec_x > dest_vec_y / dest_vec_x:
                                # Turn right (clockwise)
                                cmd_vel.angular.z = -self.__constants.TURNING_SPEED
                            elif vel_vec_y / vel_vec_x < dest_vec_y / dest_vec_x:
                                # Turn left (anticlockwise)
                                cmd_vel.angular.z = self.__constants.TURNING_SPEED

                else:
                    cmd_vel.linear.x = self.__constants.FORWARD_SPEED
                    cmd_vel.angular.z = self.__constants.TURNING_SPEED

                self.__prev_x = turtle_postion.x
                self.__prev_y = turtle_postion.y
                                  
                self.__publisher_velocity.publish(cmd_vel)

    def publish_turtle_killed(self):
        msg = String()        
        msg.data = self.__spawned_turtles[0].name

        self.__spawned_turtles.pop(0)

        self.__publisher_turtle_kill.publish(msg)

    def sign_match(self, var1, var2) -> bool:
        if self.sign_check(var1) == self.sign_check(var2):
            return True
        else:
            return False            

    def sign_check(self, var) -> int:
        if var >= 0:
            return 1
        else:
            return -1

def main(args=None):
    rclpy.init(args=args)
    node = TurtleControllerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()