#include "parameter.h"

ParametersClass::ParametersClass(): Node("parameter_node")
{
    this->declare_parameter<std::string>("my_parameter", "world");
    this->timer = this->create_wall_timer(
        1000ms, std::bind(&ParametersClass::respond, this));
}

void ParametersClass::respond()
{
    this->get_parameter("my_parameter", this->parameter_string);
    RCLCPP_INFO(this->get_logger(), "Hello %s", this->parameter_string.c_str());
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ParametersClass>());
    rclcpp::shutdown();
    return 0;
}