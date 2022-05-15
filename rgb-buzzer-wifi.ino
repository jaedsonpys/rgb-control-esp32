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
  Serial.begin(9600);
  
  // connecting wifi
  Serial.print("Connecting to WiFi");
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("OK");

  // led signal to WiFi connected
  Serial.println("WiFi connected");
  
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  
  for(int i = 0; i < 6; i++) {
    rgb.green();
    delay(200);
    rgb.green();
    delay(200);
  }

  if(MDNS.begin("esp32")) {
    Serial.println("mDNS Started.");
  }
}

void loop() {
  
}
