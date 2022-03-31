#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class receive_node : public rclcpp::Node {
private:
	void topic_callback(const std_msgs::msg::String::sharedPtr msg) const;
	
	rclcpp::Subscription>std_msgs::msg::String>::SharedPtr subscription_;
	
public:
	receive_node();

};
