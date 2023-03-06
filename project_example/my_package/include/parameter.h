#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include <string>
#include <functional>

using namespace std::chrono_literals;

class ParametersClass: public rclcpp::Node {
private:
    std::string parameter_string;
    rclcpp::TimerBase::SharedPtr timer;
public:
    ParametersClass();
    void respond();
};
