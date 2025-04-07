from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, OpaqueFunction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory
from launch.substitutions import (
    PathJoinSubstitution,
)
import os

def launch_setup(context, *args, **kwargs):
    pkg = "my_launch"

    # 获取 launch 文件路径
    launch_file_path = PathJoinSubstitution([FindPackageShare("control_hardware"),
        "launch",
        "control_system.launch.py"
    ]),

    # 包含另一个 launch 文件
    hardware_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(launch_file_path)
    )

    return [hardware_launch]

def generate_launch_description():
    return LaunchDescription([
        OpaqueFunction(function=launch_setup)
    ])
