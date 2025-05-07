from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='robot_control_hardware',
            executable='robot_control_hardware_node',
            name='robot_control_hardware',
            output='screen'
        ),
    ]) 