#include "hal_adc.h"
#include "stm32f4xx_hal.h" 


extern ADC_HandleTypeDef hadc1;

int hal_adc_read_raw(uint32_t channel, uint32_t *out_value) {
    (void)channel;
    if (out_value == NULL) return -1;

    if (HAL_ADC_Start(&hadc1) != HAL_OK) return -1;
    if (HAL_ADC_PollForConversion(&hadc1, 10) != HAL_OK) {
        HAL_ADC_Stop(&hadc1);
        return -1;
    }
    *out_value = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);
    return 0;
}
