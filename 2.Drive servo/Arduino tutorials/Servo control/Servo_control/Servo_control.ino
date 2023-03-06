//UART send 1~9==>20~180 degree
int servopin=9;//servo connect Pin9 on Arduino
int myangle;//Define the angle variable
int pulsewidth;//Define the pulse width variable
int val;
void servopulse(int servopin,int myangle)/*Define a pulse function to generate PWM values in an analog way*/
{
  pulsewidth=(myangle*11)+500;//Convert the angle to a pulse width value of 500-2480
  digitalWrite(servopin,HIGH);//Set the servo interface level to high
  delayMicroseconds(pulsewidth);//Delay pulse width value in microseconds
  digitalWrite(servopin,LOW);//Set the servo interface level to low
  delay(20-pulsewidth/1000);//Set the servo interface level to low
}
void setup()
{
  pinMode(servopin,OUTPUT);//Set the servo pin port as the output port
  Serial.begin(9600);//Set the baud rate to 9600
  Serial.println("servo=o_seral_simple ready" ) ;
}
void loop()
{
	val=Serial.read();//Read the data received by the serial port
	if(val>'0'&&val<='9')//Determine whether the received data value conforms to the range
	{
		val=val-'0';//Convert ASCII code to numerical value, for example '9'-'0'=0x39-0x30=9
		val=val*(180/9);//Convert numbers to angles, example 9*(180/9)=180
		Serial.print("moving servo to ");
		Serial.print(val,DEC);
		Serial.println();
		for(int i=0;i<=50;i++) //Generate PWM number, equivalent delay to ensure that it can turn to the response angle
		{
			servopulse(servopin,val);//Analog to generate PWM
		}
	}
}
