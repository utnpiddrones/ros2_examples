from launch import LaunchDescription
from launch_ros.actions import Node

parameter_node = Node(  
    package="my_package",
    executable="parameter",
    name="parameter_node",
    parameters=[
        {"my_parameter": "earth"}
    ],
    output="screen",
    emulate_tty=True,
)


def generate_launch_description():
    return LaunchDescription([parameter_node])