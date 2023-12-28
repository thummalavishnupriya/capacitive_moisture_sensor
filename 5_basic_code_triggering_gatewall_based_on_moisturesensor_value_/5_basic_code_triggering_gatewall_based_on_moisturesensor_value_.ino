//Basic code for gatevalve triggering based on moisture level
/*
This code triggers the gatevalves of which moisture level is low by turning off the remaining gatevalves
The exact moisture levels and motor turning off code will be added in the next code snippets. This is just to check the logic levels

Tested code with leds and 3 moisture sensors
whatever the moisture sensor value is low, the mcu will trigger that particular gatevalve.
*/
int s0;
int s1;
int s2;
void setup() {
  Serial.begin(9600);
  //Defining pins for turning on gatwalls for which moisture levels are low  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}
void loop() {
  s0 = analogRead(A0);
  s1 = analogRead(A1);
  s2 = analogRead(A2);
  Serial.print("A0 : ");
  Serial.print(s0);
  Serial.print("  ");
  Serial.print("A1 : ");
  Serial.print(s1);
  Serial.print("  ");
  Serial.print("A2 : ");
  Serial.print(s2);
  Serial.println("");
  if(s0>s1 && s0>s2)
  {
    //Turns on s0 gatewall if moisture content is less
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    }
  if(s1>s0 && s1>s2)
  {
    //Turns on s1 gatewall if moisture content is less
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    }
  if(s2>s0 && s2>s1)
  {
    //Turns on s2 gatewall if moisture content is less
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    }
   delay(1000);
}
