#include <string>
#include <vector>

class AskRobotListNode : public rclcpp::Node
{
public:
    AskRobotListNode() : Node("AskForRobotList")
    {
        subscription_ = this->create_subscription<std_msgs::msg::String>("AskRobotListNode", 10, 
            std::bind(&AskRobotListNode::SendRobotList, this, _1));
        publisher_ = this->create_publisher<std_msgs::msg::String>("AvailableRobots", 10);
    }

private:
    //vector<int> * OnlineRobots = 0;

    //SendRobotListNode * sender;
    
    //Send a list of all affailable robots
    void SendRobotList(const std_msgs::msg::String::SharedPtr msg) const
    {
        //Senders krijgen geen id, robots wel

        // ping alle robots via ping node en maak een vector<int>

        //Send via send node "OnlineRobots"

        RCLCPP_INFO(this->get_logger(), "Request for robot list Received!, Sending...", );
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

//class SendRobotListNode : public rclcpp::Node{
//public:
//    SendRobotListNode()
//        : Node("topic"), count_(0)
//    {
//        publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
//        //timer_ = this->create_wall_timer(500ms, std::bind(&SendRobotListNode::timer_callback, this));
//    }
//    void sendRobotList(vector<int>* robotList) {
//        send(vector<int> * robotList);
//    }
//private:
//    void send(vector<int> * robotList) {
//            auto message = std_msgs::msg::String();
//            string robots = "";
//            for (int robot : *robotList) {
//                robots += robot + ", ";
//            }
//            robots -= ", ";
//            message.data = RobotList;
//            RCLCPP_INFO(this->get_logger(), "Robot list send!");
//            publisher_->publish(message);
//    }
//    rclcpp::TimerBase::SharedPtr timer_;
//    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
//    size_t count_;
//};
