#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class receive_node : public rclcpp::Node
{
public:
receive_node();
private:
// the function called everytime we receive a message from the topic:
void topic_callback(const std_msgs::msg::String::SharedPtr msg) const;

// the subscription:
rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};
