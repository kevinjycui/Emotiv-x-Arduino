import serial
import json
from websocket import create_connection
import ssl
import time
import requests
import setup

receivedData = create_connection("wss://emotivcortex.com:54321", sslopt={"cert_reqs": ssl.CERT_NONE})
ser = serial.Serial('COM5', 9600)

def get_value():
    data = json.loads(receivedData.recv())
    if 'met' in data:
        value = data['met']
        return value
    else:
        return -1

setup.setup()

while True:
    select = int(input("Focus levels (0) or all levels (1)?\n>>> "))
    if select == 0:
        exit_flag = False
        exit_flag2 = True
        ser.write('s'.encode())
        break
    elif select == 1:
        exit_flag2 = False
        exit_flag = True
        ser.write('m'.encode())
        break

sum1 = 0
total = 0
avg = 0.5

while not exit_flag:
    val = get_value()
    print(val[2], avg)
    if val[2] > avg:
        ser.write('1'.encode())
        print(1)
    else:
        ser.write('0'.encode())
        print(0)
    sum1+=val[2]
    total+=1
    avg = sum1/total

sumList = [0]*7
total = 0
avgList = [0.5]*7

while not exit_flag2:
    val = get_value()
    print(val, avgList)
    result = ['']*7
    for i in range(len(val)):
        if val[i]>avgList[i]:
            result[i] = '1'
            print(1)
        else:
            result[i] = '0'
            print(0)
        sumList[i]+=val[i]
        total+=1
        avgList[i] = sumList[i]/total
    for data in result:
        ser.write(data.encode())
    
ser.close()


