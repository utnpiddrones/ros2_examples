#include "publisher.h"

/******************************************************************************
 * @brief   Constructor del nodo "my_publisher". Publicará un mensaje en el 
 *          tópico "topic" cada 500ms.
 * 
 *  @arg    Void.
 * 
 *  @return None
 ******************************************************************************/
Publisher::Publisher(): Node("my_publisher"), msg_published(0) {
    this->pub = this->create_publisher<std_msgs::msg::String>("topic", 10);

    this->timer = this->create_wall_timer(
        500ms, std::bind(&Publisher::timer_callback, this)
    );
}

/******************************************************************************
 *  @brief  Publica una string de la forma: "Hello, world! <index>" cada 500ms
 *          en el tópico "topic".
 * 
 *  @arg    Void.
 * 
 *  @return None.
 *****************************************************************************/
void Publisher::timer_callback() {
    std_msgs::msg::String msg;
    msg.data = "Hello, world! " + std::to_string(this->msg_published++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());

    this->pub->publish(msg);
}

/******************************************************************************
 *  @brief  Ejecución del nodo. La llamada a "init" incializa ROS2, "spin" deja
 *          corriendo en un bucle infinito el nodo Publisher.
 * 
 *  @arg    Void.
 * 
 *  @return "0" en éxito, otro valor en error.
 *****************************************************************************/
int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Publisher>());
    rclcpp::shutdown();
    return 0;
}