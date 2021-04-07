//
// Created by goktug on 6.04.2021.
//

#ifndef BUILD_POINTCLOUDNODE_H
#define BUILD_POINTCLOUDNODE_H

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <boost/smart_ptr.hpp>
#include <pcl/common/common.h>

#include <chrono>
#include <functional>
#include <memory>
#include <string>

class PointCloudNode : public rclcpp::Node
{
public:
    using Point = pcl::PointXYZI;
    using Cloud = pcl::PointCloud<pcl::PointXYZI>;

    explicit PointCloudNode();
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_point_cloud_;
    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr sub_point_cloud_;
    rclcpp::TimerBase::SharedPtr timer_pub_;
    size_t count_message;
    void CallbackTimer();

    std::function<void(std::shared_ptr<sensor_msgs::msg::PointCloud2>)> functionSub;
    void CallbackSubPointCloud(const sensor_msgs::msg::PointCloud2::SharedPtr msg_point_cloud);
};

#endif //BUILD_POINTCLOUDNODE_H
