#include "pvt.h"
#include <WiFi.h>


const char* ssid = SECRET_SSID;       // Your Wi-Fi network name
const char* password = SECRET_PASS; // Your Wi-Fi network password

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  /* WIFI */
  Serial.println("Connecting to WiFi...");
  // Connect to the specified network
  WiFi.begin(ssid, password);
  // Wait for the connection to establish

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    Serial.println("\nConnected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  }
}



void loop() {
}
