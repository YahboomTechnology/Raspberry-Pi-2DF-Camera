import smbus
import time
bus = smbus.SMBus(1)

Servo_ADD = 0x2D

def IICServo(servonum, angle):
    bus.write_byte_data(Servo_ADD,servonum,angle)
    time.sleep(0.1)

IICServo(1,0)
time.sleep(2)
IICServo(1,180)
time.sleep(2)
