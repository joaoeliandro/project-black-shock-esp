#include <Arduino.h>
#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_spi_flash.h"
#include "serverSocket.hpp"

gpio_num_t pin1 = (gpio_num_t)2;

extern "C" void app_main()
{
  gpio_pad_select_gpio(pin1);
  gpio_set_direction(pin1, (gpio_mode_t)GPIO_MODE_DEF_OUTPUT);
  printf("Hello World!\n");
  while (1)
  {
    printf("test");
    gpio_set_level(pin1, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_set_level(pin1, 1);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}