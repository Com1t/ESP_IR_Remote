#define OTA_ENABLE true
#include "BaseOTA.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include "kbro_ir_codes.h"

// WiFi credentials
const char* ssid = "********";
const char* password = "********";

// Set Static IP address
IPAddress local_IP(192, 168, 50, 65);
IPAddress gateway(192, 168, 50, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(192, 168, 50, 1);    //optional
IPAddress secondaryDNS(1, 1, 1, 1);    //optional

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).

IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.

// Initialize the web server on port 80
ESP8266WebServer server(80);

// Function to handle button press requests
void handleButtonPress() {
  int buttonId = server.arg("button").toInt();

  Serial.println(buttonId);

  // Based on empirical result, repeat = 2 is better
  irsend.sendXmp(kbro_ir_codes[buttonId], 64, 2);

  server.send(200, "text/plain", "IR signal sent for button ID: " + String(buttonId));
}


void setup() {
  Serial.begin(115200);
  irsend.begin();  // Initialize IR sender

  // Configures static IP address
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\nWiFi connected, IP addr: ");
  Serial.println(WiFi.localIP());

  OTAinit();  // setup OTA handlers

  // Start web server
  server.on("/", []() {
    server.send(200, "text/html", kbro_html_page);
  });
  server.on("/press", handleButtonPress);
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  OTAloopHandler();
  server.handleClient();
}