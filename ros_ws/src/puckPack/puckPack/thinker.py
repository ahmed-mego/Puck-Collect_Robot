import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from ctrl_interface.msg import CtrlInterface
from time import sleep

motor_speed_high = 0
motor_speed_low = 65535
motor_speed_half = 32767

class motorControl:
    def __init__(self) -> None:
        self.r_motor = motor_speed_low
        self.l_motor = motor_speed_low
        self.g_motor = 0
        self.s_motor = 0

    def mv_forward(controlPublisher):
        msg = CtrlInterface()
        msg.r_motor = motor_speed_half
        msg.l_motor = motor_speed_half
        controlPublisher.publish(msg)
        sleep(0.3)
        msg.r_motor = motor_speed_low
        msg.l_motor = motor_speed_low
        controlPublisher.publish(msg)

    def mv_backward(controlPublisher):
        msg = CtrlInterface()
        msg.r_motor = motor_speed_half * -1
        msg.l_motor = motor_speed_half * -1
        controlPublisher.publish(msg)
        sleep(0.3)
        msg.r_motor = motor_speed_low
        msg.l_motor = motor_speed_low
        controlPublisher.publish(msg)
    
    def rt_clockWise(controlPublisher):
        msg = CtrlInterface()
        msg.r_motor = motor_speed_half
        msg.l_motor = motor_speed_half * -1
        controlPcPublisher.publish(msg)
        sleep(0.3)
        msg.r_motor = motor_speed_low
        msg.l_motor = motor_speed_low
            
    def rt_counter_clockWise(controlPublisher):
        msg = CtrlInterface()
        msg.r_motor = motor_speed_half*-1
        msg.l_motor = motor_speed_half
        controlPcPublisher.publish(msg)
        sleep(0.3)
        msg.r_motor = motor_speed_low
        msg.l_motor = motor_speed_low
        controlPcPublisher.publish(msg)
        
class controlPcPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(CtrlInterface, 'ctrltopic', 10)
    def publish(self,msg):
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    global the_pressedkey
    controlPc = controlPcPublisher()


    msg = CtrlInterface()
    msg.r_motor = motor_speed_low
    msg.l_motor = motor_speed_low
    msg.g_stepper = 0
    msg.s_stepper = 0
    controlPc.publish(msg)



    while rclpy.ok():
        if the_pressedkey == "w":
            the_pressedkey = "x"
            msg.r_motor = motor_speed_half
            msg.l_motor = motor_speed_half
            controlPc.publish(msg)
            sleep(0.3)
            msg.r_motor = motor_speed_low
            msg.l_motor = motor_speed_low
            controlPc.publish(msg)

        elif the_pressedkey == "s":
            the_pressedkey = "x"
            msg.r_motor = motor_speed_half*-1
            msg.l_motor = motor_speed_half*-1
            controlPc.publish(msg)
            sleep(0.3)
            msg.r_motor = motor_speed_low
            msg.l_motor = motor_speed_low
            controlPc.publish(msg)
            
        elif the_pressedkey == "a":
            the_pressedkey = "x"
            msg.r_motor = motor_speed_half
            msg.l_motor = motor_speed_half*-1
            controlPc.publish(msg)
            sleep(0.3)
            msg.r_motor = motor_speed_low
            msg.l_motor = motor_speed_low
            controlPc.publish(msg)
        elif the_pressedkey == "d":
            the_pressedkey = "x"
            msg.r_motor = motor_speed_half*-1
            msg.l_motor = motor_speed_half
            controlPc.publish(msg)
            sleep(0.3)
            msg.r_motor = motor_speed_low
            msg.l_motor = motor_speed_low
            controlPc.publish(msg)
            
        elif the_pressedkey == "m":
            the_pressedkey = "x"
            msg.g_stepper = (msg.g_stepper+1) % 2 
            controlPc.publish(msg)
            sleep(1)
            
        elif the_pressedkey == "n":
            the_pressedkey = "x"
            msg.s_stepper = (msg.s_stepper+1) % 3
            controlPc.publish(msg)
            sleep(1)
            
            controlPc.publish(msg)

            # Destroy the node explicitly
    # when the garbage collector destroys the node object)
    controlPcPublisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
