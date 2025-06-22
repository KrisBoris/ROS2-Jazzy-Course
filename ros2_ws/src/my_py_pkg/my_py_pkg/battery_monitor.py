#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from my_robot_interfaces.srv import SetLed


class BatteryMonitorNode(Node):

    def __init__(self):
        super().__init__("battery_monitor_node")
        self.battery_state = False  # True = empty, False = full
        self.client_ = self.create_client(SetLed, "set_led")
        self.short_timer_ = self.create_timer(4.0, self.callback_short_timer)
        self.long_timer_ = self.create_timer(6.0, self.callback_long_timer)
        self.get_logger().info("battery_monitor node has been started")

    def callback_short_timer(self):
        self.battery_state = True

        while not self.client_.wait_for_service(1.0):
            self.get_logger().info("Standing here...")

        request = SetLed.Request()
        request.led_status = self.battery_state
        request.led_number = 3

        future = self.client_.call_async(request)
        future.add_done_callback(self.callback_service)

        self.short_timer_.cancel()
        self.long_timer_.reset()

    def callback_long_timer(self):
        self.battery_state = False

        while not self.client_.wait_for_service(1.0):
            self.get_logger().info("Standing here...")

        request = SetLed.Request()
        request.led_status = self.battery_state
        request.led_number = 3

        future = self.client_.call_async(request)
        future.add_done_callback(self.callback_service)

        self.long_timer_.cancel()
        self.short_timer_.reset()

    def callback_service(self, future):
        response = future.result()
        self.get_logger().info("Response was: " + str(response.success))

def main(args=None):
    rclpy.init(args=args)
    node = BatteryMonitorNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()