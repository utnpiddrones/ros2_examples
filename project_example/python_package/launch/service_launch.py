from launch import LaunchDescription
from launch_ros.actions import Node

###############################################################################
#   Ejemplo de launch para un servicio y varios clientes.
#   Ejecuta tres nodos, un servidor de servicios, y dos clientes.
###############################################################################
client1_node = Node(
    package="python_package",
    executable="client",
    name="client_node",
    arguments=[ "1", "2", "3"], # Argumentos del main
)

client2_node = Node(
    package="python_package",
    executable="client",
    name="client_node2",
    arguments=["4", "5", "6"],
)

service_node = Node(
    package="python_package",
    executable="service",
    name="service_node",
)

def generate_launch_description():
    return LaunchDescription([client1_node, client2_node, service_node])