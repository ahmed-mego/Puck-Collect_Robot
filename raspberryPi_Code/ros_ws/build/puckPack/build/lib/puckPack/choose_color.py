#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int8
from std_msgs.msg import String
from time import sleep
import lgpio 
BUTTON_GPIO = 10
BLUE_GPIO = 18
RED_GPIO = 23
h = lgpio.gpiochip_open(0)
lgpio.exceptions = False
if h < 0:
    print("error")
class SwitchPublisher(Node):

    def __init__(self):
        super().__init__('switchPublisher')
        self.publisher_ = self.create_publisher(Int8, 'main_color', 10)

    def publish(self,msg):
        self.publisher_.publish(msg)
        
def main(args=None):
    rclpy.init(args=args)
    lgpio.gpio_claim_input(h,BUTTON_GPIO,32)
    lgpio.gpio_claim_output(h,RED_GPIO)
    lgpio.gpio_claim_output(h,BLUE_GPIO)

#    print(lgpio.gpio_get_mode(BUTTON_GPIO))
    
    new_val = lgpio.gpio_read(h, BUTTON_GPIO) 
    old_val = new_val

    switchPublisher = SwitchPublisher()
    msg = Int8()
    msg.data = 0    
    while rclpy.ok():
        
        new_val = lgpio.gpio_read(h, BUTTON_GPIO) 
        if new_val == 0 and old_val == 1:
            if msg.data == 0: 
                msg.data = 1
            else:
                msg.data = 0

        
            sleep(1)
        print(msg.data,new_val)
        old_val = new_val
        
        if msg.data == 0 :
            lgpio.gpio_write(h, BLUE_GPIO, 0)
            lgpio.gpio_write(h, RED_GPIO, 1)

        else :
            lgpio.gpio_write(h, RED_GPIO, 0)
            lgpio.gpio_write(h, BLUE_GPIO, 1)

        switchPublisher.publish(msg)

    switchPublisher.destroy_node()
    lgpio.gpio_free(h,BUTTON_GPIO)
    lgpio.gpio_free(h,RED_GPIO)
    lgpio.gpio_free(h,BLUE_GPIO)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
