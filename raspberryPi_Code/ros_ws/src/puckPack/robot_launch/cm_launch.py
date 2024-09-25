from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='puckPack',
            executable='controlPC',
        ),
        Node(
            package='puckPack',
            executable='UartCommander',
        ),

        Node(
            package='puckPack',
            executable='mainCamera',
        ),
        Node(
            package='puckPack',
            executable='rpiCamera',
        ),
    ])
