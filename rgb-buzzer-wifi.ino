#include <WiFi.h>
#include <WiFiClient.h>
#include <ESPmDNS.h>

#include "rgb.h"

const int redLedPin = 33;
const int greenLedPin = 27;
const int blueLedPin = 14;

// wifi data
const char *ssid = "test";
const char *password = "test";

RGB rgb(redLedPin, greenLedPin, blueLedPin);

void setup(){
  // connecting wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // led signal to WiFi connected
  for(int i = 0; i < 6; i++) {
    rgb.green();
    delay(200);
    rgb.green();
    delay(200);
  }

  MDNS.begin("esp32");
}

void loop() {
  
}
