#include <Arduino.h>
#include "ServerSocket.h"

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(led, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("Connected to Wifi, Connecting to server.");

  bool connected = client.
}

void loop()
{
  // put your main code here, to run repeatedly:

}