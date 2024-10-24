/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_STM32WLXX_HAL_H
#define _MOCK_STM32WLXX_HAL_H

#include "unity.h"
#include "stm32wlxx_hal.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_stm32wlxx_hal_Init(void);
void mock_stm32wlxx_hal_Destroy(void);
void mock_stm32wlxx_hal_Verify(void);




#define HAL_I2C_Master_Transmit_IgnoreAndReturn(cmock_retval) HAL_I2C_Master_Transmit_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void HAL_I2C_Master_Transmit_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, HAL_StatusTypeDef cmock_to_return);
#define HAL_I2C_Master_Transmit_StopIgnore() HAL_I2C_Master_Transmit_CMockStopIgnore()
void HAL_I2C_Master_Transmit_CMockStopIgnore(void);
#define HAL_I2C_Master_Transmit_ExpectAndReturn(hi2c, DevAddress, pData, Size, Timeout, cmock_retval) HAL_I2C_Master_Transmit_CMockExpectAndReturn(__LINE__, hi2c, DevAddress, pData, Size, Timeout, cmock_retval)
void HAL_I2C_Master_Transmit_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, I2C_HandleTypeDef* hi2c, uint16_t DevAddress, uint8_t* pData, uint16_t Size, uint32_t Timeout, HAL_StatusTypeDef cmock_to_return);
typedef HAL_StatusTypeDef (* CMOCK_HAL_I2C_Master_Transmit_CALLBACK)(I2C_HandleTypeDef* hi2c, uint16_t DevAddress, uint8_t* pData, uint16_t Size, uint32_t Timeout, int cmock_num_calls);
void HAL_I2C_Master_Transmit_AddCallback(CMOCK_HAL_I2C_Master_Transmit_CALLBACK Callback);
void HAL_I2C_Master_Transmit_Stub(CMOCK_HAL_I2C_Master_Transmit_CALLBACK Callback);
#define HAL_I2C_Master_Transmit_StubWithCallback HAL_I2C_Master_Transmit_Stub
#define HAL_I2C_Master_Receive_IgnoreAndReturn(cmock_retval) HAL_I2C_Master_Receive_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void HAL_I2C_Master_Receive_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, HAL_StatusTypeDef cmock_to_return);
#define HAL_I2C_Master_Receive_StopIgnore() HAL_I2C_Master_Receive_CMockStopIgnore()
void HAL_I2C_Master_Receive_CMockStopIgnore(void);
#define HAL_I2C_Master_Receive_ExpectAndReturn(hi2c, DevAddress, pData, Size, Timeout, cmock_retval) HAL_I2C_Master_Receive_CMockExpectAndReturn(__LINE__, hi2c, DevAddress, pData, Size, Timeout, cmock_retval)
void HAL_I2C_Master_Receive_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, I2C_HandleTypeDef* hi2c, uint16_t DevAddress, uint8_t* pData, uint16_t Size, uint32_t Timeout, HAL_StatusTypeDef cmock_to_return);
typedef HAL_StatusTypeDef (* CMOCK_HAL_I2C_Master_Receive_CALLBACK)(I2C_HandleTypeDef* hi2c, uint16_t DevAddress, uint8_t* pData, uint16_t Size, uint32_t Timeout, int cmock_num_calls);
void HAL_I2C_Master_Receive_AddCallback(CMOCK_HAL_I2C_Master_Receive_CALLBACK Callback);
void HAL_I2C_Master_Receive_Stub(CMOCK_HAL_I2C_Master_Receive_CALLBACK Callback);
#define HAL_I2C_Master_Receive_StubWithCallback HAL_I2C_Master_Receive_Stub

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif