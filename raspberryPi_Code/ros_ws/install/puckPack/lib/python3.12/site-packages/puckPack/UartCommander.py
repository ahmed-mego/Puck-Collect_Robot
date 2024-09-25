    # Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from ctrl_interface.msg import CtrlInterface


import serial
import time





def array_checksum(arr):
    
    checksum_code = 0
    
    for item in arr:
        item = int(item, 16)
        checksum_code += item
    
    checksum_code = ~checksum_code
    checksum_code = checksum_code % 255
    
    return str(hex((checksum_code & 0xFF)+1)[2:])  # Ensure it returns a uint8_t equivalent (0-255)


def Cerate_StepperCommand(stepper_ID,steps,direction):
    Command = "AA "+f"{stepper_ID:02x}"+" 00 "+f"{(direction & 0xFF):02x}"+" "
    Command +=f"{(((steps >> 8) & 0xff & 0xFF)):02x}"+" "+f"{(steps& 0xFF):02x}"+" "
    val = array_checksum(Command.split())
    Command +=val+" 55"
    #print(Command)
    return Command
    
def Cerate_DcCommand(Dc_ID,PWM,direction):
    Command = "AA "+f"{Dc_ID:02x}"+" 00 "+f"{(direction & 0xFF):02x}"+" "
    Command +=f"{(((PWM >> 8) & 0xff & 0xFF)):02x}"+" "+f"{(PWM& 0xFF):02x}"+" "
    val = array_checksum(Command.split())
    Command +=val+" 55"
    #print(Command)
    return Command
    





class CommandSubscriber(Node):

    def __init__(self,port,baudrate):
        super().__init__('Uart_node')
        self.subscription = self.create_subscription(
            CtrlInterface,
            'ctrltopic',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.ser = serial.Serial(port,baudrate,timeout=None)
        self.last_r_motor = 0
        self.last_l_motor = 0
        self.last_g_stepper = 0
        self.last_s_stepper = 0

    def send_multiple_hex_commands_serial(self, hex_commands):
        # Open a serial connection
        for hex_command in hex_commands:
            # Convert hex command to bytes
            command_bytes = bytes.fromhex(hex_command)
            
            # Send the command
            self.ser.write(command_bytes)
            
    def opengate(self):
        return Cerate_StepperCommand(1,500,0)
        
    def closegate(self):
        return Cerate_StepperCommand(1,500,1)
    def sortermiddle(self):
        s_step = 0
        s_dir =1
        if self.last_s_stepper == 1:
            s_step = 500
            s_dir = 0
        elif self.last_s_stepper == 2:
            s_step = 500
            s_dir = 1
        return Cerate_StepperCommand(0,s_step,s_dir)
    def sorterleft(self):
        s_step = 0
        s_dir =1
        if self.last_s_stepper == 0:
            s_step = 500
            s_dir = 1
        elif self.last_s_stepper == 2:
            s_step = 1000
            s_dir = 1
        return Cerate_StepperCommand(0,s_step,s_dir)
    def sorterright(self):
        s_step = 0
        s_dir =1
        if self.last_s_stepper == 0:
            s_step = 500
            s_dir = 0
        elif self.last_s_stepper == 1:
            s_step = 1000
            s_dir = 0
        return Cerate_StepperCommand(0,s_step,s_dir)
    def listener_callback(self, msg):
        # 0 close 1 open 
        # 0 middle 1 left 2 right 
        t1 = self.get_clock().now()
        hex_commands = list()
        if(msg.g_stepper != self.last_g_stepper):
            if msg.g_stepper == 1:
                hex_commands.append(self.opengate())
                #self.get_logger().info(f"{msg.g_stepper} : {msg}")
            elif msg.g_stepper == 0:
                hex_commands.append(self.closegate())
            self.last_g_stepper = msg.g_stepper
        if(msg.s_stepper != self.last_s_stepper):
            if msg.s_stepper == 0:
                hex_commands.append(self.sortermiddle())
            elif msg.s_stepper == 1:
                hex_commands.append(self.sorterleft())
            elif msg.s_stepper == 2:
                hex_commands.append(self.sorterright())            
            self.last_s_stepper = msg.s_stepper
        if msg.r_motor != self.last_r_motor:
            if msg.r_motor < 0:
                hex_commands.append(Cerate_DcCommand(3,abs(msg.r_motor),1))
            else:
                hex_commands.append(Cerate_DcCommand(3,abs(msg.r_motor),0))
            self.last_r_motor = msg.r_motor
        if msg.l_motor != self.last_l_motor:
            if msg.l_motor < 0:
                hex_commands.append(Cerate_DcCommand(2,abs(msg.l_motor),1))
            else:
                hex_commands.append(Cerate_DcCommand(2,abs(msg.l_motor),0))
            self.last_l_motor = msg.l_motor
        #
        t2 = self.get_clock().now()
        self.send_multiple_hex_commands_serial(hex_commands)
        self.get_logger().info(f"time is {t2-t1}")

def main(args=None):
    rclpy.init(args=args)

    Commander = CommandSubscriber("/dev/ttyAMA3",115200)

    rclpy.spin(Commander)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    Commander.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
