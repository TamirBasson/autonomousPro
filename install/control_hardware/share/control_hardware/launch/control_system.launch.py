import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import Command, LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():

    # Teleop Joy Node
    teleop_joy_node = Node(
        package="control_hardware",  # Replace with your package name
        executable="joy_control_node",  # Replace with your executable name
        name="joy_control_node",
        output="screen",
        parameters=[{"use_sim_time": False}]
    )

    # CmdVel to PWM Node
    cmd_vel_to_gpio_node = Node(
        package="control_hardware",
        executable="cmd2gpio",
        name="cmd2gpio_node",
        output="screen",
        parameters=[{"use_sim_time": False}]
    )

    # Return the LaunchDescription with all nodes and arguments
    return LaunchDescription([
        teleop_joy_node,
        cmd_vel_to_gpio_node,
    ])
