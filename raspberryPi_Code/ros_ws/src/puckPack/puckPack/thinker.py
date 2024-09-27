import rclpy
from rclpy.node import Node
from std_msgs.msg import Int8
from ctrl_interface.msg import CtrlInterface
from time import sleep
import random

motor_speed_low = 65534
motor_speed_half = 32767
motor_speed_high = 0

Ctrlmsg = CtrlInterface()
puckseen = 0 # var for puck with the main cam
baseseen = 0 # var for my base with the main cam
maincamready = 0
puckundersorter = 3
sortercamready = 0
puck_collected_count = 0 
collect_color = 'red' 
round_timout = 0
start_op = 0


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
        sleep(0.2)
        Ctrlmsg.r_motor = motor_speed_low
        Ctrlmsg.l_motor = motor_speed_low
        controlPublisher.publish(Ctrlmsg)

    def mv_backward(self,controlPublisher):
        global Ctrlmsg
        Ctrlmsg.r_motor = motor_speed_half * -1
        Ctrlmsg.l_motor = motor_speed_half * -1
        controlPublisher.publish(Ctrlmsg)
        sleep(0.2)
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
        Ctrlmsg.r_motor = 21845
        Ctrlmsg.l_motor = 21845 * -1
        controlPublisher.publish(Ctrlmsg)
        sleep(0.3)
        Ctrlmsg.r_motor = motor_speed_low
        Ctrlmsg.l_motor = motor_speed_low
        controlPublisher.publish(Ctrlmsg)

    def rt_counter_clockWise(self,controlPublisher):
        global Ctrlmsg
        Ctrlmsg.r_motor = 21845*-1
        Ctrlmsg.l_motor = 21845
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

    def StepLeft(self,controlPUblisher):
        global Ctrlmsg
        Ctrlmsg.s_stepper = 3
        controlPUblisher.publish(Ctrlmsg)
    
    def StepRight(self,controlPUblisher):
        global Ctrlmsg
        Ctrlmsg.s_stepper = 4
        controlPUblisher.publish(Ctrlmsg)
    def StopStep(self,controlPUblisher):
        global Ctrlmsg
        Ctrlmsg.s_stepper = 100

    def Step_180(self,controlPUblisher):
        global Ctrlmsg
        Ctrlmsg.s_stepper = 5
        controlPUblisher.publish(Ctrlmsg)
        Ctrlmsg.s_stepper = 0
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
            10)
        self.subscription_maincam = self.create_subscription(
            Int8,
            'main_cam',
            self.maincam_callback,
            10)
        self.subscription_chooseColor = self.create_subscription(
            Int8,
            'main_color',
            self.chooseColor_callback,
            10)
        
    def start_timer(self):
        self.create_timer(50, self.timer_callback)
        
    def timer_callback(self):
        global round_timout 
        round_timout = 1

    def maincam_callback(self, msg):
        global puckseen
        global baseseen
        global collect_color
        global maincamready
        #puckseen = msg.data 
        if((int(msg.data) >> 0) & 1 == 1):
            if collect_color == 'red':
                puckseen = 1
            else:
                puckseen = 0
        elif((int(msg.data) >> 1) & 1 == 1):
            if collect_color == 'blue':
                puckseen = 1
            else:
                puckseen = 0
        if((int(msg.data) >> 2) & 1 == 1):
            if collect_color == 'red':
                baseseen = 1
            else:
                baseseen = 0
        elif((int(msg.data) >> 3) & 1 == 1):
            if collect_color == 'blue':
                baseseen = 1
            else:
                baseseen = 0
        maincamready = 1
        #self.get_logger().info('Publishing: %d %d' % (puckseen,baseseen))
        

    def rpicam_callback(self, msg):
        global puckundersorter 
        global sortercamready
        puckundersorter = msg.data
        sortercamready = 1
 
    def chooseColor_callback(self, msg):
        global collect_color
        global start_op
        if msg.data == 0:
            collect_color = 'red'
        elif msg.data == 1:
            collect_color = 'blue'
        else:
            start_op = 1

    
    def publish(self,msg):
        self.publisher_.publish(msg)
        #self.get_logger().info('Publishing: "%s"' % msg)
        
        
def main(args=None):

    global round_timout 
    global puck_collected_count
    global puckseen
    global baseseen
    global maincamready
    global sortercamready
    global puckundersorter 
    global start_op
    global Ctrlmsg

    rclpy.init(args=args)
    thinker_obj = thinker()
    Ctrlmsg.r_motor = motor_speed_low
    Ctrlmsg.l_motor = motor_speed_low
    Ctrlmsg.g_stepper = 0
    Ctrlmsg.s_stepper = 0
    thinker_obj.publish(Ctrlmsg)
    while rclpy.ok and start_op == 0:
        rclpy.spin_once(thinker_obj,timeout_sec=0)
        #thinker_obj.get_logger().info('Publishing: "%s"' % start_op)
    sleep(2)
    thinker_obj.start_timer()  
        #t1 = thinker_obj.get_clock().now()
    puckundersorter = 3
    while puckundersorter != 2 and rclpy.ok(): # wait for puckundersorter to be 2 
        sortercamready = 0
        while sortercamready == 0:
            rclpy.spin_once(thinker_obj,timeout_sec = 0)
        control_motors_obj.StepLeft(thinker_obj)
        #sleep(0.1)
    sleep(0.5)    
    #thinker_obj.get_logger().info('Publishing: "%s"' % puckundersorter)
    control_motors_obj.Step_180(thinker_obj)   
    
    for i in range(8):
        #t1 = thinker_obj.get_clock().now()
        control_motors_obj.mv_forward(thinker_obj) 
        #t2 = thinker_obj.get_clock().now()
        #thinker_obj.get_logger().info(f"time is {t2-t1}")
    
    while rclpy.ok():     
        maincamready = 0
        sortercamready = 0
        puckseen = 0
        while (maincamready == 0 or sortercamready == 0 )and rclpy.ok():
            rclpy.spin_once(thinker_obj,timeout_sec=0)  
          #thinker_obj.get_logger().info('Publishing: %d %d' % (puckseen,baseseen))
        if puckseen == 1 and baseseen == 0:
            #     rclpy.spin_once(thinker_obj,timeout_sec = 0)
            control_motors_obj.mv_forward(thinker_obj)
            sleep(0.1)
            maincamready = 0
            while maincamready == 0 :
                rclpy.spin_once(thinker_obj,timeout_sec=0)  
            if puckseen == 0:
                for i in range(3):
                    control_motors_obj.mv_forward(thinker_obj)
                    sortercamready = 0

            sortercamready = 0
            while ( sortercamready == 0 )and rclpy.ok():
                rclpy.spin_once(thinker_obj,timeout_sec=0) 
             
            
            # if (puckseen == 0):
            #     pass
            # sleep(0.05)
              #control_motors_obj.mv_forward(thinker_obj)
        if puckseen == 0 or baseseen == 1:
            rotate_count = random.randint(1,3)
            for i in range(rotate_count):
                control_motors_obj.rt_clockWise(thinker_obj)
            mv_dir = random.choices([0, 1], weights=[0.4, 0.6])[0]
            mv_mag = random.choices([0, 1, 2], weights=[0.30, 0.30, 0.40])[0]
            if mv_dir:
                for i in range(mv_mag):
                    control_motors_obj.mv_forward(thinker_obj)
            else:
                for i in range(mv_mag):
                    control_motors_obj.mv_backward(thinker_obj)

        if puckundersorter == 0 and  collect_color == 'red':
            control_motors_obj.collect_sortplace(thinker_obj)
            control_motors_obj.default_sortplace(thinker_obj)
            puck_collected_count+=1
        elif puckundersorter == 1 and  collect_color == 'blue':
            control_motors_obj.collect_sortplace(thinker_obj)
            control_motors_obj.default_sortplace(thinker_obj)
            puck_collected_count+=1
        elif puckundersorter == 1 and  collect_color == 'red':
            control_motors_obj.reject_sortplace(thinker_obj)
            control_motors_obj.default_sortplace(thinker_obj)
        elif puckundersorter == 0 and  collect_color == 'blue':
            control_motors_obj.reject_sortplace(thinker_obj)
            control_motors_obj.default_sortplace(thinker_obj)

        
        if round_timout == 1 or puck_collected_count >= 10:
            thinker_obj.get_logger().info('colected : %d' % (puck_collected_count))
            round_timout == 0
            while rclpy.ok():
                maincamready = 0
                sortercamready = 0
                puckseen = 0
                while (maincamready == 0 or sortercamready == 0 ) and rclpy.ok():
                    rclpy.spin_once(thinker_obj,timeout_sec=0)  
                
                if puckseen == 1 :
                    control_motors_obj.mv_forward(thinker_obj)
                    sleep(0.1)
                    maincamready = 0
                    while maincamready == 0 :
                        rclpy.spin_once(thinker_obj,timeout_sec=0)  
                if baseseen == 1:
                    for i in range(10):
                        control_motors_obj.mv_forward(thinker_obj)
                        sleep(0.1)
                    for i in range(5): # rotate 180
                        control_motors_obj.rt_clockWise(thinker_obj)
                        sleep(0.1)
                    control_motors_obj.open_gate(thinker_obj)
                    for i in range(5):
                        control_motors_obj.mv_forward(thinker_obj)
                        sleep(0.1)
                    control_motors_obj.close_gate()
                    while rclpy.ok():
                        rclpy.spin_once(thinker_obj,timeout_sec=0)
                    
                if puckseen == 0 and baseseen == 0:
                    rotate_count = random.randint(1,3)
                    for i in range(rotate_count):
                        control_motors_obj.rt_clockWise(thinker_obj)
                    mv_dir = random.choices([0, 1], weights=[0.4, 0.6])[0]
                    mv_mag = random.choices([0, 1, 2], weights=[0.30, 0.30, 0.40])[0]
                    if mv_dir:
                        for i in range(mv_mag):
                            control_motors_obj.mv_forward(thinker_obj)
                    else:
                        for i in range(mv_mag):
                            control_motors_obj.mv_backward(thinker_obj)
        sleep(0.1)
            # Destroy the node explicitly
    # when the garbage collector destroys the node object)

    Ctrlmsg.r_motor = motor_speed_low
    Ctrlmsg.l_motor = motor_speed_low
    thinker_obj.publish(Ctrlmsg)

    thinker_obj.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

