#include "ADC.h"
#include "esp_adc/adc_oneshot.h"

static adc_oneshot_unit_handle_t adc_handle;
static adc_channel_t adc_channel;

esp_err_t INIT_ADC(int gpio){

    adc_unit_t unit;

    esp_err_t ret_err = adc_oneshot_io_to_channel(gpio, &unit, &adc_channel);
    if(ret_err != ESP_OK)
        return ret_err;

    adc_oneshot_unit_init_cfg_t init_cfg ={
        .clk_src = ADC_RTC_CLK_SRC_DEFAULT,
        .unit_id =  unit,
        .ulp_mode = ADC_ULP_MODE_DISABLE
    };

    ret_err = adc_oneshot_new_unit(&init_cfg, &adc_handle);
    if(ret_err != ESP_OK)
        return ret_err;

    adc_oneshot_chan_cfg_t config = {
        .atten = ADC_ATTEN_DB_12,
        .bitwidth = ADC_BITWIDTH_12
    };

    return adc_oneshot_config_channel(adc_handle, adc_channel, &config);
}

esp_err_t ADC_READ(int *raw){
    return adc_oneshot_read(adc_handle, adc_channel, raw);
}
