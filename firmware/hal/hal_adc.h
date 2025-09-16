#ifndef HAL_ADC_H
#define HAL_ADC_H
#include <stdint.h>
int hal_adc_read_raw(uint32_t channel, uint32_t *value);
#endif
