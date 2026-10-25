
#include "driver/gpio.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>

void app_main(void) {
  printf("Button debounce program started!\n");

  gpio_reset_pin(GPIO_NUM_19);
  gpio_set_direction(GPIO_NUM_19, GPIO_MODE_INPUT);
  gpio_set_pull_mode(GPIO_NUM_19, GPIO_PULLUP_ONLY);

  gpio_reset_pin(GPIO_NUM_18);
  gpio_set_direction(GPIO_NUM_18, GPIO_MODE_OUTPUT);
  gpio_set_level(GPIO_NUM_18, 0);

  int curr_btn_state = gpio_get_level(GPIO_NUM_19);
  int stable_btn_state = curr_btn_state;
  int candidate_btn_state = curr_btn_state;
  int led_state = 0;

  int64_t now_us = esp_timer_get_time();
  int64_t candidate_since_us = now_us;

  while (1) {
    curr_btn_state = gpio_get_level(GPIO_NUM_19);
    now_us = esp_timer_get_time();

    if (curr_btn_state != candidate_btn_state) {
      candidate_btn_state = curr_btn_state;
      candidate_since_us = now_us;
    } else if (candidate_btn_state != stable_btn_state &&
               (now_us - candidate_since_us) >= 25000) {
      stable_btn_state = candidate_btn_state;
      printf("Stable button state: %d\n", stable_btn_state);
      if (stable_btn_state == 0) {
        led_state = !led_state;
        gpio_set_level(GPIO_NUM_18, led_state);
      }
    }

    vTaskDelay(pdMS_TO_TICKS(10));
  }
}
