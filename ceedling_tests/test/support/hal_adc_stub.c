#include <stdint.h>
#include <stddef.h>     
#include <stdint.h>

/* Stub simple trả raw ~310 (tương đương ~25°C với LM35) */
int hal_adc_read_raw(uint32_t channel, uint32_t *out_value) {
    (void)channel;
    if (out_value == NULL) return -1;
    *out_value = 310u;
    return 0;
}