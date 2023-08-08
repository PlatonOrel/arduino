import serial.tools.list_ports
import csv
ports = serial.tools.list_ports.comports()
for port in ports:
    print('Доступные com порты: ', port.device)

baudrate = 9600 #скорость порта
port = str(input('Введите номер порта: '))

try:
    ser = serial.Serial(port, baudrate=baudrate)
    print('Serial connection')
    while True:
        line = ser.readline().decode()
        if line:
            print(line)
            print(type(line))
        with open('test.csv', 'a') as file:

            file.write(line)



except serial.SerialException as se:
    print("Serial port error:", str(se))

