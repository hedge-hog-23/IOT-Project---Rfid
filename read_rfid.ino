#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         22          // Reset pin (not used)
#define SS_PIN          5          // Slave Select pin

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

void setup() {
  Serial.begin(115200);               // Initialize serial communication
  SPI.begin();                      // Init SPI bus
  mfrc522.PCD_Init();               // Init MFRC522

  Serial.println("RFID Ready!");
}

void loop() {
  // Look for new cards
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Show UID on serial monitor
    Serial.print("UID tag :");
    String content = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
      content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    Serial.println();
    Serial.print("Message : ");
    content.toUpperCase();
    Serial.println(content);

    // You can add your code here to write to the RFID tag or perform other actions based on the tag's UID

    delay(1000); // Wait for a second
  }
}
