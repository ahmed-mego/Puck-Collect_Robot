import rclpy
from rclpy.node import Node
from std_msgs.msg import Int8
from ctrl_interface.msg import CtrlInterface
from time import sleep
import random

motor_speed_high = 0
motor_speed_low = 65535
motor_speed_half = 32767

Ctrlmsg = CtrlInterface()
puckseen = 0 # var for puck with the main cam
puckundersorter = 2
sortercamready = 0
base = 0
puck_collected_count = 0 # var for puck with the main cam
collect_color = 'red' 
round_timout = 0


class motorControl:
    def __init__(self) :
        global Ctrlmsg
        self.r_motor = motor_speed_low
        self.l_motor = motor_speed_low
        self.g_motor = 0
        self.s_motor = 0

    def mv_forward(self,controlPublisher):
        global Ctrlmsg
        Ctrlmsg.r_motor = motor_speed_half
        Ctrlmsg.l_motor = motor_speed_half
        controlPublisher.publish(Ctrlmsg)
        sleep(0.3)
        Ctrlmsg.r_motor = motor_speed_low
        Ctrlmsg.l_motor = motor_speed_low
        controlPublisher.publish(Ctrlmsg)

    def mv_backward(self,controlPublisher):
        global Ctrlmsg
        Ctrlmsg.r_motor = motor_speed_half * -1
        Ctrlmsg.l_motor = motor_speed_half * -1
        controlPublisher.publish(Ctrlmsg)
        sleep(0.3)
        Ctrlmsg.r_motor = motor_speed_low
        Ctrlmsg.l_motor = motor_speed_low
        controlPublisher.publish(Ctrlmsg)
    
    def stop (self, controlPublisher):
        global Ctrlmsg
        Ctrlmsg.r_motor = motor_speed_low
        Ctrlmsg.l_motor = motor_speed_low
        controlPublisher.publish(Ctrlmsg)
    
    def rt_clockWise(self,controlPublisher):
        global Ctrlmsg
        Ctrlmsg.r_motor = motor_speed_half
        Ctrlmsg.l_motor = motor_speed_half * -1
        controlPublisher.publish(Ctrlmsg)
        sleep(0.3)
        Ctrlmsg.r_motor = motor_speed_low
        Ctrlmsg.l_motor = motor_speed_low
            
    def rt_counter_clockWise(self,controlPublisher):
        global Ctrlmsg
        Ctrlmsg.r_motor = motor_speed_half*-1
        Ctrlmsg.l_motor = motor_speed_half
        controlPublisher.publish(Ctrlmsg)
        sleep(0.3)
        Ctrlmsg.r_motor = motor_speed_low
        Ctrlmsg.l_motor = motor_speed_low
        controlPublisher.publish(Ctrlmsg)
        
    def open_gate(self,controlPublisher):
        global Ctrlmsg
        Ctrlmsg.g_stepper = 1
        controlPublisher.publish(Ctrlmsg)
        sleep(1)
    def close_gate(self,controlPublisher):
        global Ctrlmsg
        Ctrlmsg.g_stepper = 0
        controlPublisher.publish(Ctrlmsg)
        sleep(1)
    def default_sortplace(self,controlPublisher):
        global Ctrlmsg
        Ctrlmsg.s_stepper = 0
        controlPublisher.publish(Ctrlmsg)
        sleep(1)     
    def collect_sortplace(self,controlPublisher):
        global Ctrlmsg
        Ctrlmsg.s_stepper = 1
        controlPublisher.publish(Ctrlmsg)
        sleep(1)     
    def reject_sortplace(self,controlPublisher):
        global Ctrlmsg
        Ctrlmsg.s_stepper = 2
        controlPublisher.publish(Ctrlmsg)
        sleep(1)        

control_motors_obj = motorControl()

class thinker(Node):
    def __init__(self):
        super().__init__('think')
        self.publisher_ = self.create_publisher(CtrlInterface, 'ctrltopic', 10)
        self.subscription_rpicam = self.create_subscription(
            Int8,
            'rpi_cam',
            self.rpicam_callback,
            1)
        self.subscription_rpicam  # prevent unused variable warning
        
        self.subscription_maincam = self.create_subscription(
            Int8,
            'main_cam',
            self.maincam_callback,
            1)
        self.subscription_maincam  # prevent unused variable warning

        self.subscription_chooseColor = self.create_subscription(
            Int8,
            'main_color',
            self.chooseColor_callback,
            10)

        self.create_timer(50, self.timer_callback)
        

    def timer_callback(self):
        global round_timout 
        round_timout = 1
    def maincam_callback(self, msg):
        global puckseen
        puckseen = msg.data
    def rpicam_callback(self, msg):
        global puckundersorter 
        global sortercamready
        puckundersorter = msg.data
        sortercamready = 1
 
    def chooseColor_callback(self, msg):
        global collect_color
        if msg.data == 0:
            collect_color = 'red'
        else :
            collect_color = 'blue'
    
    def publish(self,msg):
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg)
        
        

def main(args=None):

    global round_timout 
    global puck_collected_count
    global puckseen
    global sortercamready
    global puckundersorter 

    rclpy.init(args=args)
    thinker_obj = thinker()
    Ctrlmsg.r_motor = motor_speed_low
    Ctrlmsg.l_motor = motor_speed_low
    Ctrlmsg.g_stepper = 0
    Ctrlmsg.s_stepper = 0
    thinker_obj.publish(Ctrlmsg)
    sleep(5)
    for i in range(5):
        control_motors_obj.mv_forward(thinker_obj)   
    #t1 = thinker_obj.get_clock().now()
    while rclpy.ok():        
        rclpy.spin_once(thinker_obj,0)
        if(puckundersorter != 2):
            current_color = 'red'
            if(puckundersorter == 0):
                current_color = 'red'
            if(puckundersorter == 1):
                current_color = 'blue'
                
            if (current_color == collect_color): 
                control_motors_obj.collect_sortplace(thinker_obj)
                control_motors_obj.mv_forward(thinker_obj)
                control_motors_obj.default_sortplace(thinker_obj)  
                sortercamready = 0
                while sortercamready == 0:
                    rclpy.spin_once(thinker_obj,0)
                if(puckundersorter == 2):
                    puck_collected_count+=1
                elif puckundersorter == 0 and current_color == 'red':
                    base = 1
                elif puckundersorter == 1 and current_color == 'blue':
                    base = 1
            else: # not my color opeset color 
                control_motors_obj.reject_sortplace(thinker_obj)
                control_motors_obj.mv_forward(thinker_obj)
                control_motors_obj.default_sortplace(thinker_obj)
                sortercamready = 0
                while sortercamready == 0:
                    rclpy.spin_once(thinker_obj,0)

                if puckundersorter == 0 and current_color == 'red':
                    base = 2
                elif puckundersorter == 1 and current_color == 'blue':
                    base = 2
            current_color = ''

        else:
            base = 0
        if base == 1:
            for i in range(5):
                control_motors_obj.rt_clockWise(thinker_obj)
            control_motors_obj.open_gate(thinker_obj)
            for i in range(5):
                control_motors_obj.mv_forward(thinker_obj)
            control_motors_obj.close_gate(thinker_obj)   
            base = 0
        if base == 2:
            for i in range(5):
                control_motors_obj.rt_counter_clockWise(thinker_obj)

            for i in range(5):
                control_motors_obj.mv_forward(thinker_obj)

            base = 0
        

        if(round_timout == 1) :# time to get back
            self.get_logger().info('Publishing: time out')
            for i in range(10):
                control_motors_obj.rt_counter_clockWise(thinker_obj)
            for i in range(20):
                control_motors_obj.mv_forward(thinker_obj)
            for i in range(10):
                control_motors_obj.rt_counter_clockWise(thinker_obj)
            for i in range(20):
                control_motors_obj.mv_forward(thinker_obj)

            for i in range(10):
                control_motors_obj.rt_counter_clockWise(thinker_obj)
            for i in range(20):
                control_motors_obj.mv_forward(thinker_obj)
            for i in range(10):
                control_motors_obj.rt_counter_clockWise(thinker_obj)
            for i in range(20):
                control_motors_obj.mv_forward(thinker_obj)
            round_timout = 0 


        if(puck_collected_count>=10): # we collected all of our pucks 
            self.get_logger().info('Publishing: all puck colected')
            for i in range(10):
                control_motors_obj.rt_counter_clockWise(thinker_obj)
            for i in range(20):
                control_motors_obj.mv_forward(thinker_obj)
            for i in range(10):
                control_motors_obj.rt_counter_clockWise(thinker_obj)
            for i in range(20):
                control_motors_obj.mv_forward(thinker_obj)

            for i in range(10):
                control_motors_obj.rt_counter_clockWise(thinker_obj)
            for i in range(20):
                control_motors_obj.mv_forward(thinker_obj)
            for i in range(10):
                control_motors_obj.rt_counter_clockWise(thinker_obj)
            for i in range(20):
                control_motors_obj.mv_forward(thinker_obj)

        if(puckseen == 1): 
            for i in range(20):
                control_motors_obj.mv_forward(thinker_obj)

        else :
            for i in range(10):
                control_motors_obj.rt_counter_clockWise(thinker_obj)
            
        #defult navagate 
           
            # Destroy the node explicitly
    # when the garbage collector destroys the node object)
    thinker_obj.destroy_node()
    rclpy.shutdown()
if __name__ == '__main__':
    main()

"""

        global control_motors_obj
        global collect_color
        global puck_collected_count


"""