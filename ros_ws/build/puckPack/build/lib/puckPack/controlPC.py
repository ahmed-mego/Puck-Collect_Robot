import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from ctrl_interface.msg import CtrlInterface
from time import sleep
from pynput import keyboard


the_pressedkey = 'x'

def on_press(key):
    global the_pressedkey
    try:
        k = key.char
    except AttributeError:
        k = key
    the_pressedkey =k
class controlPcPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(CtrlInterface, 'ctrltopic', 10)
    def publish(self,msg):
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg)
def main(args=None):
    rclpy.init(args=args)
    global the_pressedkey
    controlPc = controlPcPublisher()
    motor_speed_high = 0
    motor_speed_low = 65535
    motor_speed_half = 65535
    
    msg = CtrlInterface()
    msg.r_motor = motor_speed_low
    msg.l_motor = motor_speed_low
    msg.g_stepper = 0
    msg.s_stepper = 0    
    controlPc.publish(msg)  
    
    keyboard_Listener = keyboard.Listener(on_press=on_press)
    keyboard_Listener.start()
    
    while rclpy.ok():
        if the_pressedkey == "w":
            msg.r_motor = motor_speed_half
            msg.l_motor = motor_speed_half
            controlPc.publish(msg)
            sleep(0.1)
            msg.r_motor = motor_speed_low
            msg.l_motor = motor_speed_low
            controlPc.publish(msg)
            the_pressedkey == "x"
        if the_pressedkey == "s":
            msg.r_motor = motor_speed_half*-1
            msg.l_motor = motor_speed_half*-1
            controlPc.publish(msg)
            sleep(0.1)
            msg.r_motor = motor_speed_low
            msg.l_motor = motor_speed_low
            controlPc.publish(msg)
            the_pressedkey == "x"
        if the_pressedkey == "a":
            msg.r_motor = motor_speed_half*1
            msg.l_motor = motor_speed_half*-1
            controlPc.publish(msg)
            sleep(0.1)
            msg.r_motor = motor_speed_low
            msg.l_motor = motor_speed_low
            the_pressedkey == "x"
        if the_pressedkey == "d":
            msg.r_motor = motor_speed_half*-1
            msg.l_motor = motor_speed_half*1
            controlPc.publish(msg)
            sleep(0.1)
            msg.r_motor = motor_speed_low
            msg.l_motor = motor_speed_low
            the_pressedkey == "x"
        if the_pressedkey == "m":
            msg.g_stepper = (msg.g_stepper+1) % 2 
            controlPc.publish(msg)
            sleep(1)
            the_pressedkey == "x"
        if the_pressedkey == "n":
            msg.s_stepper = (msg.s_stepper+1) % 3
            controlPc.publish(msg)
            sleep(1)
            the_pressedkey == "x"
            controlPc.publish(msg)
            # Destroy the node explicitly
    # when the garbage collector destroys the node object)
    controlPcPublisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
