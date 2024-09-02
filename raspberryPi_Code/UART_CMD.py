
import serial
import time

def send_multiple_hex_commands_serial(port, baudrate, hex_commands):
    # Open a serial connection
    with serial.Serial(port, baudrate, timeout=1) as ser:
        for hex_command in hex_commands:
            # Convert hex command to bytes
            command_bytes = bytes.fromhex(hex_command)
            
            # Send the command
            ser.write(command_bytes)
            
            # Read response (optional, depending on the device)
            time.sleep(1)  # Wait for the device to respond
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

# Example usage
serial_port = 'COM5'  # Replace with your serial port
baud_rate = 9600              # Replace with the appropriate baud rate
hex_commands = ['AA 00 00 00 01 f4', 'AA 00 00 01 01 f4', 'AA 01 00 00 01 f4', 'AA 01 00 01 01 f4', 'AA 02 00 01 ff ff', 'AA 03 00 01 ff ff', 'AA 02 00 01 00 00', 'AA 03 00 01 00 00', 'AA 02 00 01 ff ff', 'AA 03 00 01 ff ff', 'AA 02 00 00 00 00', 'AA 03 00 00 00 00', 'AA 02 00 00 ff ff', 'AA 03 00 00 ff ff']
#hex_commands = ['AA 02 00 01 ff ff']

for comand in range(len(hex_commands)):
    val = array_checksum(hex_commands[comand].split())
    hex_commands[comand] = hex_commands[comand]+" "+val+" 55"
    
#hex_commands = ['AA 00 00 01 01 f4 5e 55']
send_multiple_hex_commands_serial(serial_port, baud_rate, hex_commands)
