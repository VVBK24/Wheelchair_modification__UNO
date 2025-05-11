#include <SoftwareSerial.h>

// Define pins for the emergency call button and Bluetooth module
const int emergencyButtonPin = 2;
SoftwareSerial bluetooth(10, 11); // RX, TX pins for Bluetooth communication

// Variable to store the state of the button
int lastEmergencyButtonState = LOW;
int emergencyButtonState = 0;

void setup() {
  // Initialize the button pin as an input
  pinMode(emergencyButtonPin, INPUT);

  // Set up Bluetooth communication
  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // Read the state of the button
  emergencyButtonState = digitalRead(emergencyButtonPin);

  //debounce
   if (emergencyButtonState != lastEmergencyButtonState) {
    delay(50); // Debounce time
    emergencyButtonState = digitalRead(emergencyButtonPin); // Read again
  }

  // Check if the button is pressed
  if (emergencyButtonState == HIGH) {
    // Call emergency function
    makeEmergencyCall();
  }
}

void makeEmergencyCall() {
  // Send a command to the Bluetooth module to trigger an action on the receiving end
  bluetooth.println("EMERGENCY_CALL");

  // For demonstration purposes, print a message to the Serial Monitor
  Serial.println("Emergency call initiated!");

  // You can add more logic here based on your Bluetooth communication requirements
}