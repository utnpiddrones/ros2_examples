#include <functional>
#include <memory>
#include <thread>

#include "my_interface/action/my_action.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"


class ActionServer : public rclcpp::Node
{
public:
    using fib_t = my_interface::action::Fibonacci;
    using fib_goal_handler_t = rclcpp_action::ServerGoalHandle<fib_t>;

    explicit ActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

private:
  rclcpp_action::Server<my_interface::action::MyAction>::SharedPtr action_server;

  rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const my_interface::action::MyAction::Goal> goal);

  rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleFibonacci> goal_handle);

  void handle_accepted(const std::shared_ptr<GoalHandleFibonacci> goal_handle);

  void execute(const std::shared_ptr<GoalHandleFibonacci> goal_handle);
  
};
