// Define the number of sensors
const int numSensors = 3;

// Array to store sensor values
int sensorValues[numSensors];

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Your main loop code here
  // Read and store sensor values
  for (int i = 0; i < numSensors; i++) {
    sensorValues[i] = analogRead(A0 + i);  // Read from A0, A1, A2 in sequence
    delay(1000);  // Optional delay to stabilize readings
  }
  // Print the stored sensor values
  Serial.println("Sensor Values:");
  printSensorValues();
}

// Function to print sensor values
void printSensorValues() {
  for (int i = 0; i < numSensors; i++) {
    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(sensorValues[i]);
  }
}
