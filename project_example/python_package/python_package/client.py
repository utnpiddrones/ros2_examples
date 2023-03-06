import sys
from my_interface.srv import MySrv
import rclpy
from rclpy.node import Node


class MinimalClientAsync(Node):

    def __init__(self):
        super().__init__('minimal_client_async')
        self.cli = self.create_client(MySrv, 'service_name')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = MySrv.Request()

    def send_request(self, a, b, c):
        self.req.a = a
        self.req.b = b
        self.req.c = c
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()


def main():
    rclpy.init()

    minimal_client = MinimalClientAsync()
    response = minimal_client.send_request(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]))
    minimal_client.get_logger().info(
        'Result of sum: for %d + %d + %d = %d' %
        (int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]), response.sum))

    minimal_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()