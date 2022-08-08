#include "subscriber.h"

/******************************************************************************
 * @brief   Constructor del nodo "my_subscriber". Recibe los mensajes del
 *          publisher, subscribe al tópico "topic".
 * 
 *  @arg    Void.
 * 
 *  @return None
 ******************************************************************************/
Subscriber::Subscriber() : Node("my_subscriber")
{
    this->sub = this->create_subscription<std_msgs::msg::String>("topic", 10, std::bind(&Subscriber::topic_callback, this, _1));
}

/******************************************************************************
 * @brief   Función a ser llamada al recibir un mensaje por el tópico "topic".
 *          Imprime la información recibida por pantalla.
 * 
 *  @arg    msg: el mensaje recibido, normalmente msg->data es un std::string.
 * 
 *  @return None
 ******************************************************************************/
void Subscriber::topic_callback(const std_msgs::msg::String::SharedPtr msg) const
{
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
}

/******************************************************************************
 * @brief   Ejecución del nodo. La llamada a "init" incializa ROS2, "spin" deja
 *          corriendo en un bucle infinito el nodo Subscriber.
 * 
 *  @arg    Void.
 * 
 *  @return None
 ******************************************************************************/
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Subscriber>());
  rclcpp::shutdown();
  return 0;
}