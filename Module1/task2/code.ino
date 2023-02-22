// Define the input pin for the PIR sensor
int pirPin = 2;

void setup() {
  // Set the pin mode of the built-in LED to output
  pinMode(LED_BUILTIN, OUTPUT);

  // Set the pin mode of the PIR sensor input to input
  pinMode(pirPin, INPUT);

  // Attach an interrupt to the PIR sensor input
  attachInterrupt(digitalPinToInterrupt(pirPin), motionDetected, CHANGE);

  // Start the serial communication at a baud rate of 9600
  Serial.begin(9600);
}

// Function to handle motion detected interrupt
void motionDetected() {
  // Read the state of the PIR sensor
  int pirState = digitalRead(pirPin);

  // Print the state of the PIR sensor to the serial monitor
  Serial.println(pirState);

  // If motion is detected, turn on the built-in LED
  if (pirState == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Interrupted");
  } else {
    // If no motion is detected, turn off the built-in LED
    digitalWrite(LED_BUILTIN, LOW);
    
  }
}

void loop() {
  // The loop function is not used in this code
}
