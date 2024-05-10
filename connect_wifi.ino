#include "WiFi.h"

const char* ssid = "Galaxy S21 FE 5G b537";
const char* password = "12345678";

void initWiFi();

void setup() {
  Serial.begin(115200);
  
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  initWiFi();
}

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ");
  Serial.print(ssid);
  Serial.print(" .. ");
  
  int attempt = 0;
  while (WiFi.status() != WL_CONNECTED && attempt < 30) { // Try for 30 seconds
    delay(1000);
    Serial.print('.');
    attempt++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Connection failed.");
  }
}

void loop() {
  // Your code here
}
