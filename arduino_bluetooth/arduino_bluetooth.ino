/*
NSAC - Near Space Arduino Course
Spring 2017
UPC Space Program


Code to show serial data treatment based in a non-interrupt software
*/


#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // Rx and Tx of your Arduino

char c[100];
int i = 0;
int relay = 10;
bool input = false;
void setup()
{
  Serial.begin(9600);
  Serial.println("Arduino is ready");
  Serial.println("Remember to select Both NL & CR i  n the serial monitor");
  BTserial.begin(9600);
  pinMode(relay, OUTPUT);




}
void loop()
{
    delay(500);
    if (BTserial.available()){
    input = true;
    while(BTserial.available()){
      c[i] = BTserial.read();
      i++;
      }
}

 if(input){

 // We write through our Arduino Serial port (USB connected) what we sent.
 Serial.println("Input detected, you sent:");
 Serial.println(c);

 // We write to out mobile phone
 BTserial.print("You sent: ");
 BTserial.println(c);

 //We see what can we do with our data
 if(!strcmp(c,"on")){
  //do something
  digitalWrite(relay, LOW);
  }
  else if (!strcmp(c,"off")) {
    digitalWrite(relay, HIGH);
  }
 //reset variables
 input = false;
 i = 0;
 memset(c,0, sizeof(c));
 }
}
