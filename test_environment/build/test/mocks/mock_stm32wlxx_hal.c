/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_stm32wlxx_hal.h"

static const char* CMockString_DevAddress = "DevAddress";
static const char* CMockString_HAL_I2C_Master_Receive = "HAL_I2C_Master_Receive";
static const char* CMockString_HAL_I2C_Master_Transmit = "HAL_I2C_Master_Transmit";
static const char* CMockString_Size = "Size";
static const char* CMockString_Timeout = "Timeout";
static const char* CMockString_hi2c = "hi2c";
static const char* CMockString_pData = "pData";

typedef struct _CMOCK_HAL_I2C_Master_Transmit_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  HAL_StatusTypeDef ReturnVal;
  int CallOrder;
  I2C_HandleTypeDef* Expected_hi2c;
  uint16_t Expected_DevAddress;
  uint8_t* Expected_pData;
  uint16_t Expected_Size;
  uint32_t Expected_Timeout;

} CMOCK_HAL_I2C_Master_Transmit_CALL_INSTANCE;

typedef struct _CMOCK_HAL_I2C_Master_Receive_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  HAL_StatusTypeDef ReturnVal;
  int CallOrder;
  I2C_HandleTypeDef* Expected_hi2c;
  uint16_t Expected_DevAddress;
  uint8_t* Expected_pData;
  uint16_t Expected_Size;
  uint32_t Expected_Timeout;

} CMOCK_HAL_I2C_Master_Receive_CALL_INSTANCE;

static struct mock_stm32wlxx_halInstance
{
  char HAL_I2C_Master_Transmit_IgnoreBool;
  HAL_StatusTypeDef HAL_I2C_Master_Transmit_FinalReturn;
  char HAL_I2C_Master_Transmit_CallbackBool;
  CMOCK_HAL_I2C_Master_Transmit_CALLBACK HAL_I2C_Master_Transmit_CallbackFunctionPointer;
  int HAL_I2C_Master_Transmit_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE HAL_I2C_Master_Transmit_CallInstance;
  char HAL_I2C_Master_Receive_IgnoreBool;
  HAL_StatusTypeDef HAL_I2C_Master_Receive_FinalReturn;
  char HAL_I2C_Master_Receive_CallbackBool;
  CMOCK_HAL_I2C_Master_Receive_CALLBACK HAL_I2C_Master_Receive_CallbackFunctionPointer;
  int HAL_I2C_Master_Receive_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE HAL_I2C_Master_Receive_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_stm32wlxx_hal_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.HAL_I2C_Master_Transmit_CallInstance;
  if (Mock.HAL_I2C_Master_Transmit_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_HAL_I2C_Master_Transmit);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.HAL_I2C_Master_Transmit_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.HAL_I2C_Master_Receive_CallInstance;
  if (Mock.HAL_I2C_Master_Receive_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_HAL_I2C_Master_Receive);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.HAL_I2C_Master_Receive_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void mock_stm32wlxx_hal_Init(void)
{
  mock_stm32wlxx_hal_Destroy();
}

void mock_stm32wlxx_hal_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef* hi2c, uint16_t DevAddress, uint8_t* pData, uint16_t Size, uint32_t Timeout)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_HAL_I2C_Master_Transmit_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_HAL_I2C_Master_Transmit);
  cmock_call_instance = (CMOCK_HAL_I2C_Master_Transmit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.HAL_I2C_Master_Transmit_CallInstance);
  Mock.HAL_I2C_Master_Transmit_CallInstance = CMock_Guts_MemNext(Mock.HAL_I2C_Master_Transmit_CallInstance);
  if (Mock.HAL_I2C_Master_Transmit_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.HAL_I2C_Master_Transmit_FinalReturn;
    memcpy((void*)(&Mock.HAL_I2C_Master_Transmit_FinalReturn), (void*)(&cmock_call_instance->ReturnVal),
         sizeof(HAL_StatusTypeDef[sizeof(cmock_call_instance->ReturnVal) == sizeof(HAL_StatusTypeDef) ? 1 : -1])); /* add HAL_StatusTypeDef to :treat_as_array if this causes an error */
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.HAL_I2C_Master_Transmit_CallbackBool &&
      Mock.HAL_I2C_Master_Transmit_CallbackFunctionPointer != NULL)
  {
    HAL_StatusTypeDef cmock_cb_ret = Mock.HAL_I2C_Master_Transmit_CallbackFunctionPointer(hi2c, DevAddress, pData, Size, Timeout, Mock.HAL_I2C_Master_Transmit_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_HAL_I2C_Master_Transmit,CMockString_hi2c);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_hi2c), (void*)(hi2c), sizeof(I2C_HandleTypeDef), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_HAL_I2C_Master_Transmit,CMockString_DevAddress);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_DevAddress, DevAddress, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_HAL_I2C_Master_Transmit,CMockString_pData);
    if (cmock_call_instance->Expected_pData == NULL)
      { UNITY_TEST_ASSERT_NULL(pData, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(cmock_call_instance->Expected_pData, pData, 1, cmock_line, CMockStringMismatch); }
  }
  {
    UNITY_SET_DETAILS(CMockString_HAL_I2C_Master_Transmit,CMockString_Size);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_Size, Size, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_HAL_I2C_Master_Transmit,CMockString_Timeout);
    UNITY_TEST_ASSERT_EQUAL_HEX32(cmock_call_instance->Expected_Timeout, Timeout, cmock_line, CMockStringMismatch);
  }
  if (Mock.HAL_I2C_Master_Transmit_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.HAL_I2C_Master_Transmit_CallbackFunctionPointer(hi2c, DevAddress, pData, Size, Timeout, Mock.HAL_I2C_Master_Transmit_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_HAL_I2C_Master_Transmit(CMOCK_HAL_I2C_Master_Transmit_CALL_INSTANCE* cmock_call_instance, I2C_HandleTypeDef* hi2c, uint16_t DevAddress, uint8_t* pData, uint16_t Size, uint32_t Timeout);
void CMockExpectParameters_HAL_I2C_Master_Transmit(CMOCK_HAL_I2C_Master_Transmit_CALL_INSTANCE* cmock_call_instance, I2C_HandleTypeDef* hi2c, uint16_t DevAddress, uint8_t* pData, uint16_t Size, uint32_t Timeout)
{
  cmock_call_instance->Expected_hi2c = hi2c;
  cmock_call_instance->Expected_DevAddress = DevAddress;
  cmock_call_instance->Expected_pData = pData;
  cmock_call_instance->Expected_Size = Size;
  cmock_call_instance->Expected_Timeout = Timeout;
}

void HAL_I2C_Master_Transmit_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, HAL_StatusTypeDef cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_HAL_I2C_Master_Transmit_CALL_INSTANCE));
  CMOCK_HAL_I2C_Master_Transmit_CALL_INSTANCE* cmock_call_instance = (CMOCK_HAL_I2C_Master_Transmit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.HAL_I2C_Master_Transmit_CallInstance = CMock_Guts_MemChain(Mock.HAL_I2C_Master_Transmit_CallInstance, cmock_guts_index);
  Mock.HAL_I2C_Master_Transmit_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.HAL_I2C_Master_Transmit_IgnoreBool = (char)1;
}

void HAL_I2C_Master_Transmit_CMockStopIgnore(void)
{
  if(Mock.HAL_I2C_Master_Transmit_IgnoreBool)
    Mock.HAL_I2C_Master_Transmit_CallInstance = CMock_Guts_MemNext(Mock.HAL_I2C_Master_Transmit_CallInstance);
  Mock.HAL_I2C_Master_Transmit_IgnoreBool = (char)0;
}

void HAL_I2C_Master_Transmit_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, I2C_HandleTypeDef* hi2c, uint16_t DevAddress, uint8_t* pData, uint16_t Size, uint32_t Timeout, HAL_StatusTypeDef cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_HAL_I2C_Master_Transmit_CALL_INSTANCE));
  CMOCK_HAL_I2C_Master_Transmit_CALL_INSTANCE* cmock_call_instance = (CMOCK_HAL_I2C_Master_Transmit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.HAL_I2C_Master_Transmit_CallInstance = CMock_Guts_MemChain(Mock.HAL_I2C_Master_Transmit_CallInstance, cmock_guts_index);
  Mock.HAL_I2C_Master_Transmit_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_HAL_I2C_Master_Transmit(cmock_call_instance, hi2c, DevAddress, pData, Size, Timeout);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(HAL_StatusTypeDef[sizeof(cmock_to_return) == sizeof(HAL_StatusTypeDef) ? 1 : -1])); /* add HAL_StatusTypeDef to :treat_as_array if this causes an error */
}

void HAL_I2C_Master_Transmit_AddCallback(CMOCK_HAL_I2C_Master_Transmit_CALLBACK Callback)
{
  Mock.HAL_I2C_Master_Transmit_IgnoreBool = (char)0;
  Mock.HAL_I2C_Master_Transmit_CallbackBool = (char)1;
  Mock.HAL_I2C_Master_Transmit_CallbackFunctionPointer = Callback;
}

void HAL_I2C_Master_Transmit_Stub(CMOCK_HAL_I2C_Master_Transmit_CALLBACK Callback)
{
  Mock.HAL_I2C_Master_Transmit_IgnoreBool = (char)0;
  Mock.HAL_I2C_Master_Transmit_CallbackBool = (char)0;
  Mock.HAL_I2C_Master_Transmit_CallbackFunctionPointer = Callback;
}

HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef* hi2c, uint16_t DevAddress, uint8_t* pData, uint16_t Size, uint32_t Timeout)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_HAL_I2C_Master_Receive_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_HAL_I2C_Master_Receive);
  cmock_call_instance = (CMOCK_HAL_I2C_Master_Receive_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.HAL_I2C_Master_Receive_CallInstance);
  Mock.HAL_I2C_Master_Receive_CallInstance = CMock_Guts_MemNext(Mock.HAL_I2C_Master_Receive_CallInstance);
  if (Mock.HAL_I2C_Master_Receive_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.HAL_I2C_Master_Receive_FinalReturn;
    memcpy((void*)(&Mock.HAL_I2C_Master_Receive_FinalReturn), (void*)(&cmock_call_instance->ReturnVal),
         sizeof(HAL_StatusTypeDef[sizeof(cmock_call_instance->ReturnVal) == sizeof(HAL_StatusTypeDef) ? 1 : -1])); /* add HAL_StatusTypeDef to :treat_as_array if this causes an error */
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.HAL_I2C_Master_Receive_CallbackBool &&
      Mock.HAL_I2C_Master_Receive_CallbackFunctionPointer != NULL)
  {
    HAL_StatusTypeDef cmock_cb_ret = Mock.HAL_I2C_Master_Receive_CallbackFunctionPointer(hi2c, DevAddress, pData, Size, Timeout, Mock.HAL_I2C_Master_Receive_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_HAL_I2C_Master_Receive,CMockString_hi2c);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_hi2c), (void*)(hi2c), sizeof(I2C_HandleTypeDef), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_HAL_I2C_Master_Receive,CMockString_DevAddress);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_DevAddress, DevAddress, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_HAL_I2C_Master_Receive,CMockString_pData);
    if (cmock_call_instance->Expected_pData == NULL)
      { UNITY_TEST_ASSERT_NULL(pData, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(cmock_call_instance->Expected_pData, pData, 1, cmock_line, CMockStringMismatch); }
  }
  {
    UNITY_SET_DETAILS(CMockString_HAL_I2C_Master_Receive,CMockString_Size);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_Size, Size, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_HAL_I2C_Master_Receive,CMockString_Timeout);
    UNITY_TEST_ASSERT_EQUAL_HEX32(cmock_call_instance->Expected_Timeout, Timeout, cmock_line, CMockStringMismatch);
  }
  if (Mock.HAL_I2C_Master_Receive_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.HAL_I2C_Master_Receive_CallbackFunctionPointer(hi2c, DevAddress, pData, Size, Timeout, Mock.HAL_I2C_Master_Receive_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_HAL_I2C_Master_Receive(CMOCK_HAL_I2C_Master_Receive_CALL_INSTANCE* cmock_call_instance, I2C_HandleTypeDef* hi2c, uint16_t DevAddress, uint8_t* pData, uint16_t Size, uint32_t Timeout);
void CMockExpectParameters_HAL_I2C_Master_Receive(CMOCK_HAL_I2C_Master_Receive_CALL_INSTANCE* cmock_call_instance, I2C_HandleTypeDef* hi2c, uint16_t DevAddress, uint8_t* pData, uint16_t Size, uint32_t Timeout)
{
  cmock_call_instance->Expected_hi2c = hi2c;
  cmock_call_instance->Expected_DevAddress = DevAddress;
  cmock_call_instance->Expected_pData = pData;
  cmock_call_instance->Expected_Size = Size;
  cmock_call_instance->Expected_Timeout = Timeout;
}

void HAL_I2C_Master_Receive_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, HAL_StatusTypeDef cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_HAL_I2C_Master_Receive_CALL_INSTANCE));
  CMOCK_HAL_I2C_Master_Receive_CALL_INSTANCE* cmock_call_instance = (CMOCK_HAL_I2C_Master_Receive_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.HAL_I2C_Master_Receive_CallInstance = CMock_Guts_MemChain(Mock.HAL_I2C_Master_Receive_CallInstance, cmock_guts_index);
  Mock.HAL_I2C_Master_Receive_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.HAL_I2C_Master_Receive_IgnoreBool = (char)1;
}

void HAL_I2C_Master_Receive_CMockStopIgnore(void)
{
  if(Mock.HAL_I2C_Master_Receive_IgnoreBool)
    Mock.HAL_I2C_Master_Receive_CallInstance = CMock_Guts_MemNext(Mock.HAL_I2C_Master_Receive_CallInstance);
  Mock.HAL_I2C_Master_Receive_IgnoreBool = (char)0;
}

void HAL_I2C_Master_Receive_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, I2C_HandleTypeDef* hi2c, uint16_t DevAddress, uint8_t* pData, uint16_t Size, uint32_t Timeout, HAL_StatusTypeDef cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_HAL_I2C_Master_Receive_CALL_INSTANCE));
  CMOCK_HAL_I2C_Master_Receive_CALL_INSTANCE* cmock_call_instance = (CMOCK_HAL_I2C_Master_Receive_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.HAL_I2C_Master_Receive_CallInstance = CMock_Guts_MemChain(Mock.HAL_I2C_Master_Receive_CallInstance, cmock_guts_index);
  Mock.HAL_I2C_Master_Receive_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_HAL_I2C_Master_Receive(cmock_call_instance, hi2c, DevAddress, pData, Size, Timeout);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(HAL_StatusTypeDef[sizeof(cmock_to_return) == sizeof(HAL_StatusTypeDef) ? 1 : -1])); /* add HAL_StatusTypeDef to :treat_as_array if this causes an error */
}

void HAL_I2C_Master_Receive_AddCallback(CMOCK_HAL_I2C_Master_Receive_CALLBACK Callback)
{
  Mock.HAL_I2C_Master_Receive_IgnoreBool = (char)0;
  Mock.HAL_I2C_Master_Receive_CallbackBool = (char)1;
  Mock.HAL_I2C_Master_Receive_CallbackFunctionPointer = Callback;
}

void HAL_I2C_Master_Receive_Stub(CMOCK_HAL_I2C_Master_Receive_CALLBACK Callback)
{
  Mock.HAL_I2C_Master_Receive_IgnoreBool = (char)0;
  Mock.HAL_I2C_Master_Receive_CallbackBool = (char)0;
  Mock.HAL_I2C_Master_Receive_CallbackFunctionPointer = Callback;
}
