#include <memory>
#include <chrono>
#include <string>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class Publisher: public rclcpp::Node
{
private:  
    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub;
    int msg_published;

    void timer_callback();

public:
    Publisher();

};