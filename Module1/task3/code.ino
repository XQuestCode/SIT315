// Define the input pins for the sensors
int pirPin = 2;
int tmpPin = A0;

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


  // If motion is detected, turn on the built-in LED
  if (pirState == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Motion detected");
  } else {
    // If no motion is detected, turn off the built-in LED
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void loop() {
  // Read the state of the TMP36 temperature sensor
  int tmpReading = analogRead(tmpPin);

  // Convert the analog reading to voltage
  float voltage = tmpReading * 5.0 / 1024.0;

  // Convert the voltage to temperature in degrees Celsius
  float temperature = (voltage - 0.5) * 100;

  // Print the temperature to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("C");

  // Wait for a short time before taking the next reading
  delay(1000);
}
