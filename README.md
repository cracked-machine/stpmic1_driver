### STPMIC1 Driver for STM32 Microcontrollers

https://www.st.com/resource/en/datasheet/stpmic1.pdf

Abridged example. Use CubeIDE/CubeMX to setup your project.

```
#include <stpmic1.h>

// Redirect stdout to ITM/SWO
int _write(int file, char *ptr, int len)
{
	for (int i=0; i<len; i++)
	{
		ITM_SendChar((*ptr++));
	}
	return len;
}

int main(void)
{

  HAL_Init();
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();

  // setup the driver
  stpmic1_i2c_connect(&hi2c1);

  // store the read register values
  uint8_t data = 0;

  // get the chip version
  stpmic1_get_register_value(STPMIC_VERSION_SR, &data);
  
  // set the BUCK regulators voltage output to maximum value
  stpmic1_set_register_value(STPMIC_LDO1_MAIN_CR, STPMIC_LDO1_PRESET_31);	// 3.3V
  stpmic1_set_register_value(STPMIC_LDO2_MAIN_CR, STPMIC_LDO2_PRESET_31);	// 3.3V
  stpmic1_set_register_value(STPMIC_LDO5_MAIN_CR, STPMIC_LDO5_PRESET_31);	// 3.9V
  stpmic1_set_register_value(STPMIC_LDO6_MAIN_CR, STPMIC_LDO6_PRESET_31);	// 3.3V

  // set the LDO regulators voltage output to maximum values
  stpmic1_set_register_value(STPMIC_BUCK1_MAIN_CR, STPMIC_BUCK1_PRESET_63);	// 1.5V
  stpmic1_set_register_value(STPMIC_BUCK2_MAIN_CR, STPMIC_BUCK2_PRESET_63);	// 1.5V
  stpmic1_set_register_value(STPMIC_BUCK3_MAIN_CR, STPMIC_BUCK3_PRESET_63);	// 3.9V
  stpmic1_set_register_value(STPMIC_BUCK4_MAIN_CR, STPMIC_BUCK4_PRESET_63);	// 3.9V

  while(1)
  {
    // do something fun
  }
}
```
