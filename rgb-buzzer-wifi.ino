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
WiFiServer server(80); // creating a server in 80 port

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

  // initializing server
  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if(client.connected()) {
    Serial.println("---------------------");
    Serial.print("New client connected: ");
    Serial.println(client.remoteIP());
    
    String message = "";
    Serial.println("Wait client message...");
    
    while(client.available() == 0); // waiting client message
    while(client.available() > 0) {
      char msg = client.read();
      message.concat(msg);
    }

    // commands handling
    if(message == "RED") {
      rgb.red();
    } else if(message == "GREEN") {
      rgb.green();
    } else if(message == "BLUE") {
      rgb.blue();
    } else {
      // rgb string
      int rgbArray[2] = {};
      int lastIndex = 0;

      String rgbCode = "";

      for(int i = 0; i < message.length(); i++) {
        if(message.charAt(i) == ',') {
          rgbArray[lastIndex] = rgbCode.toInt();
          rgbCode = "";
          lastIndex++;
        } else {
          rgbCode.concat(message[i]);
        }
      }

      rgb.rgb(rgbArray[0], rgbArray[1], rgbArray[2]);
    }

    Serial.print("Client message: ");
    Serial.println(message);
    Serial.println("Client closed");
    client.stop();
  }
}
