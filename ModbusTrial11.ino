#include <SimpleModbusMaster_DUE.h>
#include <HardwareSerial.h>

//#include<SoftwareSerial.h>
//SoftwareSerial mySerial(2, 3); // RX, TX

#define baud 9600
#define timeout 200
#define polling 150 // the scan rate
#define retry_count 10
#define TxEnablePin 4
#define TOTAL_NO_OF_REGISTERS 5

enum
{
  PACKET1,
  PACKET2,
  PACKET3,
  TOTAL_NO_OF_PACKETS // leave this last entry
};

long previousMillis = 0;
long interval = 1000;
unsigned long currentMillis;
unsigned long prev_req,prev_req1,prev_req2;
unsigned long Voltage ;

float hum;
float temp ; 

Packet packets [TOTAL_NO_OF_PACKETS];
unsigned int regs [TOTAL_NO_OF_REGISTERS];

void setup()
{
  Serial.begin(9600) ;
  //Serial.begin(9600) ;
  Serial2.begin(9600,SERIAL_8N1);
  
//    modbus_construct(packet,id of slave,function,register adress,number of registers,local_start_address);   

//    modbus_construct(&packets[PACKET1], 0x0001, 0x06, 0x0101, 0x0003, 7);
//    delay(100) ;

    modbus_construct(&packets[PACKET1], 0x0001, 0x04, 0x0001, 2, 0);
    delay(100) ;

    modbus_construct(&packets[PACKET2], 0x0002, 0x04, 0x0001, 2, 0);
    delay(100) ;

      modbus_construct(&packets[PACKET3], 0x0003, 0x04, 0x0001, 2, 0);
     delay(100) ;
 
  // Initialize the Modbus Finite State Machine  
  modbus_configure(&Serial2, baud, timeout, polling, retry_count, TxEnablePin, packets, TOTAL_NO_OF_PACKETS, regs);
  delay(500) ;

}

void loop()
{

//    if (Serial2.available())
//    Serial.write(Serial2.read());
//  if (Serial.available())
//    Serial2.write(Serial.read());

modbus_update();
currentMillis = millis(); 
  
if (packets[PACKET1].successful_requests > prev_req)
{
prev_req = packets[PACKET1].successful_requests;

   temp= regs[0] /10.0 ; 
   Serial.print("temperature: ");
   Serial.println(temp );

   hum= regs[1] /10.0 ; 
   Serial.print("humidité: ");
   Serial.println(hum);
   
}

if (packets[PACKET2].successful_requests > prev_req1)
{
prev_req1 = packets[PACKET2].successful_requests;

   temp= regs[0] /10.0 ; 
   Serial.print("temperature2: ");
   Serial.println(temp );
 
   hum= regs[1] /10.0 ; 
   Serial.print("humidité2 : ");
   Serial.println(hum);
   
}


if (packets[PACKET3].successful_requests > prev_req2)
{
prev_req2 = packets[PACKET3].successful_requests;

   temp= regs[0] /10.0 ; 
   Serial.print("temperature3: ");
   Serial.println(temp );
 
   hum= regs[1] /10.0 ; 
   Serial.print("humidité3 : ");
   Serial.println(hum);
   
}

//  Serial.print("successful_requests: ");
//  Serial.println(packets[PACKET1].successful_requests);
//  Serial.println("                        || ");
//  Serial.print("failed_requests: ");
//  Serial.print(packets[PACKET1].failed_requests);
//  Serial.println("     || ");
//  Serial.print("exception_errors: ");
//  Serial.print(packets[PACKET1].exception_errors);
//  Serial.println("     || ");
//  Serial.print("connection: ");
//  Serial.print(packets[PACKET1].connection);
//  Serial.println("           || ");

  delay(1000) ;

}
