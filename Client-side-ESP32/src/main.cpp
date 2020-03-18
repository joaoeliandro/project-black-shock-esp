#include <Arduino.h>
#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_spi_flash.h"
#include "serverSocket.h"

void setup()
{
  Serial.begin(115200);

  pinMode(led, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("Connected to WiFi, Connecting to server.");

  bool connected = client.connect(websockets_server_host, websockets_server_port, "/");

  if (connected)
  {
    Serial.println("Connected!");
    client.send("Hello Server");
  }
  else
  {
    Serial.println("Not Connected!");
    return;
  }

  client.onMessage([&](WebsocketsMessage message) {
    Serial.print("Got Message!");
    Serial.println(message.data());

    if (message.data().equalsIgnoreCase("ON"))
    {
      digitalWrite(led, HIGH);
    }
    else if (message.data().equalsIgnoreCase("OFF"))
    {
      digitalWrite(led, LOW);
    }
  });
}

void loop()
{
  if (client.available())
  {
    client.poll();

    delay(1);
  }
}

// gpio_num_t pin1 = (gpio_num_t)2;

// extern "C" void app_main()
// {
//   gpio_pad_select_gpio(pin1);
//   gpio_set_direction(pin1, (gpio_mode_t)GPIO_MODE_DEF_OUTPUT);
//   printf("Hello World!\n");
//   while (1)
//   {
//     printf("test");
//     gpio_set_level(pin1, 0);
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//     gpio_set_level(pin1, 1);
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//   }
// }