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

  // connect using this I2C interface
  stpmic1_i2c_connect(&hi2c1);

  /*
   * Get status register info
   */
  stpmic1_main_ctrl_sr();
  stpmic1_get_turn_on_sr();
  stpmic1_get_turn_off_sr();
  stpmic1_get_ocp_ldos_sr();
  stpmic1_get_ocp_buck_bsw_sr();
  stpmic1_get_restart_sr();


  /*
   * Boost regulator and load switches
   */

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

  /*
   * Buck regulator control
   */

  // Enable BUCK1 full 1.5V output
  stpmic1_set_register_value(STPMIC_BUCK1_MAIN_CR, (STPMIC_BUCK1_MAIN_ENA_Mask | STPMIC_BUCK1_PRESET_63_Mask));

  // Enable BUCK2 full 1.5V output
  stpmic1_set_register_value(STPMIC_BUCK2_MAIN_CR, (STPMIC_BUCK2_MAIN_ENA_Mask | STPMIC_BUCK2_PRESET_63_Mask));

  // Enable BUCK3 full 3.4V output
  stpmic1_set_register_value(STPMIC_BUCK3_MAIN_CR, (STPMIC_BUCK3_MAIN_ENA_Mask | STPMIC_BUCK3_PRESET_63_Mask));

  // Enable BUCK4 full 3.9V output
  stpmic1_set_register_value(STPMIC_BUCK4_MAIN_CR, (STPMIC_BUCK4_MAIN_ENA_Mask | STPMIC_BUCK4_PRESET_63_Mask));

  /*
   * LDO Control
   */

  // LDO1 enable and vout max
  stpmic1_set_register_value(STPMIC_LDO1_MAIN_CR, STPMIC_LDO1_MAIN_ENA_Mask | STPMIC_LDO1_PRESET_31_Mask);

  // LDO2 enable and vout max
  stpmic1_set_register_value(STPMIC_LDO2_MAIN_CR, STPMIC_LDO2_MAIN_ENA_Mask | STPMIC_LDO2_PRESET_31_Mask);

  // LDO3 enable and vout max
  stpmic1_set_register_value(STPMIC_LDO3_MAIN_CR, STPMIC_LDO3_MAIN_ENA_Mask | STPMIC_LDO3_PRESET_30_Mask);

  // LDO5 enable and vout max
  stpmic1_set_register_value(STPMIC_LDO5_MAIN_CR, STPMIC_LDO5_MAIN_ENA_Mask | STPMIC_LDO5_PRESET_31_Mask);

  // LDO6 enable and vout max
  stpmic1_set_register_value(STPMIC_LDO6_MAIN_CR, STPMIC_LDO6_MAIN_ENA_Mask | STPMIC_LDO6_PRESET_31_Mask);

  /*
   * VREFDDR
   */

  // Enable VREFDDR output
  stpmic1_set_register_value(STPMIC_REFDDR_MAIN_CR, STPMIC_REFDDR_MAIN_ENA_Mask);


  while(1)
  {
    // do something fun
  }
}
```
