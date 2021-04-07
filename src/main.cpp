#include <cstdio>
#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "PointCloudNode.h"

using namespace std::chrono_literals;

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PointCloudNode>());
    rclcpp::shutdown();
  return 0;
}
