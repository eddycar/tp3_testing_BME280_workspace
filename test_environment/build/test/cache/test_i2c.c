#include "../I2C_BME248_ComPolling/App/Inc/I2C.h"
#include "mock_stm32wlxx_hal.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


I2C_HandleTypeDef hi2c1;







void setUp(void)

{



}







void tearDown(void)

{



}

void test_user_i2c_read_transmit_and_receive_success(void) {

    uint8_t reg_addr = 0x10;

    uint8_t reg_data[2] = {0};

    uint32_t len = 2;

    uint8_t dev_addr = 0x76;

    void *intf_ptr = &dev_addr;



    HAL_I2C_Master_Transmit_CMockExpectAndReturn(35, &hi2c1, dev_addr << 1, &reg_addr, 1, 0xFFFFFFFFU, HAL_OK);

    HAL_I2C_Master_Receive_CMockExpectAndReturn(36, &hi2c1, dev_addr << 1, reg_data, len, 0xFFFFFFFFU, HAL_OK);



    int8_t result = user_i2c_read(reg_addr, reg_data, len, intf_ptr);

    UnityAssertEqualNumber((UNITY_INT)((HAL_OK)), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

}

void test_user_i2c_read_transmit_error(void) {

    uint8_t reg_addr = 0x10;

    uint8_t reg_data[2] = {0};

    uint32_t len = 2;

    uint8_t dev_addr = 0x76;

    void *intf_ptr = &dev_addr;



    HAL_I2C_Master_Transmit_CMockExpectAndReturn(56, &hi2c1, dev_addr << 1, &reg_addr, 1, 0xFFFFFFFFU, HAL_ERROR);



    int8_t result = user_i2c_read(reg_addr, reg_data, len, intf_ptr);

    UnityAssertEqualNumber((UNITY_INT)((HAL_ERROR)), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

}

void test_user_i2c_read_transmit_success_receive_failure(void) {

    uint8_t reg_addr = 0x10;

    uint8_t reg_data[2] = {0};

    uint32_t len = 2;

    uint8_t dev_addr = 0x76;

    void *intf_ptr = &dev_addr;



    HAL_I2C_Master_Transmit_CMockExpectAndReturn(76, &hi2c1, dev_addr << 1, &reg_addr, 1, 0xFFFFFFFFU, HAL_OK);

    HAL_I2C_Master_Receive_CMockExpectAndReturn(77, &hi2c1, dev_addr << 1, reg_data, len, 0xFFFFFFFFU, HAL_ERROR);



    int8_t result = user_i2c_read(reg_addr, reg_data, len, intf_ptr);

    UnityAssertEqualNumber((UNITY_INT)((HAL_ERROR)), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

}

void test_user_i2c_write_success(void) {

    uint8_t reg_addr = 0x10;

    uint8_t reg_data[2] = {0x01, 0x02};

    uint32_t len = 2;

    uint8_t dev_addr = 0x76;

    void *intf_ptr = &dev_addr;



    uint8_t expected_buffer[3] = {reg_addr, reg_data[0] , reg_data[1] };



    HAL_I2C_Master_Transmit_CMockExpectAndReturn(99, &hi2c1, dev_addr << 1, expected_buffer, len + 1, 0xFFFFFFFFU, HAL_OK);



    int8_t result = user_i2c_write(reg_addr, reg_data, len, intf_ptr);

    UnityAssertEqualNumber((UNITY_INT)((HAL_OK)), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_INT);

}

void test_user_i2c_write_transmit_error(void) {

    uint8_t reg_addr = 0x10;

    const uint8_t reg_data[2] = {0x01, 0x02};

    uint32_t len = 2;

    uint8_t dev_addr = 0x76;

    void *intf_ptr = &dev_addr;



    uint8_t buffer[len + 1];

    buffer[0] = reg_addr;

    memcpy(&buffer[1], reg_data, len);



    HAL_I2C_Master_Transmit_CMockExpectAndReturn(123, &hi2c1, dev_addr << 1, buffer, len + 1, 0xFFFFFFFFU, HAL_ERROR);



    int8_t result = user_i2c_write(reg_addr, reg_data, len, intf_ptr);

    UnityAssertEqualNumber((UNITY_INT)((HAL_ERROR)), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(126), UNITY_DISPLAY_STYLE_INT);

}

void test_user_i2c_write_zero_length(void) {

    uint8_t reg_addr = 0x10;

    const uint8_t *reg_data = 

                             ((void *)0)

                                 ;

    uint32_t len = 0;

    uint8_t dev_addr = 0x76;

    void *intf_ptr = &dev_addr;



    int8_t result = user_i2c_write(reg_addr, reg_data, len, intf_ptr);

    UnityAssertEqualNumber((UNITY_INT)((HAL_ERROR)), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(144), UNITY_DISPLAY_STYLE_INT);

}















void test_user_i2c_read_null_interface_pointer(void) {

    uint8_t reg_addr = 0x10;

    uint8_t reg_data[2] = {0};

    uint32_t len = 2;

    void *intf_ptr = 

                    ((void *)0)

                        ;



    int8_t result = user_i2c_read(reg_addr, reg_data, len, intf_ptr);

    UnityAssertEqualNumber((UNITY_INT)((HAL_ERROR)), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(160), UNITY_DISPLAY_STYLE_INT);

}

void test_user_i2c_write_null_interface_pointer(void) {

    uint8_t reg_addr = 0x10;

    uint8_t reg_data[2] = {0x01, 0x02};

    uint32_t len = 2;

    void *intf_ptr = 

                    ((void *)0)

                        ;



    int8_t result = user_i2c_write(reg_addr, reg_data, len, intf_ptr);

    UnityAssertEqualNumber((UNITY_INT)((HAL_ERROR)), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(177), UNITY_DISPLAY_STYLE_INT);

}
