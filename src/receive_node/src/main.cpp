#include "rclcpp/rclcpp.hpp"
#include "receive_node.hpp"

int main(int argc, char * argv[])
{
rclcpp::init(argc, argv);
rclcpp::spin(std::make_shared<receive_node>());
rclcpp::shutdown();
return 0;
}