#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "my_interface/srv/my_srv.hpp"

/******************************************************************************
 *  @brief  Servicio que recibe 3 enteros y devuelve la suma.
 * 
 *  @arg    - request: Contiene los elementos de la solicitud (a, b, c).
 * 
 *          - response: Contiene el contenido que debe devolverse (sum).
 * 
 *  @return Void.
 ******************************************************************************/
void add(
    const std::shared_ptr<my_interface::srv::MySrv::Request> request,
    std::shared_ptr<my_interface::srv::MySrv::Response> response
    ) {

    response->sum = request->a + request->b + request->c;
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld" " c: %ld",
                    request->a, request->b, request->c);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending back response: [%ld]", (long int)response->sum);
}

/******************************************************************************
 *  @brief  Crea un nodo de nombre "my_service node" y un servicio llamado
 *          "service_name" que recibe de argumento 3 enteros y devuelve la suma.
 * 
 *  @arg    Void.
 * 
 *  @return None
 ******************************************************************************/
int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("my_service_node");

    rclcpp::Service<my_interface::srv::MySrv>::SharedPtr service =
        node->create_service<my_interface::srv::MySrv>("service_name", &add);

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service online.");

    rclcpp::spin(node);
    rclcpp::shutdown();
}