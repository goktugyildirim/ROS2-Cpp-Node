from launch import LaunchDescription
import launch_ros.actions

def generate_launch_description():
    return LaunchDescription([
        launch_ros.actions.Node(
            package='ros2_point_cloud_cpp',
            namespace='point_cloud',
            executable='point_cloud_node', 
            output='screen'),
    ])
