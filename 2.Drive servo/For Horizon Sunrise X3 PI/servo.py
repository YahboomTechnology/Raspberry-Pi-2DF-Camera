# -*- coding:utf-8 -*-
import binascii
import serial
import serial.tools.list_ports
import time


# 打开串口/Open serial port
def serial_open(n=0):
    global ser
    ser = serial.Serial("/dev/ttyS3",9600,timeout=1)
    if ser.isOpen():
        print( "open success")
        return 0
    else:
        print("open failed")
        return 255




def UARTServo(servonum, angle):
    servonum = 64 + servonum
    date1 = int(angle/100 + 48)
    date2 = int((angle%100)/10 + 48)
    date3 = int(angle%10 + 48)
    cmd=bytearray([36,servonum,date1,date2,date3,35])
    print(cmd)
    ser.write(cmd)
    time.sleep(0.05)

serial_open()
UARTServo(1,0)
time.sleep(2)
UARTServo(1,180)
time.sleep(2)
