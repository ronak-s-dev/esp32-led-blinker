#include "driver/gpio.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>

int increase_or_decrease_rpm(int direction, int *rpm);

void app_main(void) {
  printf("Encoder program started!\n");

  gpio_reset_pin(GPIO_NUM_25);
  gpio_set_direction(GPIO_NUM_25, GPIO_MODE_INPUT);
  gpio_set_pull_mode(GPIO_NUM_25, GPIO_PULLUP_ONLY);

  gpio_reset_pin(GPIO_NUM_26);
  gpio_set_direction(GPIO_NUM_26, GPIO_MODE_INPUT);
  gpio_set_pull_mode(GPIO_NUM_26, GPIO_PULLUP_ONLY);

  int clk_state, dt_state;
  clk_state = gpio_get_level(GPIO_NUM_25);
  dt_state = gpio_get_level(GPIO_NUM_26);
  int target_rpm = 0;

  int prev_state = (clk_state << 1) | dt_state;

  int direction_table[4][4] = {
      {0, -1, +1, 0}, {+1, 0, 0, -1}, {-1, 0, 0, +1}, {0, +1, -1, 0}};

  int encoder_count = 0;

  while (1) {
    clk_state = gpio_get_level(GPIO_NUM_25);
    dt_state = gpio_get_level(GPIO_NUM_26);

    int curr_state = (clk_state << 1) | dt_state;

    if (prev_state != curr_state) {
      int direction = direction_table[prev_state][curr_state];
      printf("PREV=%d CURR=%d DIR=%d\n", prev_state, curr_state, direction);
      switch (direction) {
      case +1:
        printf("Direction is ClockWise %d\n", direction);
        encoder_count++;
        increase_or_decrease_rpm(direction, &target_rpm);
        break;
      case -1:
        printf("Direction is Anti-ClockWise %d\n", direction);
        encoder_count--;
        increase_or_decrease_rpm(direction, &target_rpm);
        break;
      default:
        printf("Invalid / No Movement\n");
      }
      prev_state = curr_state;
    }

    vTaskDelay(pdMS_TO_TICKS(1));
  }
}

int increase_or_decrease_rpm(int direction, int *rpm) {
  // Retains the transition count between function calls
  static int transition_count = 0;

  // Accumulate the encoder's direction
  if (direction == 1) {
    transition_count++;
  } else if (direction == -1) {
    transition_count--;
  }

  printf("Transition accumulator: %d\n", transition_count);

  if (transition_count >= 4) {
    if (*rpm < 100) {
      *rpm += 1;
    }

    transition_count = 0;
  } else if (transition_count <= -4) {
    if (*rpm > 0) {
      *rpm -= 1;
    }
    transition_count = 0;
  }
  printf("Target RPM: %d\n", *rpm);
  return *rpm;
}
