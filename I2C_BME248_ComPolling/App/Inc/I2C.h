/*
 * I2C.h
 *
 *  Created on: Oct 19, 2024
 *      Author: eddyc
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "stm32wlxx_hal.h"
#include "logger.h"

/**
 * @brief Reads data from the I2C device at the specified register address.
 *
 * @param reg_addr The register address from which to read.
 * @param reg_data Pointer to the buffer where the read data will be stored.
 * @param len Number of bytes to read.
 * @param intf_ptr Interface pointer containing device-specific information.
 * @return int8_t Returns 0 on success, or >0 error code.
 */
int8_t user_i2c_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t len,
		void *intf_ptr);

/**
 * @brief Writes data to the I2C device at the specified register address.
 *
 * @param reg_addr The register address to which data will be written.
 * @param reg_data Pointer to the data buffer to be written.
 * @param len Number of bytes to write.
 * @param intf_ptr Interface pointer containing device-specific information.
 * @return int8_t Returns 0 on success, or >0 error code.
 */
int8_t user_i2c_write(uint8_t reg_addr, const uint8_t *reg_data, uint32_t len,
		void *intf_ptr);

#endif /* INC_I2C_H_ */
