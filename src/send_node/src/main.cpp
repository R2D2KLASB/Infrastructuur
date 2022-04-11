#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <fstream>
#include <array>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

std::string gcodeToString() {
    std::string s = "";
    std::ifstream file("gcodeSend.txt");

    if (file.good()) {
        std::string tmp = "";
        while (std::getline(file, tmp)) {
            s += tmp + '\n';
        }
    }
    file.close();
    remove("gcodeSend.txt");

    return s;
}

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class send_nodes : public rclcpp::Node
{
  public:
    send_nodes()
    : Node("topic"), count_(0)
    {
      publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
      timer_ = this->create_wall_timer(500ms, std::bind(&send_nodes::timer_callback, this));
    }
  private:
      void timer_callback() {
          std::string txt = gcodeToString();
          if (txt.size() > 10) {
              auto message = std_msgs::msg::String();
              message.data = txt; // met tijd en andere info
              RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
              publisher_->publish(message);
              txt = "";
          }
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<send_nodes>());
  rclcpp::shutdown();
  return 0;
}