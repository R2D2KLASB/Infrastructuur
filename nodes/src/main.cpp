#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <fstream>
#include <array>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include "Robotlistnode.h"

using namespace std::chrono_literals;

// Iedere robot moet een id hebben, hiervoor is een node nodig die wacht op topic: Robot_Start
// deze node geeft de robot een nieuwe ID en registreert deze bij de ping node
// 
// pingen
// topic: Robot_Ping
// iedere online robot reageert met:
// [robotID] : [1]=beschikbaar [0]=niet beschikbaar
// Als een robot ID x keer niet reageert, word de robot verwijdert en wordt dit doorgegeven aan de Robot_Start node.

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AskRobotListNode>());
  rclcpp::shutdown();
  return 0;
}

