// Define the input pin for the PIR sensor
int pirPin = 2;

void setup() {
  // Set the pin mode of the built-in LED to output
  pinMode(LED_BUILTIN, OUTPUT);

  // Set the pin mode of the PIR sensor input to input
  pinMode(pirPin, INPUT);

  // Start the serial communication at a baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Read the state of the PIR sensor
  int pirState = digitalRead(pirPin);
  
  // If motion is detected, turn on the built-in LED
  if (pirState == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
    // Print the state of the PIR sensor to the serial monitor
    Serial.println("Motion detected");
  } else {
    // If no motion is detected, turn off the built-in LED
    digitalWrite(LED_BUILTIN, LOW);
    // Print the state of the PIR sensor to the serial monitor
    Serial.println("No motion detected!");
  }
}
