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

// Basic test to check if the environment is working
void test_config(void)
{
    // Forcefully fail the test to confirm the environment is set up correctly
    TEST_FAIL_MESSAGE("Test framework is set up");
}