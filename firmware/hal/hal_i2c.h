#ifndef HAL_I2C_H
#define HAL_I2C_H
#include <stdint.h>
int hal_i2c_read(uint16_t dev_addr, uint8_t reg, uint8_t *buf, uint16_t len);
int hal_i2c_write(uint16_t dev_addr, uint8_t reg, const uint8_t *buf, uint16_t len);
#endif
