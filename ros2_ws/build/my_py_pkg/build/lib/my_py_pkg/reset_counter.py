 #!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from example_interfaces.srv import SetBool
from functools import partial

class ResetCounterNode(Node):

    def __init__(self):
        super().__init__("reset_counter")
        self.client_ = self.create_client(SetBool, "reset_counter")
        self.timer_ = self.create_timer(10.0, self.callback_timer)
        self.get_logger().info("reset_counter node has been started")

    def callback_timer(self):
        while not self.client_.wait_for_service(1.0):
            self.get_logger().info("Standing here...")
        
        request = SetBool.Request()
        request.data = True

        future = self.client_.call_async(request)
        future.add_done_callback(partial(self.callback_future, request=request))

    def callback_future(self, future, request):
        response = future.result()
        self.get_logger().info("Request: " + str(request.data) + ", response: " + str(response.message))


def main(args=None):
    rclpy.init(args=args)
    node = ResetCounterNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()