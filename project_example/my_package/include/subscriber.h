#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class Subscriber : public rclcpp::Node
{
private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub;

    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const;


public:
    Subscriber();
};
