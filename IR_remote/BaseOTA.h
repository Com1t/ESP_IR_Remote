#ifndef OTA_ENABLE
#define OTA_ENABLE false
#endif  // OTA_ENABLE

#if OTA_ENABLE

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

void OTAinit() {
  // See BasicOTA ESP example for source and settings
  ArduinoOTA.setHostname("ESP_IR");
  // Remember to set password!
  ArduinoOTA.setPassword((const char *)"12345678");

  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else
      type = "filesystem";

    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });

  ArduinoOTA.begin();
}

void OTAloopHandler() {
  ArduinoOTA.handle();
}

#else   // OTA_ENABLE
void OTAwifi() {}
void OTAinit() {}
void OTAloopHandler() {}
#endif  // OTA_ENABLE
