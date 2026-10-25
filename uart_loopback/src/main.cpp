#include <Arduino.h>

void setup() {
  Serial.begin(115200); 
  // We are using D18 and D19 for UART2
  Serial2.begin(9600, SERIAL_8N1, 18, 19); 
  Serial.println("UART Loopback Test Started");
}

void loop() {
  Serial2.print("PING"); // Send out D19
  
  if (Serial2.available()) {
    String received = Serial2.readString();
    Serial.print("Echo received: ");
    Serial.println(received);
  } else {
    Serial.println("Sent PING... no echo (check jumper)");
  }
  
  delay(1000);
}