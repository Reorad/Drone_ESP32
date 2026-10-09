#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "ADC.h"
#include "pini.h"


void app_main(void)
{
    ESP_ERROR_CHECK(INIT_ADC(ADC_PIN));

    int raw;
    while (1) {
        ESP_ERROR_CHECK(ADC_READ(&raw));
        printf("ADC: %d\n", raw);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
