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
 *	@brief 		This scans the I2C bus and uses the first device that returns an ACK.
 *
 *	@param 		hi2c The I2C peripheral to use
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
 *	@brief 		This gets the checks the Operating Mode of the RESTART_SR status register
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
 *	@brief 		Performs I2C read operation on STPMIC
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
 *	@brief 		Performs a I2C write operation on the STPMIC
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
 *	@brief		Prints the TURN_ON_SR bits that are set
 *
 *	@param 		None
 *
 *	@retval 	returns TURN_ON_SR data register byte
 *
 */
uint8_t stpmic1_get_turn_on_sr()
{
	uint8_t data = 0;
	stpmic1_get_register_value(STPMIC_TURN_ON_SR, &data);
	if(data & STPMIC_TURN_ON_PKEY_Mask)
		printf("TURN_ON_PKEY: Last Turn-ON condition was due to PONKEYn detection\n");
	if(data & STPMIC_TURN_ON_WKUP_Mask)
		printf("TURN_ON_WKUP: Last Turn-ON condition was due to WAKEUP pin detection\n");
	if(data & STPMIC_TURN_ON_VBUS_Mask)
		printf("TURN_ON_VBUS:  Last Turn-ON condition was due to VBUS detection on VBUSOTG pin\n");
	if(data & STPMIC_TURN_ON_SWOUT_Mask)
		printf("TURN_ON_SWOUT: Last Turn-ON condition was VBUS due to detection on SWOUT pin\n");
	if(data & STPMIC_TURN_ON_AUTO_Mask)
		printf("TURN_ON_AUTOR: STPMIC1 has automatically turned ON on due to VIN rising.\n");

	return data;
}

/*
 *	@brief		Prints the TURN_OFF_SR bits that are set
 *
 *	@param 		None
 *
 *	@retval 	returns TURN_OFF_SR data register byte
 *
 */
uint8_t stpmic1_get_turn_off_sr()
{
	uint8_t data = 0;
	stpmic1_get_register_value(STPMIC_TURN_OFF_SR, &data);
	if(data & STPMIC_TURN_OFF_SWOFF_Mask)
		printf("TURN_OFF_SWOFF: Last turn-OFF condition was due to software switch OFF\n");
	if(data & STPMIC_TURN_OFF_VINOK_FA_Mask)
		printf("TURN_OFF_VINOK_FA: Last turn-OFF condition was due to VIN below VINOK_Fal\n");
	if(data & STPMIC_TURN_OFF_THSD_Mask)
		printf("TURN_OFF_THSD: Last turn-OFF condition was due to thermal shutdown\n");
	if(data & STPMIC_TURN_OFF_OCP_Mask)
		printf("TURN_OFF_OCP: Last turn-ON condition was due to overcurrent protection\n");
	if(data & STPMIC_TURN_OFF_WDG_Mask)
		printf("TURN_OFF_WDG: Last turn-OFF condition was due to watchdog\n");
	if(data & STPMIC_TURN_OFF_PKEYLKP_Mask)
		printf("TURN_OFF_PKEYLKP: Last turn-OFF condition was due to PONKEYn long key\n");

	return data;
}

/*
 *	@brief		Prints the OCP_LDOS_SR bits that are set
 *
 *	@param 		None
 *
 *	@retval 	returns OCP_LDOS_SR data register byte
 *
 */
uint8_t stpmic1_get_ocp_ldos_sr()
{
	uint8_t data = 0;
	stpmic1_get_register_value(STPMIC_OCP_LDOS_SR, &data);
	if(data & STPMIC_OCP_LDOS_OCP_LDO1_Mask)
		printf("OCP_LDOS_OCP_LDO1: Last turn-OFF was due to overcurrent protection on LDO1\n");
	if(data & STPMIC_OCP_LDOS_OCP_LDO2_Mask)
		printf("OCP_LDOS_OCP_LDO2: Last turn-OFF was due to overcurrent protection on LDO2\n");
	if(data & STPMIC_OCP_LDOS_OCP_LDO3_Mask)
		printf("OCP_LDOS_OCP_LDO3: Last turn-OFF was due to overcurrent protection on LDO3\n");
	if(data & STPMIC_OCP_LDOS_OCP_LDO4_Mask)
		printf("OCP_LDOS_OCP_LDO4: Last turn-OFF was due to overcurrent protection on LDO4\n");
	if(data & STPMIC_OCP_LDOS_OCP_LDO5_Mask)
		printf("OCP_LDOS_OCP_LDO5: Last turn-OFF was due to overcurrent protection on LDO5\n");
	if(data & STPMIC_OCP_LDOS_OCP_LDO6_Mask)
		printf("OCP_LDOS_OCP_LDO6: Last turn-OFF was due to overcurrent protection on LDO6\n");

	return data;
}

/*
 *	@brief		Prints the OCP_BUCKS_BSW_SR that are set
 *
 *	@param 		None
 *
 *	@retval 	returns OCP_BUCKS_BSW_SR data register byte
 *
 */
uint8_t stpmic1_get_ocp_buck_bsw_sr()
{
	uint8_t data = 0;
	stpmic1_get_register_value(STPMIC_OCP_BUCKS_BSW_SR, &data);
	if(data & STPMIC_OCP_BUCKS_BSW_OCP_BUCK1_Mask)
		printf("OCP_BUCKS_BSW_OCP_BUCK1: Last turn-OFF was due to overcurrent protection on BUCK1\n");
	if(data & STPMIC_OCP_BUCKS_BSW_OCP_BUCK2_Mask)
		printf("OCP_BUCKS_BSW_OCP_BUCK2: Last turn-OFF was due to overcurrent protection on BUCK2\n");
	if(data & STPMIC_OCP_BUCKS_BSW_OCP_BUCK3_Mask)
		printf("OCP_BUCKS_BSW_OCP_BUCK3: Last turn-OFF was due to overcurrent protection on BUCK3\n");
	if(data & STPMIC_OCP_BUCKS_BSW_OCP_BUCK4_Mask)
		printf("OCP_BUCKS_BSW_OCP_BUCK4: Last turn-OFF was due to overcurrent protection on BUCK4\n");
	if(data & STPMIC_OCP_BUCKS_BSW_OCP_VBUSOTG_Mask)
		printf("OCP_BUCKS_BSW_OCP_VBUSOTG: Last turn-OFF was due to overcurrent protection on VBUSOTG\n");
	if(data & STPMIC_OCP_BUCKS_BSW_OCP_SWOUT_Mask)
		printf("OCP_BUCKS_BSW_OCP_SWOUT: Last turn-OFF was due to overcurrent protection on SWOUT\n");
	if(data & STPMIC_OCP_BUCKS_BSW_OCP_BOOST_Mask)
		printf("OCP_BUCKS_BSW_OCP_BOOST: Last turn-OFF was due to overcurrent protection on BOOST\n");

	return data;
}

/*
 *	@brief		Prints the RESTART_SR bits that are set
 *
 *	@param 		None
 *
 *	@retval 	returns RESTART_SR data register byte
 *
 */
uint8_t stpmic1_get_restart_sr()
{
	uint8_t data = 0;
	stpmic1_get_register_value(STPMIC_RESTART_SR, &data);
	if(data & STPMIC_RESTART_R_RST_Mask)
		printf("RESTART_R_RST: Restart is due to RSTn signal asserted by application processor\n");
	if(data & STPMIC_RESTART_R_SWOFF_Mask)
		printf("RESTART_R_SWOFF: Restart is due to SWOFF turn-OFF condition while RREQ_EN bit is set\n");
	if(data & STPMIC_RESTART_R_WDG_Mask)
		printf("RESTART_R_WDG: Restart is due to watchdog turn-OFF condition while RREQ_EN bit is set\n");
	if(data & STPMIC_RESTART_R_PKEYLKP_Mask)
		printf("RESTART_R_PKEYLKP: Restart is due to PONKEYn long key press turn- OFF condition while RREQ_EN bit is set\n");
	if(data & STPMIC_RESTART_R_VINOK_FA_Mask)
		printf("RESTART_R_VINOK_FA: Restart is due to VINOK_Fall turn-OFF condition while RREQ_EN bit is set\n");

	if(data == STPMIC_RESTART_LDO4_SRC_OFF_Mask)
		printf("RESTART_LDO4_SRC: Disabled\n");
	if(data & STPMIC_RESTART_LDO4_SRC_VIN_Mask)
		printf("RESTART_LDO4_SRC: VIN\n");
	if(data & STPMIC_RESTART_LDO4_SRC_VBUSOTG_Mask)
		printf("RESTART_LDO4_SRC: VBUSOTG \n");
	if(data & STPMIC_RESTART_LDO4_SRC_BSTOUT_Mask)
		printf("RESTART_LDO4_SRC: BSTOUT\n");

	if(data & STPMIC_RESTART_OP_MODE_Mask)
		printf("RESTART_OP_MODE: Alternate mode enabled.\n");
	else
		printf("RESTART_OP_MODE: Main mode enabled.\n");

	return data;
}

/*
 *	@brief		Prints the MAIN_CR bits that are set
 *
 *	@param 		None
 *
 *	@retval 	returns MAIN_CR data register byte
 *
 */
uint8_t stpmic1_main_ctrl_sr()
{
	uint8_t data = 0;
	stpmic1_get_register_value(STPMIC_MAIN_CR, &data);
	if(data & STPMIC_MAIN_SWOFF_Mask)
		printf("MAIN_SWOFF: Software switch OFF bit requested\n");	// unlikely to poll this register bit before power down occurs

	if(data & STPMIC_MAIN_RREQ_EN_Mask)
		printf("MAIN_RREQ_EN: Power cycling is performed on turn-OFF condition and on RSTn assertion by the application processor.\n");
	else
		printf("MAIN_RREQ_EN: Power cycling is performed only on RSTn assertion by the application process.\n");

	if(data & STPMIC_MAIN_PWRCTRL_EN_Mask)
		printf("MAIN_PWRCTRL_EN: PWRCTRL disabled.\n");
	else
		printf("MAIN_PWRCTRL_EN: PWRCTRL enabled.\n");

	if(data & STPMIC_MAIN_PWRCTRL_POL_Mask)
		printf("MAIN_PWRCTRL_POL:  PWRCTRL active high.\n");
	else
		printf("MAIN_PWRCTRL_POL: PWRCTROL active low.\n");


	if(data & STPMIC_MAIN_OCP_OFF_DBG_Mask)
		printf("MAIN_OCP_OFF_DBG: OCP turn-OFF event is generated.\n");
	else
		printf("MAIN_OCP_OFF_DBG: OCP event is generated based on flags from regulators.\n");


	return data;
}

/*
 *
 *	@brief 		Convenience function to pretty print the HAL API function status
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
