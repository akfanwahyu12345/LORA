#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1)
      ;
  }
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // Menerima paket
    String received = "";
    while (LoRa.available()) {
      received += (char)LoRa.read();
    }

    // Tampilkan pesan yang diterima
    Serial.print("Received: ");
    Serial.println(received);
  }
}
