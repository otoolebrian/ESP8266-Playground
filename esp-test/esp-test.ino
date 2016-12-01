
/* Sketch to use AT commands over serial to communicate
 * from Arduino Nano to ESP8266 and then onto a port listener
 * sitting on 192.168.0.13:12345 
  */

void setup() 
{
  
  //Set the serial connection to be 9600
  Serial.begin(9600);

  //Set up the ESP8266 Module, it should be visible on the AP
  //after these commands

  //Insert code to check, for the time being just delay 5 seconds
  //to allow the wifi to connect
  delay(5000);

  //Set the mode for the chip to be 
  
  
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
  Serial.print("AT+CIPSTART=\"TCP\",\""+IP+"\","+port+"\r\n");

  //Delay to allow it to set up
  delay(1000);
  
  //Send the message, and delay for one second to allow the
  //operation to complete
  Serial.print("AT+CIPSEND="+String(message.length())+"\r\n");
  delay(1000);
 
  //Send the message
  Serial.print(message+"\r\n");
  delay(1000);
 
  //Close the connection
  Serial.print("AT+CIPCLOSE\r\n");
}

