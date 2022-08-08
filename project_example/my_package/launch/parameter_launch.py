from launch import LaunchDescription
from launch_ros.actions import Node

parameter_node = Node(  package="my_package",
                        executable="parameter",
                        name="paramater_node",
                        parameters=)


def generate_launch_description():
    return LaunchDescription([
        Node(
            package="cpp_parameters",
            executable="parameter_node",
            name="custom_parameter_node",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"my_parameter": "earth"}
            ]
        )
    ])