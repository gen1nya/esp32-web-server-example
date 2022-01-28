#include <Arduino.h>
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
 
const char* ssid = "yourNetworkName";
const char* password =  "yourNetworkPass";
 
AsyncWebServer server(80);
 
void setup(){
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  Serial.println("Connecting to WiFi..");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
 
  Serial.println(WiFi.localIP());
 
  server.on("/test", HTTP_GET, [](AsyncWebServerRequest *request){
    AsyncWebServerResponse *response = request->beginResponse(200, "text/plain", "Ok");
    response->addHeader("Content-Disposition", "attachment");
    request->send(response);
  });
 
  server.begin();
}
 
void loop(){

}