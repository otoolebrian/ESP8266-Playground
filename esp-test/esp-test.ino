
/* Sketch to use AT commands over serial to communicate
 * from Arduino Nano to ESP8266 and then onto a port listener
 * sitting on 192.168.0.13:12345 
  */


#include<SoftwareSerial.h>
SoftwareSerial softSerial(10,11); //RX,TX

void setup() 
{
  
  //Set the serial connection to be 9600
  softSerial.begin(9600);

  //Set up the ESP8266 Module, it should be visible on the AP
  //after these commands

  //Insert code to check, for the time being just delay 5 seconds
  //to allow the wifi to connect
  delay(5000); 
  
}

void loop() 
{

  //Create the message that is going to be sent
  String message = "Hello World";
  sendInfo(message, "192.168.0.10","12345");
  delay(5000);


  
}

/*
 * Function to send a message to a predetermined IP & Port
 */
void sendInfo(String message, String IP, String port)
{
  //Create the connection to the listening server
  softSerial.print("AT+CIPSTART=\"TCP\",\""+IP+"\","+port+"\r\n");

  //Delay to allow it to set up
  delay(1000);
  
  //Send the message, and delay for one second to allow the
  //operation to complete
  softSerial.print("AT+CIPSEND="+String(message.length())+"\r\n");
  delay(1000);
 
  //Send the message
  softSerial.print(message+"\r\n");
  delay(1000);
 
  //Close the connection
  softSerial.print("AT+CIPCLOSE\r\n");
}

