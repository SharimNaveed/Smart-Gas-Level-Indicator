#include<SoftwareSerial.h>
int bluetoothTx=2;
int bluetoothRx=3;
int sig=A2;
int sensorvalue;
int value;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
Serial.begin(9600);
pinMode(sig, INPUT);
bluetooth.begin(115200);
bluetooth.print("$");
bluetooth.print("$");
bluetooth.print("$");
delay(100);
bluetooth.println("U,9600,N");
bluetooth.begin(9600);
}

void loop() 
{
  if(bluetooth.available())
{
  Serial.print((char)bluetooth.read());
}
 sensorvalue=analogRead(sig);
 
 value=map(sensorvalue,0,1023,0,80);
 Serial.println(value);
 bluetooth.print(value);
 delay(1000);
}
