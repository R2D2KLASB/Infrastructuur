#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "send_node.hpp"

send_node::send_node():
	Node("sendNode"), cound_(0) {
	publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
	timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&Publisher_node::timer_callback, this));
	}

void send_node::timer_callback() {
    std::string txt = nodeFromTxtFile();
    if (txt.size() > 10) {
        auto message = std_msgs::msg::String();
        message.data = txt; // met tijd en andere info
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        publisher_->publish(message);
        txt = "";
    }

std::string send_node::nodeFromTxtFile() {
    std::string s = "";
    std::ifstream file("gcode.txt");

    if (file.good()) {
        std::string tmp = "";
        while (std::getline(file, tmp)) {
            s += tmp;
        }
    }
    file.close();
    remove("gcode.txt");

    return s;
}
