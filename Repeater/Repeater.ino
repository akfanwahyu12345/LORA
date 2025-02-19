#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // Coba terima paket
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String received = "";
    while (LoRa.available()) {
      received += (char)LoRa.read();
    }

    // Tampilkan pesan yang diterima dan teruskan
    Serial.print("Received: ");
    Serial.println(received);
    LoRa.beginPacket();
    LoRa.print(received);
    LoRa.endPacket();
  }
}
