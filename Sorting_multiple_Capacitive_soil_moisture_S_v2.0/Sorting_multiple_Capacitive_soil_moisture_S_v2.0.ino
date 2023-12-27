//Define the number of sensors
const int numSensors = 3;
//Array to store sensor values
int sensorValues[numSensors];

void setup() {
  //Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  //Read and store sensor values
  for (int i=0; i < numSensors; i++) {
    sensorValues[i] = analogRead(A0 + i);  // Read from A0, A1, A2 in sequence
    delay(1000);  // Optional delay to stabilize readings
  }
  //Print the stored sensor values before sorting
  printSensorValues_b4_a4_sort();
}

void printSensorValues_b4_a4_sort() {
  //Printing sensor values before sorting
  Serial.println("  ");
  Serial.println("Sensor Values before sorting");
  for (int i=0; i < numSensors; i++) {
    Serial.print("Sensor");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(sensorValues[i]);
  }
  //sorting
  for(int j=0; j < numSensors-1 ; j++) {
    for(int k=0; k < numSensors-1; k++) {
      if(sensorValues[k] > sensorValues[k+1]) {
        int temp = sensorValues[k];
        sensorValues[k] = sensorValues[k+1];
        sensorValues[k+1] = temp;
        }
     }
  }
  //Printing sensor values after sorting
  Serial.println("Sensor Values after sorting");
  for(int l=0; l < numSensors; l++) {
    Serial.print("Sensor");
    Serial.print(l+1);
    Serial.print(": ");
    Serial.println(sensorValues[l]);
  }
}
