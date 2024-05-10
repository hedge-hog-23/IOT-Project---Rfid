
#define BUZZER_PIN 2 // Change this to the GPIO pin where your buzzer is connected

void setup() {
  Serial.begin(115200); // Initialize serial communication
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.println("Buzzer test starting...");
}

void loop() {
  Serial.println("Buzzer on");
  digitalWrite(BUZZER_PIN, HIGH); // Turn the buzzer on
  delay(2000); // Wait for 2 seconds
  
  Serial.println("Buzzer off");
  digitalWrite(BUZZER_PIN, LOW); // Turn the buzzer off
  delay(2000); // Wait for 2 seconds
}
