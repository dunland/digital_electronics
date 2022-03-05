import serial
ser = serial.Serial('/dev/ttyACM0', 9600)
# ser = serial.Serial('/dev/ttyACM0', 
#                     baudrate=9600, 
#                     parity=serial.PARITY_NONE, 
#                     stopbits=serial.STOPBITS_ONE)

while(True):
    data=ser.readline()
    print(data)
    print(str(data))
    # ser.read(ser.in_waiting)