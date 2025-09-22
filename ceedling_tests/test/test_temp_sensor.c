#include "unity.h"
#include "temp_sensor.h"

void setUp(void) {}
void tearDown(void) {}

void test_sensor_read_temperature_success(void) {
    float temp = 0.0f;
    int rc = sensor_read_temperature(&temp);
    TEST_ASSERT_EQUAL_INT(0, rc);


    int temp_x10 = (int)(temp * 10.0f + 0.5f); 

    TEST_ASSERT_INT_WITHIN(20, 250, temp_x10);
}

void test_sensor_read_temperature_nullptr(void) {
    int rc = sensor_read_temperature(NULL);
    TEST_ASSERT_NOT_EQUAL(0, rc);
}
