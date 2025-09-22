#include "temp_sensor.h"
#include "hal_adc.h"
#include <stddef.h>     
#include <stdint.h>

int sensor_read_temperature(float *out_celsius) {
    if (out_celsius == NULL) return -1;

    uint32_t raw = 0;
    if (hal_adc_read_raw(0, &raw) != 0) return -1;

    // ADC 12-bit (0..4095), Vref = 3.3V
    float voltage = (raw / 4095.0f) * 3.3f;
    
    *out_celsius = voltage * 100.0f;
    return 0;
}
