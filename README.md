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

  // store the read register value
  uint8_t data = 0;

  // get the chip version
  stpmic1_get_register_value(STPMIC_VERSION_SR, &data);
  
  // Enable the VBOOST regulator (5.2V fixed output)
  stpmic1_set_register_value(STPMIC_BST_SW_CR, (STPMIC_BST_SW_BST_ON_Mask));

  // Enable the PWR_USB (OTG) power switch - internally connected to boost regulator.
  stpmic1_set_register_value(STPMIC_BST_SW_CR, (STPMIC_BST_SW_BST_ON_Mask) | (STPMIC_BST_SW_VBUSOTG_ON_Mask));

  // Enable the PWR_SW power switch - J7 connected to SWIN (requires ext power source on J3).
  stpmic1_set_register_value(STPMIC_BST_SW_CR, STPMIC_BST_SW_SWOUT_ON_Mask);

  // Enable the PWR_SW power switch - J7 connected to VBOOST.
  stpmic1_set_register_value(STPMIC_BST_SW_CR, (STPMIC_BST_SW_BST_ON_Mask) | (STPMIC_BST_SW_SWOUT_ON_Mask));

  // Enable the PWR_USB (OTG) power switch - internally connected to boost regulator.
  // AND
  // Enable the PWR_SW power switch - J7 connected to SWIN (requires ext power source on J3).
  stpmic1_set_register_value(STPMIC_BST_SW_CR, (STPMIC_BST_SW_VBUSOTG_ON_Mask) | (STPMIC_BST_SW_BST_ON_Mask) | (STPMIC_BST_SW_SWOUT_ON_Mask));

  // Enable BUCK1 full 1.5V output
  stpmic1_set_register_value(STPMIC_BUCK1_MAIN_CR, ((STPMIC_BUCK1_MAIN_ENA_Mask) | (STPMIC_BUCK1_PRESET_63 << STPMIC_BUCK1_MAIN_VOUT)));

  // Enable BUCK2 full 1.5V output
  stpmic1_set_register_value(STPMIC_BUCK2_MAIN_CR, ((STPMIC_BUCK2_MAIN_ENA_Mask) | (STPMIC_BUCK2_PRESET_63 << STPMIC_BUCK2_MAIN_VOUT)));

  // Enable BUCK3 full 3.4V output
  stpmic1_set_register_value(STPMIC_BUCK3_MAIN_CR, ((STPMIC_BUCK3_MAIN_ENA_Mask) | (STPMIC_BUCK3_PRESET_63 << STPMIC_BUCK3_MAIN_VOUT)));

  // Enable BUCK4 full 3.9V output
  stpmic1_set_register_value(STPMIC_BUCK4_MAIN_CR, ((STPMIC_BUCK4_MAIN_ENA_Mask) | (STPMIC_BUCK4_PRESET_63 << STPMIC_BUCK4_MAIN_VOUT)));
  
  // Enable VREFDDR output
  stpmic1_set_register_value(STPMIC_REFDDR_MAIN_CR, STPMIC_REFDDR_MAIN_ENA_Mask);



  while(1)
  {
    // do something fun
  }
}
```
