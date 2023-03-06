#include <chrono>
#include <cstdlib>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "my_interface/srv/my_srv.hpp"

using namespace std::chrono_literals;

/******************************************************************************
 * @brief   Crea el nodo "my_client_node", que será un cliente del servicio
 *          "service_name", el cual está declarado dentro de este mismo
 *          paquete bajo el nombre "my_package/srv/my_srv".
 * 
 *  @arg    argc: "4" (tres elementos)
 * 
 *          a, b, c: tres enteros.
 * 
 *  @return "0" en éxito, otro valor en error
 ******************************************************************************/
int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    if (argc < 4) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "usage: add_three_ints_client X Y Z");
            return 1;
    }

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("my_client_node");

    rclcpp::Client<my_interface::srv::MySrv>::SharedPtr client =
        node->create_client<my_interface::srv::MySrv>("service_name");

    auto request = std::make_shared<my_interface::srv::MySrv::Request>();
    request->a = atoll(argv[1]);
    request->b = atoll(argv[2]);
    request->c = atoll(argv[3]);

    while (!client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
            return 0;
        }

        rclcpp::Client<my_interface::srv::MySrv>::SharedPtr client =
            node->create_client<my_interface::srv::MySrv>("service_name");

        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service not available, waiting again...");
    }

    auto result = client->async_send_request(request);
    // Wait for the result.
    if (rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sum: %ld", result.get()->sum);
    } 

    else {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service service_name");
    }

    rclcpp::shutdown();
    return 0;
}