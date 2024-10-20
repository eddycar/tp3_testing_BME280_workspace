/*
 * I2C.c
 *
 *  Created on: Oct 19, 2024
 *      Author: eddyc
 */
#include "I2C.h"

extern I2C_HandleTypeDef hi2c1;

int8_t user_i2c_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t len,
		void *intf_ptr) {
	HAL_StatusTypeDef status = HAL_OK;

	uint8_t dev_addr;
	dev_addr = *((uint8_t*) intf_ptr);

	status = HAL_I2C_Master_Transmit(&hi2c1, dev_addr << 1, &reg_addr, 1,
	HAL_MAX_DELAY);
	if (status != HAL_OK) {
		return status;
	}

	status = HAL_I2C_Master_Receive(&hi2c1, dev_addr << 1, reg_data, len,
	HAL_MAX_DELAY);

	return status;
}

int8_t user_i2c_write(uint8_t reg_addr, const uint8_t *reg_data, uint32_t len,
		void *intf_ptr) {
	HAL_StatusTypeDef status = HAL_OK;

	uint8_t dev_addr;
	dev_addr = *((uint8_t*) intf_ptr);

	uint8_t buffer[len + 1];
	buffer[0] = reg_addr;
	memcpy(&buffer[1], reg_data, len);

	if (HAL_I2C_Master_Transmit(&hi2c1, dev_addr << 1, buffer, len + 1,
	HAL_MAX_DELAY) != HAL_OK) {
		status = HAL_ERROR;
	}

	return status;
}

