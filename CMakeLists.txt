cmake_minimum_required(VERSION 3.5)
project(ros2_point_cloud_cpp)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

set(PCL_DIR "/home/goktug/libraries/libpcl-1.11.1/share/pcl-1.11/")
find_package(PCL 1.11.1 REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

add_definitions(${PCL_DEFINITIONS})

add_executable(point_cloud_node 
        src/main.cpp
        src/PointCloudNode.cpp)

include_directories(
        include
        ${PCL_INCLUDE_DIRS}
)

ament_target_dependencies(point_cloud_node
        rclcpp
        std_msgs
        sensor_msgs
        )

target_link_libraries(point_cloud_node
        ${PCL_LIBRARIES}
        ${Boost_SYSTEM_LIBRARY}
)

target_include_directories(point_cloud_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
       )


install(TARGETS point_cloud_node
  DESTINATION lib/${PROJECT_NAME})
  
# install the launch directory
install(DIRECTORY
        launch
        DESTINATION share/${PROJECT_NAME}/
        )



ament_package()
