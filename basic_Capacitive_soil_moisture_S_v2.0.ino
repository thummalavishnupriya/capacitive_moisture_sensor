/*
Resistive soil sensors
For general moisture sensors it measures the resistance between 2 pins(water,fertilizer changes resistance)
DC current reacts with water and makes it oxide so corrosion will be a problem 

Capacitive soil sensors(Analog sensor)
Water level changes the capacity, we can measure charge and discharge timing based on the amount of water that we will be measuring
Capacitive soil moisture sensor V2.0 contains timer IC onboard that helps with the timing of sensor
*/

/*
The below sensor ranges from 200 to 481 when its fully wet and fully dry respectively in bangalore climate.
Keep the sensors in dry and wet place and calibrate the values
*/
const int dry = 481;
const int wet = 200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int SensorVal = analogRead(A0);
  int percentageHumidiy = map(SensorVal, wet, dry, 100, 0);
  Serial.print(percentageHumidiy);
  Serial.println("%");
  delay(100);
}
