from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    client1_node = Node(package="my_package",
                executable="client",
                name="my_client_node",
                arguments=[ "1", "2", "3"])

    client2_node = Node(package="my_package",
                    executable="client",
                    name="my_client_node2",
                    arguments=["4", "5", "6"])


    service_node = Node(package="my_package",
                    executable="service",
                    name="my_service_node")


    return LaunchDescription([client1_node, client2_node, service_node])