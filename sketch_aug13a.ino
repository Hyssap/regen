x// Pin definitions
const int relayPin = 8;  // The pin connected to the base of the transistor
const int sensorPin = A0; // The pin connected to the voltage divider

// Voltage divider constants
const float R1 = 4600.0; // R1 in ohms
const float R2 = 3300.0; // R2 in ohms

// Reference voltage
const float referenceVoltage = 5.0; // Arduino analog reference voltage

// Threshold voltage in volts
const float thresholdVoltage = 8.0;

void setup() {
  // Initialize relay pin as an output
  pinMode(relayPin, OUTPUT);
  // Initialize sensor pin as an input
  pinMode(sensorPin, INPUT);
  
  // Start serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the voltage divider
  int sensorValue = analogRead(sensorPin);
  
  // Convert the analog value to a voltage
  float sensorVoltage = (sensorValue / 1023.0) * referenceVoltage;
  
  // Calculate the actual voltage from the divider
  float actualVoltage = sensorVoltage * ((R1 + R2) / R2);
  
  // Debugging output to the Serial Monitor (optional)
  Serial.print("Measured Voltage: ");
  Serial.println(actualVoltage);
  
  // Check if the measured voltage is greater than the threshold
  if (actualVoltage > thresholdVoltage) {
    digitalWrite(relayPin, HIGH); // Activate the relay
  } else {
    digitalWrite(relayPin, LOW);  // Deactivate the relay
  }
  
  // Small delay to avoid rapid toggling
  delay(100);
}
