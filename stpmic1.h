/*
 * 		stpmic1.h
 *
 *  	Created on: Mar 28, 2021
 *      Author: Chris Sutton
 *
 *      STPMIC1 Driver for STM32 Microcontrollers
 *      https://www.st.com/resource/en/datasheet/stpmic1.pdf
 *
 *      MIT License
 *
 * 		Copyright (c) [2021] [Chris Sutton]
 *
 * 		Permission is hereby granted, free of charge, to any person obtaining a copy
 * 		of this software and associated documentation files (the "Software"), to deal
 * 		in the Software without restriction, including without limitation the rights
 * 		to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * 		copies of the Software, and to permit persons to whom the Software is
 * 		furnished to do so, subject to the following conditions:
 *
 * 		The above copyright notice and this permission notice shall be included in all
 * 		copies or substantial portions of the Software.
 *
 * 		THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * 		IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * 		FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * 		AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * 		LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * 		OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * 		SOFTWARE.
 *
 */

#ifndef STPMIC1_DRIVER_STPMIC1_H_
#define STPMIC1_DRIVER_STPMIC1_H_

#include <stdint.h>
#include <stdio.h>

// Change this to match your STM32 target
#include "stm32g4xx_hal.h"

// STPMIC1 register mappings
#include "stpmic1_def.h"

// the I2C bus to use
I2C_HandleTypeDef *stpmic1_i2c;

// the I2C device address to use
uint16_t stpmic1_dev_addr;

int stpmic1_i2c_connect(I2C_HandleTypeDef *hi2c);

void stpmic1_print_hal_status(HAL_StatusTypeDef res, char* msg);

int stpmic1_getversion(uint8_t *data);

int stpmic1_get_register_value(uint8_t reg, uint8_t *data_out);

int stpmic1_set_register_value(uint8_t reg, uint8_t data_in);

uint8_t stpmic1_get_turn_on_sr();
uint8_t stpmic1_get_turn_off_sr();
uint8_t stpmic1_get_ocp_ldos_sr();
uint8_t stpmic1_get_ocp_buck_bsw_sr();
uint8_t stpmic1_get_restart_sr();
uint8_t stpmic1_main_ctrl_sr();

#endif /* STPMIC1_DRIVER_STPMIC1_H_ */
