
//set up output pin for LED test
int output_led = 9;

//set the status led
int status_led = 10;

void setup() 
{
  //Set the serial connection to be 9600
  Serial.begin(9600);
  
}

void loop() 
{

  //Write to the serial interface
  Serial.print("Hello World\\n");
  delay(10000);
  
}
