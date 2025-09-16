#include "temp_sensor.h"
#include "hal_adc.h"

int sensor_read_temperature(float *out_celsius){
    uint32_t raw = 0;
    if (hal_adc_read_raw(0, &raw) != 0) return -1;
    // Giả sử ADC 12-bit, Vref = 3.3V, LM35 -> 10mV/°C
    float voltage = (raw / 4095.0f) * 3.3f;
    *out_celsius = voltage * 100.0f;
    return 0;
}
