using namespace std::chrono_literals;
#include <string>

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class send_nodes : public rclcpp::Node {
public:
    send_node();
private:
    void timer_callback();
    std::string nodeFromTxtFile();

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
};