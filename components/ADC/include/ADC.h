#ifndef _ADC_H
#define _ADC_H

#include "esp_err.h"

esp_err_t INIT_ADC(int gpio);

esp_err_t ADC_READ(int *raw);

#endif
