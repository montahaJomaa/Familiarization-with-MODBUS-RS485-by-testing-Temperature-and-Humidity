
#Modbus Sensor Data Reader
This code provides a simple implementation of a Modbus sensor data reader using the SimpleModbusMaster_DUE library. It is designed to communicate with multiple Modbus slave devices and read temperature and humidity values from them.

#Dependencies
SimpleModbusMaster_DUE library
HardwareSerial library

#Circuit Setup
Connect the Modbus slave devices to the Arduino board via the appropriate communication interface (e.g., RS485 or RS232).
Connect the required communication pins (e.g., Tx, Rx) between the Arduino board and the Modbus slave devices.

#Configuration
Adjust the baud rate (baud), timeout value (timeout), polling interval (polling), and retry count (retry_count) according to your specific requirements.
Set the correct values for the slave device IDs, Modbus function codes, register addresses, and the number of registers to be read in the modbus_construct function calls.

#Operation
The code initializes the serial communication for both the Arduino board (Serial) and the Modbus slave devices (Serial2).
It constructs three Modbus packets (PACKET1, PACKET2, and PACKET3) to read data from three different Modbus slave devices.
The Modbus Finite State Machine is configured using the modbus_configure function.
In the loop function, the modbus_update function is called to perform the Modbus communication and update the data.
If new data is received successfully from any of the Modbus packets, the temperature and humidity values are extracted from the registers and printed to the serial monitor.

#Usage
Upload the code to your Arduino board.
Open the serial monitor to view the temperature and humidity values received from the Modbus slave devices.
The code will continuously read and display the sensor data at the specified interval.
