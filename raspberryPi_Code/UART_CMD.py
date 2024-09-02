
import serial
import time


def Init_Serial(port, baudrate):
    ser = serial.Serial(port,baudrate,timeout=1)
    return ser
def send_multiple_hex_commands_serial(ser, hex_commands):
    # Open a serial connection
    for hex_command in hex_commands:
        # Convert hex command to bytes
        command_bytes = bytes.fromhex(hex_command)
        
        # Send the command
        ser.write(command_bytes)
        
        # Read response (optional, depending on the device)
        time.sleep(300/1000)  # Wait for the device to respond
        response = ser.read(ser.in_waiting)
        print(f'Sent: {hex_command}, Received response: {response.hex()}') 


def array_checksum(arr):
    
    checksum_code = 0
    
    for item in arr:
        item = int(item, 16)
        checksum_code += item
    
    checksum_code = ~checksum_code
    checksum_code = checksum_code % 255
    
    return str(hex((checksum_code & 0xFF)+1)[2:])  # Ensure it returns a uint8_t equivalent (0-255)


def Cerate_StepperCommand(stepper_ID,steps,dir):
    Command = "AA "+f"{stepper_ID:02x}"+" 00 "+f"{(dir & 0xFF):02x}"+" "
    Command +=f"{(((steps >> 8) & 0xff & 0xFF)):02x}"+" "+f"{(steps& 0xFF):02x}"+" "
    val = array_checksum(Command.split())
    Command +=val+" 55"
    print(Command)
    return Command
    
def Cerate_DcCommand(Dc_ID,PWM,dir):
    Command = "AA "+f"{Dc_ID:02x}"+" 00 "+f"{(dir & 0xFF):02x}"+" "
    Command +=f"{(((PWM >> 8) & 0xff & 0xFF)):02x}"+" "+f"{(PWM& 0xFF):02x}"+" "
    val = array_checksum(Command.split())
    Command +=val+" 55"
    print(Command)
    return Command
    


# Example usage


serial_port = 'COM5'  # Replace with your serial port
baud_rate = 9600              # Replace with the appropriate baud rate
ser = Init_Serial(serial_port,baud_rate)


"""

['AA 00 00 00 01 f4', 'AA 00 00 01 01 f4', 'AA 01 00 00 01 f4',


 'AA 01 00 01 01 f4', 'AA 02 00 01 ff ff', 'AA 03 00 01 ff ff', 
 
 
 'AA 02 00 01 80 00', 'AA 03 00 01 80 00', 'AA 02 00 01 ff ff',
 'AA 03 00 01 ff ff', 'AA 02 00 00 80 00',

 'AA 03 00 00 80 00', 'AA 02 00 00 ff ff', 'AA 03 00 00 ff ff']
hex_commands = []

Cerate_StepperCommand(00,500,1)
"""
hex_commands = [
Cerate_StepperCommand(00,500,1) , Cerate_StepperCommand(0,500,0)
,Cerate_StepperCommand(00,500,1) , Cerate_StepperCommand(0,500,0)
,Cerate_StepperCommand(00,500,1) , Cerate_StepperCommand(0,500,0)
,Cerate_StepperCommand(00,500,1) , Cerate_StepperCommand(0,500,0)
,Cerate_StepperCommand(00,500,1) , Cerate_StepperCommand(0,500,0)]


"""
for comand in range(len(hex_commands)):
    val = array_checksum(hex_commands[comand].split())
    hex_commands[comand] = hex_commands[comand]+" "+val+" 55"
    
#hex_commands = ['AA 00 00 01 01 f4 5e 55']
send_multiple_hex_commands_serial(ser, hex_commands)

hex_commands = ['AA 02 00 01 80 00', 'AA 02 00 01 ff ff']
for comand in range(len(hex_commands)):
    val = array_checksum(hex_commands[comand].split())
    hex_commands[comand] = hex_commands[comand]+" "+val+" 55"
"""
send_multiple_hex_commands_serial(ser, hex_commands)