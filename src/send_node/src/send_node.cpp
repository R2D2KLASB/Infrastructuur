#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "send_node.hpp"

send_node::send_node():
	Node("sendNode"), cound_(0){
	publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
	
	timer_ = this->create_wall_timer(std::chrono::milliseconds(500), 				std::bind(&Publisher_node::timer_callback, this));
	}
	
void send_node::timer_callback(){
	auto message = std_msgs::msg::String();
	
	count++;
	message.data = "Test " + std::to_string(count_);
	
	publisher_->publish(message);
}
