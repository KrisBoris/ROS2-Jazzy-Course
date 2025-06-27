#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import LedPanelState
from my_robot_interfaces.srv import SetLed


class LedPanelStateNode(Node):

    def __init__(self):
        super().__init__("led_panel")

        self.declare_parameter("led_states", [False, False, False])

        self.led_panel_status = self.get_parameter("led_states").value         
        self.service_ = self.create_service(SetLed, "set_led", self.callback_service)
        self.publisher_ = self.create_publisher(LedPanelState, "led_panel_state", 10)
        self.timer_ = self.create_timer(1.0, self.callback_timer)
        self.get_logger().info("led_panel has been started")

    def callback_service(self, request: SetLed.Request, response: SetLed.Response):
        self.led_panel_status[request.led_number - 1] = request.led_status
        response.success = True
        return response

    def callback_timer(self):
        msg = LedPanelState()
        for i in range(len(self.led_panel_status)):
            msg.led_status[i] = self.led_panel_status[i]
        self.publisher_.publish(msg)        


def main(args=None):
    rclpy.init(args=args)
    node = LedPanelStateNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()