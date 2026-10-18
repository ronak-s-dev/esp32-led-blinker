#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void app_main(void)
{
    printf("LED Blinker program started!\n");

    gpio_reset_pin(GPIO_NUM_18);
    gpio_set_direction(GPIO_NUM_18, GPIO_MODE_OUTPUT);

    while(1){
        gpio_set_level(GPIO_NUM_18, 1);
        vTaskDelay(pdMS_TO_TICKS(100));

        gpio_set_level(GPIO_NUM_18, 0);
        vTaskDelay(pdMS_TO_TICKS(100));

        printf("Blink Cycle Completed!\n");
    }
}
