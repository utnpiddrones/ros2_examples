from launch import LaunchDescription
from launch_ros.actions import Node

###############################################################################
#   Ejemplo de archivo launch para subscriptor y publicador.
#   Ejecuta dos nodos, un subscriber y un publisher.
###############################################################################
sub_node = Node(
    package="python_package",
    executable="sub",
    name="my_subscriber_node"
)

pub_node = Node(
    package="python_package",
    executable="pub",
    name="my_publisher_node"
)

rqt_node = Node(
    package="rqt_gui",
    executable="rqt_gui",
    name="rqt"
)

def generate_launch_description():
    return LaunchDescription([sub_node, pub_node, rqt_node])