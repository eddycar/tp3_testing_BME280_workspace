#include "unity.h"
#include "mock_stm32wlxx_hal.h"
#include "I2C.h"

I2C_HandleTypeDef hi2c1;

// This function is called before each test is executed.
// It is used to set up the environment or initialize any variables needed for the tests.
void setUp(void)
{
    // Initialization code here (if needed)
}

// This function is called after each test is executed.
// It is used to clean up or reset any variables or states modified during the test.
void tearDown(void)
{
    // Cleanup code here (if needed)
}

/**
 * @brief Test case for successful transmission and reception in user_i2c_read.
 * 
 * This function sets up the necessary parameters, mocks the HAL I2C 
 * functions to simulate a successful transmission and reception, 
 * and asserts that the result of user_i2c_read matches HAL_OK.
 */
void test_user_i2c_read_transmit_and_receive_success(void) {
    uint8_t reg_addr = 0x10;
    uint8_t reg_data[2] = {0};
    uint32_t len = 2;
    uint8_t dev_addr = 0x76;
    void *intf_ptr = &dev_addr;

    HAL_I2C_Master_Transmit_ExpectAndReturn(&hi2c1, dev_addr << 1, &reg_addr, 1, HAL_MAX_DELAY, HAL_OK);
    HAL_I2C_Master_Receive_ExpectAndReturn(&hi2c1, dev_addr << 1, reg_data, len, HAL_MAX_DELAY, HAL_OK);

    int8_t result = user_i2c_read(reg_addr, reg_data, len, intf_ptr);
    TEST_ASSERT_EQUAL(HAL_OK, result);
}

/**
 * @brief Test case for transmission error in user_i2c_read.
 * 
 * This function sets up the parameters for a read operation, 
 * mocks the HAL I2C transmission to return an error, 
 * and asserts that the result of user_i2c_read matches HAL_ERROR.
 */
void test_user_i2c_read_transmit_error(void) {
    uint8_t reg_addr = 0x10;
    uint8_t reg_data[2] = {0};
    uint32_t len = 2;
    uint8_t dev_addr = 0x76;
    void *intf_ptr = &dev_addr;

    HAL_I2C_Master_Transmit_ExpectAndReturn(&hi2c1, dev_addr << 1, &reg_addr, 1, HAL_MAX_DELAY, HAL_ERROR);
    
    int8_t result = user_i2c_read(reg_addr, reg_data, len, intf_ptr);
    TEST_ASSERT_EQUAL(HAL_ERROR, result);
}

/**
 * @brief Test case for successful transmission followed by reception failure in user_i2c_read.
 * 
 * This function simulates a successful transmission but a failure 
 * in receiving data. It asserts that user_i2c_read returns HAL_ERROR 
 * in this case.
 */
void test_user_i2c_read_transmit_success_receive_failure(void) {
    uint8_t reg_addr = 0x10;
    uint8_t reg_data[2] = {0};
    uint32_t len = 2;           
    uint8_t dev_addr = 0x76;
    void *intf_ptr = &dev_addr;  

    HAL_I2C_Master_Transmit_ExpectAndReturn(&hi2c1, dev_addr << 1, &reg_addr, 1, HAL_MAX_DELAY, HAL_OK);
    HAL_I2C_Master_Receive_ExpectAndReturn(&hi2c1, dev_addr << 1, reg_data, len, HAL_MAX_DELAY, HAL_ERROR);

    int8_t result = user_i2c_read(reg_addr, reg_data, len, intf_ptr);
    TEST_ASSERT_EQUAL(HAL_ERROR, result);
}

/**
 * @brief Test case for successful write operation in user_i2c_write.
 * 
 * This function verifies that user_i2c_write successfully transmits 
 * data when the HAL I2C transmission returns HAL_OK. 
 * It checks that the expected data is sent.
 */
void test_user_i2c_write_success(void) {
    uint8_t reg_addr = 0x10;
    uint8_t reg_data[2] = {0x01, 0x02};  
    uint32_t len = 2;                    
    uint8_t dev_addr = 0x76;            
    void *intf_ptr = &dev_addr;

    uint8_t expected_buffer[3] = {reg_addr, reg_data[0] , reg_data[1] };

    HAL_I2C_Master_Transmit_ExpectAndReturn(&hi2c1, dev_addr << 1, expected_buffer, len + 1, HAL_MAX_DELAY, HAL_OK);

    int8_t result = user_i2c_write(reg_addr, reg_data, len, intf_ptr);
    TEST_ASSERT_EQUAL(HAL_OK, result);
}

/**
 * @brief Test case for transmission error in user_i2c_write.
 * 
 * This function simulates an error during the transmission 
 * in the user_i2c_write function and checks that it returns 
 * HAL_ERROR when the HAL I2C transmission fails.
 */
void test_user_i2c_write_transmit_error(void) {
    uint8_t reg_addr = 0x10;
    const uint8_t reg_data[2] = {0x01, 0x02}; 
    uint32_t len = 2;
    uint8_t dev_addr = 0x76;   
    void *intf_ptr = &dev_addr;

    uint8_t buffer[len + 1];
    buffer[0] = reg_addr;
    memcpy(&buffer[1], reg_data, len);

    HAL_I2C_Master_Transmit_ExpectAndReturn(&hi2c1, dev_addr << 1, buffer, len + 1, HAL_MAX_DELAY, HAL_ERROR);

    int8_t result = user_i2c_write(reg_addr, reg_data, len, intf_ptr);
    TEST_ASSERT_EQUAL(HAL_ERROR, result);
}

/**
 * @brief Test case for zero-length write operation in user_i2c_write.
 * 
 * This function checks the behavior of user_i2c_write when 
 * the length of data to be written is zero, verifying 
 * that it returns HAL_ERROR.
 */
void test_user_i2c_write_zero_length(void) {
    uint8_t reg_addr = 0x10;
    const uint8_t *reg_data = NULL; 
    uint32_t len = 0;                 
    uint8_t dev_addr = 0x76;          
    void *intf_ptr = &dev_addr;

    int8_t result = user_i2c_write(reg_addr, reg_data, len, intf_ptr);
    TEST_ASSERT_EQUAL(HAL_ERROR, result);
}

/**
 * @brief Test case for null interface pointer in user_i2c_read.
 * 
 * This function verifies that user_i2c_read handles a null 
 * interface pointer gracefully and returns HAL_ERROR.
 */
void test_user_i2c_read_null_interface_pointer(void) {
    uint8_t reg_addr = 0x10;
    uint8_t reg_data[2] = {0}; 
    uint32_t len = 2;
    void *intf_ptr = NULL;     

    int8_t result = user_i2c_read(reg_addr, reg_data, len, intf_ptr);
    TEST_ASSERT_EQUAL(HAL_ERROR, result);
}

/**
 * @brief Test case for null interface pointer in user_i2c_write.
 * 
 * This function checks the behavior of user_i2c_write when 
 * the interface pointer is null, verifying that it returns 
 * HAL_ERROR.
 */
void test_user_i2c_write_null_interface_pointer(void) {
    uint8_t reg_addr = 0x10;
    uint8_t reg_data[2] = {0x01, 0x02}; 
    uint32_t len = 2;
    void *intf_ptr = NULL;              

    int8_t result = user_i2c_write(reg_addr, reg_data, len, intf_ptr);
    TEST_ASSERT_EQUAL(HAL_ERROR, result);
}