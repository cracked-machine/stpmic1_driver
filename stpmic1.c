/*
 * 		stpmic1.c
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
#include <stpmic1.h>

// prototypes
void stpmic1_check_mode();
int stpmic1_i2c_connect(I2C_HandleTypeDef *hi2c);
int stpmic1_get_register_value(uint8_t reg, uint8_t *data_out);
void stpmic1_print_hal_status(HAL_StatusTypeDef res, char* msg);

/*
 *
 *	@brief This scans the I2C bus and uses the first device that returns an ACK.
 *
 *	@param hi2c The I2C peripheral to use
 *	@retval 	 0 - Device found on I2C bus
 *				-1 - No devices found on I2C bus
 *
 */
int stpmic1_i2c_connect(I2C_HandleTypeDef *hi2c) {

	stpmic1_i2c = hi2c;

	//printf("Using I2C Bus at 0x%02X\n", stpmic1_i2c->Instance);
    printf("Scanning I2C bus...\n");
    char msg[64];
    int DeviceFound=0;
    //char notFound[160];
    HAL_StatusTypeDef res;
    for(uint16_t i = 0; i < 128; i++) {
        res = HAL_I2C_IsDeviceReady(stpmic1_i2c, i << 1, 1, 10);
        if(res == HAL_OK) {

            snprintf(msg, sizeof(msg), "0x%02X", i);
            printf("Found %s\n", msg);
            stpmic1_print_hal_status(res, "");
            DeviceFound=1;
            stpmic1_dev_addr = i;
            //ssd1306_SetI2CAddress(i);

            stpmic1_check_mode();
            return 0;
        }
    }
    if(!DeviceFound)
    {
    	stpmic1_print_hal_status(res, "No device found: ");
    	return -1;
    }
    return -1;
}

/*
 *
 *	@brief This gets the checks the Operating Mode of the RESTART_SR status register
 *
 *	@param 		None
 *	@retval 	None
 *
 */
void stpmic1_check_mode()
{
	uint8_t data = 0;
	stpmic1_get_register_value(STPMIC_RESTART_SR, &data);

	if(data & (1U << 0x07))
		printf("Alternate Mode enabled\n");
	else
		printf("Main Mode enabled\n");
}

/*
 *
 *	@brief Performs I2C read operation on STPMIC
 *
 *	@param 		uint8_t reg 		- The register to read from
 *				uint8_t *data_out	- The buffer into which the data will be read
 *	@retval 	 0 	- 	Successful I2C read operation
 *				-1 	-	Failed I2C read operation
 *
 */
int stpmic1_get_register_value(uint8_t reg, uint8_t *data_out	)
{
	  HAL_StatusTypeDef res;
	  printf("\n");
	  printf("STPMIC1 GetRegister: 0x%02X\n", reg);
	  printf("---------------------------\n");

	  if(stpmic1_dev_addr != 0)
	  {

		  res = HAL_I2C_Master_Transmit(stpmic1_i2c, stpmic1_dev_addr << 1, &reg, 1, 1);
		  stpmic1_print_hal_status(res, "Request=");
	  }
	  else
	  {
		  return -1;
	  }

	  if(res == HAL_OK)
	  {
		  res = HAL_I2C_Master_Receive(stpmic1_i2c, stpmic1_dev_addr << 1, data_out, 1, 1);
		  stpmic1_print_hal_status(res, "Read=");
		  printf("Read Data=0x%02X\n", *data_out);

	  }
	  else
	  {
		  return -1;
	  }

	  return 0;
}

/*
 *
 *	@brief Performs a I2C write operation on the STPMIC
 *
 *	@param 		uint8_t reg 		- The register to write to
 *				uint8_t *data_out	- The buffer from which the data will be written
 *	@retval 	 0 	- 	Successful I2C write operation
 *				-1 	-	Failed I2C write operation
 *
 */
int stpmic1_set_register_value(uint8_t reg, uint8_t data_in)
{
	  HAL_StatusTypeDef res;
	  printf("\n");
	  printf("STPMIC1 SetRegister: 0x%02X\n", reg);
	  printf("---------------------------\n");

	  uint8_t write_data[2];
	  write_data[0] = reg;
	  write_data[1] = data_in;

	  if(stpmic1_dev_addr != 0)
	  {

		  res = HAL_I2C_Master_Transmit(stpmic1_i2c, stpmic1_dev_addr << 1, write_data, 2, 1);
		  stpmic1_print_hal_status(res, "Request=");
	  }
	  else
	  {
		  return -1;
	  }

	  return 0;
}

/*
 *
 *	@brief Convenience function to pretty print the HAL API function status
 *
 *	@param 		HAL_StatusTypeDef res 	- The STM HAL API status
 *				char* msg				- Additional user text to add to the message
 *	@retval 	None
 *
 */
void stpmic1_print_hal_status(HAL_StatusTypeDef res, char* msg)
{
	  switch(res)
	  {
		  case HAL_OK:
			  printf("%sHAL_OK\n", msg);
			  break;
		  case HAL_ERROR:
			  printf("%sHAL_ERROR\n", msg);
			  break;
		  case HAL_BUSY:
			  printf("%sHAL_BUSY\n", msg);
			  break;
		  case HAL_TIMEOUT:
			  printf("%sHAL_TIMEOUT\n", msg);
			  break;
	  }
}
