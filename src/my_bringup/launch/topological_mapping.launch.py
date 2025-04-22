from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
import os

def generate_launch_description():
    # Get the package directory
    package_dir = os.path.dirname(os.path.dirname(os.path.dirname(__file__)))
    
    # Create the launch description
    ld = LaunchDescription()
    
    # Pose logger node
    pose_logger = Node(
        package='my_bringup',
        executable='image_pose_logger',
        name='pose_logger',
        output='screen',
        parameters=[{
            'min_distance': 1.0,  # meters
            'image_folder': os.path.join(package_dir, 'image_data'),
            'csv_file': os.path.join(package_dir, 'poses.csv')
        }]
    )
    
    # Topological map visualizer node
    map_visualizer = Node(
        package='my_bringup',
        executable='live_pose_plotter',
        name='topological_map',
        output='screen',
        parameters=[{
            'region_threshold': 1.0,  # meters
            'connection_threshold': 0.3,  # meters
            'update_rate': 200  # milliseconds
        }]
    )
    
    # Add nodes to launch description
    ld.add_action(pose_logger)
    ld.add_action(map_visualizer)
    
    return ld 