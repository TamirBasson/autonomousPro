from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # path
    mpu9250_launch = os.path.join(
        get_package_share_directory('robot_mpu9250driver'), 'launch', 'mpu9250driver_launch.py')

    lslidar_launch = os.path.join(
        get_package_share_directory('lslidar_driver'), 'launch', 'lslidar_cx_launch.py')

    control_launch = os.path.join(
        get_package_share_directory('robot_control_hardware'), 'launch', 'control_system.launch.py')

    return LaunchDescription([
        # Step 1: start MPU9250
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(mpu9250_launch)
        ),

        # Step 2: logging 3s ， start LSLiDAR
        TimerAction(
            period=3.0,
            actions=[
                IncludeLaunchDescription(
                    PythonLaunchDescriptionSource(lslidar_launch)
                )
            ]
        ),

        # Step 3: logging another 3s，start control hardware
        TimerAction(
            period=6.0,  
            actions=[
                IncludeLaunchDescription(
                    PythonLaunchDescriptionSource(control_launch)
                )
            ]
        ),
    ])
