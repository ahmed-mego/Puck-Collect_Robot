from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='puckPack',
            executable='thinker',
        ),
        Node(
            package='puckPack',
            executable='UartCommander',
        ),
        Node(
            package='puckPack',
            executable='rpiCamera',
        ),

        Node(
            package='puckPack',
            executable='mainCamera',
        ),

        Node(
            package='puckPack',
            executable='choose_color',
        ),
    ])
