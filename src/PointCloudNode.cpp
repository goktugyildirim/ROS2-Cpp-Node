//
// Created by goktug on 6.04.2021.
//

#include "PointCloudNode.h"

using namespace std::chrono_literals;

PointCloudNode::PointCloudNode()
:Node("point_cloud_node"),
count_message(0)
{
    functionSub = std::bind(&PointCloudNode::CallbackSubPointCloud, this, std::placeholders::_1);
    sub_point_cloud_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
            "/point_cloud", 10, functionSub);

    pub_point_cloud_ = create_publisher<sensor_msgs::msg::PointCloud2>("/point_cloud", 10);

    timer_pub_ = create_wall_timer(500ms, std::bind(&PointCloudNode::CallbackTimer, this));
}

void
PointCloudNode::CallbackTimer() {
    Cloud::Ptr cloud(new Cloud);
    for(int i=0; i<1000; i++)
    {
        Point p;
        p.x = 1+i;
        p.y = 0;
        p.z = 1;
        cloud->points.push_back(p);
    }

    sensor_msgs::msg::PointCloud2 msg;
    boost::shared_ptr<sensor_msgs::msg::PointCloud2> msg_ptr =
            boost::make_shared<sensor_msgs::msg::PointCloud2>(msg);
    pcl::toROSMsg(*cloud, *msg_ptr);
    msg_ptr->header.frame_id = "velodyne";
    msg_ptr->header.stamp = now();
    msg_ptr->width = cloud->size();
    pub_point_cloud_->publish(*msg_ptr);
    std::cout << "Message is published: " << std::endl;
}

void PointCloudNode::CallbackSubPointCloud
(const sensor_msgs::msg::PointCloud2::SharedPtr msg_point_cloud) {
    Cloud::Ptr cloud(new Cloud);
    pcl::fromROSMsg(*msg_point_cloud,*cloud);
    std::cout << "Point cloud message is received." << std::endl;
}
