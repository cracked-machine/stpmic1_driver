/*
 * 		stpmic1_def.h
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

#ifndef STPMIC1_DRIVER_STPMIC1_DEF_H_
#define STPMIC1_DRIVER_STPMIC1_DEF_H_


//	STPMIC_TURN_ON_SR - Turn-ON status register
//
#define STPMIC_TURN_ON_SR			0x01	//Turn-ON status base address
#define STPMIC_TURN_ON_PKEY			0U		//last Turn-ON condition was PONKEYn detection
#define STPMIC_TURN_ON_WKUP			1U		//last Turn-ON condition was WAKEUP pin detection
#define STPMIC_TURN_ON_VBUS			2U		//last Turn-ON condition was VBUS detection on VBUSOTG pin
#define STPMIC_TURN_ON_SWOUT		3U		//last Turn-ON condition was VBUS detection on SWOUT pin.
#define STPMIC_TURN_ON_AUTO			4U		//STPMIC1 has automatically turned ON on VIN rising.

//	STPMIC_TURN_OFF_SR - Turn-OFF status register
//
#define STPMIC_TURN_OFF_SR			0x02	//Turn-OFF status base address
#define STPMIC_TURN_OFF_SWOFF		0U		//Last turn-OFF condition was due to software switch OFF
#define STPMIC_TURN_OFF_VINOK_FA	1U		//Last turn-OFF condition was due to VIN below VINOK_Fall
#define STPMIC_TURN_OFF_THSD		2U		//Last turn-OFF condition was due to thermal shutdown
#define STPMIC_TURN_OFF_OSC			3U		//Last turn-ON condition was due to overcurrent protection
#define STPMIC_TURN_OFF_WDG			4U		//Last turn-OFF condition was due to watchdog
#define STPMIC_TURN_OFF_PKEYLKP		5U		//Last turn-OFF condition was due to PONKEYn long key

//	STPMIC_OCP_LDOS_SR - Overcurrent protection LDO turn-OFF status register
//
#define	STPMIC_OCP_LDOS_SR			0x03	//Overcurrent protection LDO turn-OFF status register
#define	STPMIC_OCP_LDOS_OCP_LDO1	0U		//Last turn-OFF was due to overcurrent protection on LDO1
#define	STPMIC_OCP_LDOS_OCP_LDO2	1U		//Last turn-OFF was due to overcurrent protection on LDO2
#define	STPMIC_OCP_LDOS_OCP_LDO3	2U		//Last turn-OFF was due to overcurrent protection on LDO3
#define	STPMIC_OCP_LDOS_OCP_LDO4	3U		//Last turn-OFF was due to overcurrent protection on LDO4
#define	STPMIC_OCP_LDOS_OCP_LDO5	4U		//Last turn-OFF was due to overcurrent protection on LDO5
#define	STPMIC_OCP_LDOS_OCP_LDO6	5U		//Last turn-OFF was due to overcurrent protection on LDO6

// STPMIC_OCP_BUCKS_BSW_SR - Overcurrent protection buck turn-OFF status register
//
#define STPMIC_OCP_BUCKS_BSW_SR 			0x04	//Overcurrent protection buck turn-OFF status register
#define STPMIC_OCP_BUCKS_BSW_OCP_BUCK1		0U		//Last turn-OFF was due to overcurrent protection on BUCK1
#define STPMIC_OCP_BUCKS_BSW_OCP_BUCK2		1U		//Last turn-OFF was due to overcurrent protection on BUCK2
#define STPMIC_OCP_BUCKS_BSW_OCP_BUCK3		2U		//Last turn-OFF was due to overcurrent protection on BUCK3
#define STPMIC_OCP_BUCKS_BSW_OCP_BUCK4		3U		//Last turn-OFF was due to overcurrent protection on BUCK4
#define STPMIC_OCP_BUCKS_BSW_OCP_VBUSOTG	4U		//Last turn-OFF was due to overcurrent protection on VBUSTOTG pin (PWR_USB_SW out)
#define STPMIC_OCP_BUCKS_BSW_OCP_SWOUT		5U  	//Last turn-OFF was due to overcurrent protection on SWOUT pin (PWR_SW out)
#define STPMIC_OCP_BUCKS_BSW_OCP_BOOST  	6U		//Last turn-OFF was due to overcurrent protection on BOOST


// STPMIC_RESTART_SR - Restart status register
//
#define STPMIC_RESTART_SR			0x04	//Restart status register
#define STPMIC_RESTART_R_RST		0U		//Restart is due to RSTn signal asserted by application processor
#define STPMIC_RESTART_R_SWOFF		1U		//Restart is due to SWOFF turn-OFF condition while RREQ_EN bit is set
#define STPMIC_RESTART_R_WDG		2U		//Restart is due to watchdog turn-OFF condition while RREQ_EN bit is set
#define STPMIC_RESTART_R_PKEYLKP	3U		//Restart is due to PONKEYn long key press turn- OFF condition while RREQ_EN bit is set
#define STPMIC_RESTART_R_VINOK_FA	4U		//Restart is due to VINOK_Fall turn-OFF condition while RREQ_EN bit is set
#define STPMIC_RESTART_LDO4_SRC		5U		//LDO4 input source. Provides status of LDO4 input switch selection
#define STPMIC_RESTART_OP_MODE		7U		//Operating mode. Signal if the STPMIC1 is in MAIN mode or ALTERNATE mode.

// STPMIC_VERSION_SR - Version status register
//
#define STPMIC_VERSION_SR 				0x06	//Version status register
#define STPMIC_VERSION_MINOR_VERSION	0U
#define STPMIC_VERSION_MAJOR_VERSION	4U

// STPMIC_MAIN_CR - Main control register
//
#define STPMIC_MAIN_CR				0x10	//Main control register
#define STPMIC_MAIN_SWOFF			0U		//Software switch OFF bit
#define STPMIC_MAIN_RREQ_EN   		1U		//allows power cycling on turn-OFF condition
#define STPMIC_MAIN_PWRCTRL_EN  	2U		//enable PWRCTRL functionality
#define STPMIC_MAIN_PWRCTRL_POL 	3U   	//specifies PWRCTRL pin polarity
#define STPMIC_MAIN_OCP_OFF_DBG 	4U		//Used as software debug bit to emulate OCP turn-OFF event generation.

//TODO
#define STPMIC_PADS_PULL_CR			0x11	//Pads pull control register
#define STPMIC_BUCKS_PD_CR			0x12	//Bucks pull-down control register
#define STPMIC_LDO14_PD_CR			0x13	//LDO1-4 pull-down control register

// STPMIC_SW_VIN_CR - PWR_SWOUT and VIN control register
//
#define STPMIC_SW_VIN_CR			0x15	//PWR_SWOUT and VIN control register
#define STPMIC_SW_VIN_VINLOW_MON	0U		//VINLOW monitoring enable bi
#define STPMIC_SW_VIN_VINLOW_TRESH 	1U		//VINLOW threshold offset
#define STPMIC_SW_VIN_VINLOW_HYST	4U		//VINLOW threshold hysteresis
#define STPMIC_SW_VIN_SWOUT_DET_DIS	6U		//SWOUT detection disable control bit
#define STPMIC_SW_VIN_SWIN_DET_EN	7U		//SWIN detection enable control bit

// STPMIC_BUCK1_MAIN_CR - BUCK1 MAIN mode control registers
//
#define STPMIC_BUCK1_MAIN_CR			0x20	//BUCK1 MAIN mode control register
#define STPMIC_BUCK1_MAIN_ENA			0U		//Buck enable bit
#define STPMIC_BUCK1_MAIN_PREG_MODE		1U		//Select high power or low power regulation mode
#define STPMIC_BUCK1_MAIN_VOUT			2U		//Buck output voltage setting.

// Buck1 VOUT Register Presets
//
#define STPMIC_BUCK1_PRESET_0		0x00	// 0.725V
#define STPMIC_BUCK1_PRESET_1		0x01	// 0.725V
#define STPMIC_BUCK1_PRESET_2		0x02	// 0.725V
#define STPMIC_BUCK1_PRESET_3		0x03	// 0.725V
#define STPMIC_BUCK1_PRESET_4		0x04	// 0.725V
#define STPMIC_BUCK1_PRESET_5		0x05	// 0.725V
#define STPMIC_BUCK1_PRESET_6		0x06	// 0.75V
#define STPMIC_BUCK1_PRESET_7		0x07	// 0.775V
#define STPMIC_BUCK1_PRESET_8		0x08	// 0.8V
#define STPMIC_BUCK1_PRESET_9		0x09	// 0.825V
#define STPMIC_BUCK1_PRESET_10		0x0A	// 0.85V
#define STPMIC_BUCK1_PRESET_11		0x0B	// 0.875V
#define STPMIC_BUCK1_PRESET_12		0x0C	// 0.9V
#define STPMIC_BUCK1_PRESET_13		0x0D	// 0.925V
#define STPMIC_BUCK1_PRESET_14		0x0E	// 0.95V
#define STPMIC_BUCK1_PRESET_15		0x0F	// 0.975V
#define STPMIC_BUCK1_PRESET_16		0x10	// 1V
#define STPMIC_BUCK1_PRESET_17		0x11	// 1.025V
#define STPMIC_BUCK1_PRESET_18		0x12	// 1.05V
#define STPMIC_BUCK1_PRESET_19		0x13	// 1.075V
#define STPMIC_BUCK1_PRESET_20		0x14	// 1.1V
#define STPMIC_BUCK1_PRESET_21		0x15	// 1.125V
#define STPMIC_BUCK1_PRESET_22		0x16	// 1.15V
#define STPMIC_BUCK1_PRESET_23		0x17	// 1.175V
#define STPMIC_BUCK1_PRESET_24		0x18	// 1.25V
#define STPMIC_BUCK1_PRESET_25		0x19	// 1.225V
#define STPMIC_BUCK1_PRESET_26		0x1A	// 1.25V
#define STPMIC_BUCK1_PRESET_27		0x1B	// 1.275V
#define STPMIC_BUCK1_PRESET_28		0x1C	// 1.3V
#define STPMIC_BUCK1_PRESET_29		0x1D	// 1.325V
#define STPMIC_BUCK1_PRESET_30		0x1E	// 1.35V
#define STPMIC_BUCK1_PRESET_31		0x1F	// 1.375V
#define STPMIC_BUCK1_PRESET_32		0x20	// 1.4V
#define STPMIC_BUCK1_PRESET_33		0x21	// 1.425V
#define STPMIC_BUCK1_PRESET_34		0x22	// 1.45V
#define STPMIC_BUCK1_PRESET_35		0x23	// 1.475V
#define STPMIC_BUCK1_PRESET_36		0x24	// 1.5V
#define STPMIC_BUCK1_PRESET_37		0x25	// 1.5V
#define STPMIC_BUCK1_PRESET_38		0x26	// 1.5V
#define STPMIC_BUCK1_PRESET_39		0x27	// 1.5V
#define STPMIC_BUCK1_PRESET_40		0x28	// 1.5V
#define STPMIC_BUCK1_PRESET_41		0x29	// 1.5V
#define STPMIC_BUCK1_PRESET_42		0x2A	// 1.5V
#define STPMIC_BUCK1_PRESET_43		0x2B	// 1.5V
#define STPMIC_BUCK1_PRESET_44		0x2C	// 1.5V
#define STPMIC_BUCK1_PRESET_45		0x2D	// 1.5V
#define STPMIC_BUCK1_PRESET_46		0x2E	// 1.5V
#define STPMIC_BUCK1_PRESET_47		0x2F	// 1.5V
#define STPMIC_BUCK1_PRESET_48		0x30	// 1.5V
#define STPMIC_BUCK1_PRESET_49		0x31	// 1.5V
#define STPMIC_BUCK1_PRESET_50		0x32	// 1.5V
#define STPMIC_BUCK1_PRESET_51		0x33	// 1.5V
#define STPMIC_BUCK1_PRESET_52		0x34	// 1.5V
#define STPMIC_BUCK1_PRESET_53		0x35	// 1.5V
#define STPMIC_BUCK1_PRESET_54		0x36	// 1.5V
#define STPMIC_BUCK1_PRESET_55		0x37	// 1.5V
#define STPMIC_BUCK1_PRESET_56		0x38	// 1.5V
#define STPMIC_BUCK1_PRESET_57		0x39	// 1.5V
#define STPMIC_BUCK1_PRESET_58		0x3A	// 1.5V
#define STPMIC_BUCK1_PRESET_59		0x3B	// 1.5V
#define STPMIC_BUCK1_PRESET_60		0x3C	// 1.5V
#define STPMIC_BUCK1_PRESET_61		0x3D	// 1.5V
#define STPMIC_BUCK1_PRESET_62		0x3E	// 1.5V
#define STPMIC_BUCK1_PRESET_63		0x3F	// 1.5V

// STPMIC_BUCK2_MAIN_CR - BUCK2 MAIN mode control register
//
#define STPMIC_BUCK2_MAIN_CR			0x21	//BUCK2 MAIN mode control register
#define STPMIC_BUCK2_MAIN_ENA			0U		//Buck enable bit
#define STPMIC_BUCK2_MAIN_PREG_MODE		1U		//Select high power or low power regulation mode
#define STPMIC_BUCK2_MAIN_VOUT			2U		//Buck output voltage setting.

#define STPMIC_BUCK2_PRESET_0		0x00	// 1V
#define STPMIC_BUCK2_PRESET_1		0x01	// 1V
#define STPMIC_BUCK2_PRESET_2		0x02	// 1V
#define STPMIC_BUCK2_PRESET_3		0x03	// 1V
#define STPMIC_BUCK2_PRESET_4		0x04	// 1V
#define STPMIC_BUCK2_PRESET_5		0x05	// 1V
#define STPMIC_BUCK2_PRESET_6		0x06	// 1V
#define STPMIC_BUCK2_PRESET_7		0x07	// 1V
#define STPMIC_BUCK2_PRESET_8		0x08	// 1V
#define STPMIC_BUCK2_PRESET_9		0x09	// 1V
#define STPMIC_BUCK2_PRESET_10		0x0A	// 1V
#define STPMIC_BUCK2_PRESET_11		0x0B	// 1V
#define STPMIC_BUCK2_PRESET_12		0x0C	// 1V
#define STPMIC_BUCK2_PRESET_13		0x0D	// 1V
#define STPMIC_BUCK2_PRESET_14		0x0E	// 1V
#define STPMIC_BUCK2_PRESET_15		0x0F	// 1V
#define STPMIC_BUCK2_PRESET_16		0x10	// 1V
#define STPMIC_BUCK2_PRESET_17		0x11	// 1V
#define STPMIC_BUCK2_PRESET_18		0x12	// 1.05V
#define STPMIC_BUCK2_PRESET_19		0x13	// 1.05V
#define STPMIC_BUCK2_PRESET_20		0x14	// 1.1V
#define STPMIC_BUCK2_PRESET_21		0x15	// 1.1V
#define STPMIC_BUCK2_PRESET_22		0x16	// 1.15V
#define STPMIC_BUCK2_PRESET_23		0x17	// 1.15V
#define STPMIC_BUCK2_PRESET_24		0x18	// 1.2V
#define STPMIC_BUCK2_PRESET_25		0x19	// 1.2V
#define STPMIC_BUCK2_PRESET_26		0x1A	// 1.25V
#define STPMIC_BUCK2_PRESET_27		0x1B	// 1.25V
#define STPMIC_BUCK2_PRESET_28		0x1C	// 1.3V
#define STPMIC_BUCK2_PRESET_29		0x1D	// 1.3V
#define STPMIC_BUCK2_PRESET_30		0x1E	// 1.35V
#define STPMIC_BUCK2_PRESET_31		0x1F	// 1.35V
#define STPMIC_BUCK2_PRESET_32		0x20	// 1.4V
#define STPMIC_BUCK2_PRESET_33		0x21	// 1.4V
#define STPMIC_BUCK2_PRESET_34		0x22	// 1.45V
#define STPMIC_BUCK2_PRESET_35		0x23	// 1.45V
#define STPMIC_BUCK2_PRESET_36		0x24	// 1.5V
#define STPMIC_BUCK2_PRESET_37		0x25	// 1.5V
#define STPMIC_BUCK2_PRESET_38		0x26	// 1.5V
#define STPMIC_BUCK2_PRESET_39		0x27	// 1.5V
#define STPMIC_BUCK2_PRESET_40		0x28	// 1.5V
#define STPMIC_BUCK2_PRESET_41		0x29	// 1.5V
#define STPMIC_BUCK2_PRESET_42		0x2A	// 1.5V
#define STPMIC_BUCK2_PRESET_43		0x2B	// 1.5V
#define STPMIC_BUCK2_PRESET_44		0x2C	// 1.5V
#define STPMIC_BUCK2_PRESET_45		0x2D	// 1.5V
#define STPMIC_BUCK2_PRESET_46		0x2E	// 1.5V
#define STPMIC_BUCK2_PRESET_47		0x2F	// 1.5V
#define STPMIC_BUCK2_PRESET_48		0x30	// 1.5V
#define STPMIC_BUCK2_PRESET_49		0x31	// 1.5V
#define STPMIC_BUCK2_PRESET_50		0x32	// 1.5V
#define STPMIC_BUCK2_PRESET_51		0x33	// 1.5V
#define STPMIC_BUCK2_PRESET_52		0x34	// 1.5V
#define STPMIC_BUCK2_PRESET_53		0x35	// 1.5V
#define STPMIC_BUCK2_PRESET_54		0x36	// 1.5V
#define STPMIC_BUCK2_PRESET_55		0x37	// 1.5V
#define STPMIC_BUCK2_PRESET_56		0x38	// 1.5V
#define STPMIC_BUCK2_PRESET_57		0x39	// 1.5V
#define STPMIC_BUCK2_PRESET_58		0x3A	// 1.5V
#define STPMIC_BUCK2_PRESET_59		0x3B	// 1.5V
#define STPMIC_BUCK2_PRESET_60		0x3C	// 1.5V
#define STPMIC_BUCK2_PRESET_61		0x3D	// 1.5V
#define STPMIC_BUCK2_PRESET_62		0x3E	// 1.5V
#define STPMIC_BUCK2_PRESET_63		0x3F	// 1.5V

// STPMIC_BUCK3_MAIN_CR - BUCK3 MAIN mode control register
//
#define STPMIC_BUCK3_MAIN_CR			0x22	//BUCK3 MAIN mode control register
#define STPMIC_BUCK3_MAIN_ENA			0U		//Buck enable bit
#define STPMIC_BUCK3_MAIN_PREG_MODE		1U		//Select high power or low power regulation mode
#define STPMIC_BUCK3_MAIN_VOUT			2U		//Buck output voltage setting.

#define STPMIC_BUCK3_PRESET_0		0x00	// 1V
#define STPMIC_BUCK3_PRESET_1		0x01	// 1V
#define STPMIC_BUCK3_PRESET_2		0x02	// 1V
#define STPMIC_BUCK3_PRESET_3		0x03	// 1V
#define STPMIC_BUCK3_PRESET_4		0x04	// 1V
#define STPMIC_BUCK3_PRESET_5		0x05	// 1V
#define STPMIC_BUCK3_PRESET_6		0x06	// 1V
#define STPMIC_BUCK3_PRESET_7		0x07	// 1V
#define STPMIC_BUCK3_PRESET_8		0x08	// 1V
#define STPMIC_BUCK3_PRESET_9		0x09	// 1V
#define STPMIC_BUCK3_PRESET_10		0x0A	// 1V
#define STPMIC_BUCK3_PRESET_11		0x0B	// 1V
#define STPMIC_BUCK3_PRESET_12		0x0C	// 1V
#define STPMIC_BUCK3_PRESET_13		0x0D	// 1V
#define STPMIC_BUCK3_PRESET_14		0x0E	// 1V
#define STPMIC_BUCK3_PRESET_15		0x0F	// 1V
#define STPMIC_BUCK3_PRESET_16		0x10	// 1V
#define STPMIC_BUCK3_PRESET_17		0x11	// 1V
#define STPMIC_BUCK3_PRESET_18		0x12	// 1V
#define STPMIC_BUCK3_PRESET_19		0x13	// 1V
#define STPMIC_BUCK3_PRESET_20		0x14	// 1.1V
#define STPMIC_BUCK3_PRESET_21		0x15	// 1.1V
#define STPMIC_BUCK3_PRESET_22		0x16	// 1.1V
#define STPMIC_BUCK3_PRESET_23		0x17	// 1.1V
#define STPMIC_BUCK3_PRESET_24		0x18	// 1.2V
#define STPMIC_BUCK3_PRESET_25		0x19	// 1.2V
#define STPMIC_BUCK3_PRESET_26		0x1A	// 1.2V
#define STPMIC_BUCK3_PRESET_27		0x1B	// 1.2V
#define STPMIC_BUCK3_PRESET_28		0x1C	// 1.3V
#define STPMIC_BUCK3_PRESET_29		0x1D	// 1.3V
#define STPMIC_BUCK3_PRESET_30		0x1E	// 1.3V
#define STPMIC_BUCK3_PRESET_31		0x1F	// 1.3V
#define STPMIC_BUCK3_PRESET_32		0x20	// 1.4V
#define STPMIC_BUCK3_PRESET_33		0x21	// 1.4V
#define STPMIC_BUCK3_PRESET_34		0x22	// 1.4V
#define STPMIC_BUCK3_PRESET_35		0x23	// 1.4V
#define STPMIC_BUCK3_PRESET_36		0x24	// 1.5V
#define STPMIC_BUCK3_PRESET_37		0x25	// 1.6V
#define STPMIC_BUCK3_PRESET_38		0x26	// 1.7V
#define STPMIC_BUCK3_PRESET_39		0x27	// 1.8V
#define STPMIC_BUCK3_PRESET_40		0x28	// 1.9V
#define STPMIC_BUCK3_PRESET_41		0x29	// 2V
#define STPMIC_BUCK3_PRESET_42		0x2A	// 2.1V
#define STPMIC_BUCK3_PRESET_43		0x2B	// 2.2V
#define STPMIC_BUCK3_PRESET_44		0x2C	// 2.3V
#define STPMIC_BUCK3_PRESET_45		0x2D	// 2.4V
#define STPMIC_BUCK3_PRESET_46		0x2E	// 2.5V
#define STPMIC_BUCK3_PRESET_47		0x2F	// 2.6V
#define STPMIC_BUCK3_PRESET_48		0x30	// 2.7V
#define STPMIC_BUCK3_PRESET_49		0x31	// 2.8V
#define STPMIC_BUCK3_PRESET_50		0x32	// 2.9V
#define STPMIC_BUCK3_PRESET_51		0x33	// 3V
#define STPMIC_BUCK3_PRESET_52		0x34	// 3.1V
#define STPMIC_BUCK3_PRESET_53		0x35	// 3.2V
#define STPMIC_BUCK3_PRESET_54		0x36	// 3.3V
#define STPMIC_BUCK3_PRESET_55		0x37	// 3.4V
#define STPMIC_BUCK3_PRESET_56		0x38	// 3.5V
#define STPMIC_BUCK3_PRESET_57		0x39	// 3.6V
#define STPMIC_BUCK3_PRESET_58		0x3A	// 3.7V
#define STPMIC_BUCK3_PRESET_59		0x3B	// 3.8V
#define STPMIC_BUCK3_PRESET_60		0x3C	// 3.9V
#define STPMIC_BUCK3_PRESET_61		0x3D	// 3.9V
#define STPMIC_BUCK3_PRESET_62		0x3E	// 3.9V
#define STPMIC_BUCK3_PRESET_63		0x3F	// 3.9V

// STPMIC_BUCK4_MAIN_CR - BUCK4 MAIN mode control register
//
#define STPMIC_BUCK4_MAIN_CR			0x23	//BUCK4 MAIN mode control register
#define STPMIC_BUCK4_MAIN_ENA			0U		//Buck enable bit
#define STPMIC_BUCK4_MAIN_PREG_MODE		1U		//Select high power or low power regulation mode
#define STPMIC_BUCK4_MAIN_VOUT			2U		//Buck output voltage setting.


#define STPMIC_BUCK4_PRESET_0		0x00	// 0.6V
#define STPMIC_BUCK4_PRESET_1		0x01	// 0.625V
#define STPMIC_BUCK4_PRESET_2		0x02	// 0.65V
#define STPMIC_BUCK4_PRESET_3		0x03	// 0.675V
#define STPMIC_BUCK4_PRESET_4		0x04	// 0.7V
#define STPMIC_BUCK4_PRESET_5		0x05	// 0.725V
#define STPMIC_BUCK4_PRESET_6		0x06	// 0.75V
#define STPMIC_BUCK4_PRESET_7		0x07	// 0.775V
#define STPMIC_BUCK4_PRESET_8		0x08	// 0.8V
#define STPMIC_BUCK4_PRESET_9		0x09	// 0.825V
#define STPMIC_BUCK4_PRESET_10		0x0A	// 0.85V
#define STPMIC_BUCK4_PRESET_11		0x0B	// 0.875V
#define STPMIC_BUCK4_PRESET_12		0x0C	// 0.9V
#define STPMIC_BUCK4_PRESET_13		0x0D	// 0.925V
#define STPMIC_BUCK4_PRESET_14		0x0E	// 0.95V
#define STPMIC_BUCK4_PRESET_15		0x0F	// 0.975V
#define STPMIC_BUCK4_PRESET_16		0x10	// 1V
#define STPMIC_BUCK4_PRESET_17		0x11	// 1.025V
#define STPMIC_BUCK4_PRESET_18		0x12	// 1.05V
#define STPMIC_BUCK4_PRESET_19		0x13	// 1.075V
#define STPMIC_BUCK4_PRESET_20		0x14	// 1.1V
#define STPMIC_BUCK4_PRESET_21		0x15	// 1.125V
#define STPMIC_BUCK4_PRESET_22		0x16	// 1.15V
#define STPMIC_BUCK4_PRESET_23		0x17	// 1.175V
#define STPMIC_BUCK4_PRESET_24		0x18	// 1.2V
#define STPMIC_BUCK4_PRESET_25		0x19	// 1.225V
#define STPMIC_BUCK4_PRESET_26		0x1A	// 1.25V
#define STPMIC_BUCK4_PRESET_27		0x1B	// 1.275V
#define STPMIC_BUCK4_PRESET_28		0x1C	// 1.3V
#define STPMIC_BUCK4_PRESET_29		0x1D	// 1.3V
#define STPMIC_BUCK4_PRESET_30		0x1E	// 1.35V
#define STPMIC_BUCK4_PRESET_31		0x1F	// 1.35V
#define STPMIC_BUCK4_PRESET_32		0x20	// 1.4V
#define STPMIC_BUCK4_PRESET_33		0x21	// 1.4V
#define STPMIC_BUCK4_PRESET_34		0x22	// 1.45V
#define STPMIC_BUCK4_PRESET_35		0x23	// 1.45V
#define STPMIC_BUCK4_PRESET_36		0x24	// 1.5V
#define STPMIC_BUCK4_PRESET_37		0x25	// 1.6V
#define STPMIC_BUCK4_PRESET_38		0x26	// 1.7V
#define STPMIC_BUCK4_PRESET_39		0x27	// 1.8V
#define STPMIC_BUCK4_PRESET_40		0x28	// 1.9V
#define STPMIC_BUCK4_PRESET_41		0x29	// 2V
#define STPMIC_BUCK4_PRESET_42		0x2A	// 2.1V
#define STPMIC_BUCK4_PRESET_43		0x2B	// 2.2V
#define STPMIC_BUCK4_PRESET_44		0x2C	// 2.3V
#define STPMIC_BUCK4_PRESET_45		0x2D	// 2.4V
#define STPMIC_BUCK4_PRESET_46		0x2E	// 2.5V
#define STPMIC_BUCK4_PRESET_47		0x2F	// 2.6V
#define STPMIC_BUCK4_PRESET_48		0x30	// 2.7V
#define STPMIC_BUCK4_PRESET_49		0x31	// 2.8V
#define STPMIC_BUCK4_PRESET_50		0x32	// 2.9V
#define STPMIC_BUCK4_PRESET_51		0x33	// 3V
#define STPMIC_BUCK4_PRESET_52		0x34	// 3.1V
#define STPMIC_BUCK4_PRESET_53		0x35	// 3.2V
#define STPMIC_BUCK4_PRESET_54		0x36	// 3.3V
#define STPMIC_BUCK4_PRESET_55		0x37	// 3.4V
#define STPMIC_BUCK4_PRESET_56		0x38	// 3.5V
#define STPMIC_BUCK4_PRESET_57		0x39	// 3.6V
#define STPMIC_BUCK4_PRESET_58		0x3A	// 3.7V
#define STPMIC_BUCK4_PRESET_59		0x3B	// 3.8V
#define STPMIC_BUCK4_PRESET_60		0x3C	// 3.9V
#define STPMIC_BUCK4_PRESET_61		0x3D	// 3.9V
#define STPMIC_BUCK4_PRESET_62		0x3E	// 3.9V
#define STPMIC_BUCK4_PRESET_63		0x3F	// 3.9V


// STPMIC_REFDDR_MAIN_CR - REFDDR MAIN mode control register
//
#define STPMIC_REFDDR_MAIN_CR			0x24	//REFDDR MAIN mode control register
#define STPMIC_REFDDR_MAIN_ENA			0U		//VREF_DDR enable bit

// STPMIC_LDO1_MAIN_CR - LDO1 MAIN mode control registers
//
#define STPMIC_LDO1_MAIN_CR		0x25	//LDO1 MAIN mode control registers
#define STPMIC_LDO1_MAIN_ENA	0U		//LDOx enable bit
#define STPMIC_LDO1_MAIN_VOUT	2U		//LDOx output voltage setting.

#define STPMIC_LDO1_PRESET_0		0x00	// 1.7V
#define STPMIC_LDO1_PRESET_1		0x01	// 1.7V
#define STPMIC_LDO1_PRESET_2		0x02	// 1.7V
#define STPMIC_LDO1_PRESET_3		0x03	// 1.7V
#define STPMIC_LDO1_PRESET_4		0x04	// 1.7V
#define STPMIC_LDO1_PRESET_5		0x05	// 1.7V
#define STPMIC_LDO1_PRESET_6		0x06	// 1.7V
#define STPMIC_LDO1_PRESET_7		0x07	// 1.7V
#define STPMIC_LDO1_PRESET_8		0x08	// 1.7V
#define STPMIC_LDO1_PRESET_9		0x09	// 1.8V
#define STPMIC_LDO1_PRESET_10		0x0A	// 1.9V
#define STPMIC_LDO1_PRESET_11		0x0B	// 2.0V
#define STPMIC_LDO1_PRESET_12		0x0C	// 2.1V
#define STPMIC_LDO1_PRESET_13		0x0D	// 2.2V
#define STPMIC_LDO1_PRESET_14		0x0E	// 2.3V
#define STPMIC_LDO1_PRESET_15		0x0F	// 2.4V
#define STPMIC_LDO1_PRESET_16		0x10	// 2.5V
#define STPMIC_LDO1_PRESET_17		0x11	// 2.6V
#define STPMIC_LDO1_PRESET_18		0x12	// 2.7V
#define STPMIC_LDO1_PRESET_19		0x13	// 2.8V
#define STPMIC_LDO1_PRESET_20		0x14	// 2.9V
#define STPMIC_LDO1_PRESET_21		0x15	// 3.0V
#define STPMIC_LDO1_PRESET_22		0x16	// 3.1V
#define STPMIC_LDO1_PRESET_23		0x17	// 3.2V
#define STPMIC_LDO1_PRESET_24		0x18	// 3.3V
#define STPMIC_LDO1_PRESET_25		0x19	// 3.3V
#define STPMIC_LDO1_PRESET_26		0x1A	// 3.3V
#define STPMIC_LDO1_PRESET_27		0x1B	// 3.3V
#define STPMIC_LDO1_PRESET_28		0x1C	// 3.3V
#define STPMIC_LDO1_PRESET_29		0x1D	// 3.3V
#define STPMIC_LDO1_PRESET_30		0x1E	// 3.3V
#define STPMIC_LDO1_PRESET_31		0x1F	// 3.3V

// STPMIC_LDO2_MAIN_CR - LDO2 MAIN mode control registers
//
#define STPMIC_LDO2_MAIN_CR		0x26	//LDO2 MAIN mode control registers
#define STPMIC_LDO2_MAIN_ENA	0U		//LDOx enable bit
#define STPMIC_LDO2_MAIN_VOUT	2U		//LDOx output voltage setting.

#define STPMIC_LDO2_PRESET_0		0x00	// 1.7V
#define STPMIC_LDO2_PRESET_1		0x01	// 1.7V
#define STPMIC_LDO2_PRESET_2		0x02	// 1.7V
#define STPMIC_LDO2_PRESET_3		0x03	// 1.7V
#define STPMIC_LDO2_PRESET_4		0x04	// 1.7V
#define STPMIC_LDO2_PRESET_5		0x05	// 1.7V
#define STPMIC_LDO2_PRESET_6		0x06	// 1.7V
#define STPMIC_LDO2_PRESET_7		0x07	// 1.7V
#define STPMIC_LDO2_PRESET_8		0x08	// 1.7V
#define STPMIC_LDO2_PRESET_9		0x09	// 1.8V
#define STPMIC_LDO2_PRESET_10		0x0A	// 1.9V
#define STPMIC_LDO2_PRESET_11		0x0B	// 2.0V
#define STPMIC_LDO2_PRESET_12		0x0C	// 2.1V
#define STPMIC_LDO2_PRESET_13		0x0D	// 2.2V
#define STPMIC_LDO2_PRESET_14		0x0E	// 2.3V
#define STPMIC_LDO2_PRESET_15		0x0F	// 2.4V
#define STPMIC_LDO2_PRESET_16		0x10	// 2.5V
#define STPMIC_LDO2_PRESET_17		0x11	// 2.6V
#define STPMIC_LDO2_PRESET_18		0x12	// 2.7V
#define STPMIC_LDO2_PRESET_19		0x13	// 2.8V
#define STPMIC_LDO2_PRESET_20		0x14	// 2.9V
#define STPMIC_LDO2_PRESET_21		0x15	// 3.0V
#define STPMIC_LDO2_PRESET_22		0x16	// 3.1V
#define STPMIC_LDO2_PRESET_23		0x17	// 3.2V
#define STPMIC_LDO2_PRESET_24		0x18	// 3.3V
#define STPMIC_LDO2_PRESET_25		0x19	// 3.3V
#define STPMIC_LDO2_PRESET_26		0x1A	// 3.3V
#define STPMIC_LDO2_PRESET_27		0x1B	// 3.3V
#define STPMIC_LDO2_PRESET_28		0x1C	// 3.3V
#define STPMIC_LDO2_PRESET_29		0x1D	// 3.3V
#define STPMIC_LDO2_PRESET_30		0x1E	// 3.3V
#define STPMIC_LDO2_PRESET_31		0x1F	// 3.3V

// STPMIC_LDO3_MAIN_CR - LDO3 MAIN mode control registers
//
#define STPMIC_LDO3_MAIN_CR		0x27	//LDO3 MAIN mode control registers
#define STPMIC_LDO3_MAIN_ENA	0U		//LDOx enable bit
#define STPMIC_LDO3_MAIN_VOUT	2U		//LDOx output voltage setting.
#define STPMIC_LDO3_MAIN_BYPASS	2U		//force bypass mode of LDO3

#define STPMIC_LDO3_PRESET_0		0x00	// 1.7V
#define STPMIC_LDO3_PRESET_1		0x01	// 1.7V
#define STPMIC_LDO3_PRESET_2		0x02	// 1.7V
#define STPMIC_LDO3_PRESET_3		0x03	// 1.7V
#define STPMIC_LDO3_PRESET_4		0x04	// 1.7V
#define STPMIC_LDO3_PRESET_5		0x05	// 1.7V
#define STPMIC_LDO3_PRESET_6		0x06	// 1.7V
#define STPMIC_LDO3_PRESET_7		0x07	// 1.7V
#define STPMIC_LDO3_PRESET_8		0x08	// 1.7V
#define STPMIC_LDO3_PRESET_9		0x09	// 1.8V
#define STPMIC_LDO3_PRESET_10		0x0A	// 1.9V
#define STPMIC_LDO3_PRESET_11		0x0B	// 2.0V
#define STPMIC_LDO3_PRESET_12		0x0C	// 2.1V
#define STPMIC_LDO3_PRESET_13		0x0D	// 2.2V
#define STPMIC_LDO3_PRESET_14		0x0E	// 2.3V
#define STPMIC_LDO3_PRESET_15		0x0F	// 2.4V
#define STPMIC_LDO3_PRESET_16		0x10	// 2.5V
#define STPMIC_LDO3_PRESET_17		0x11	// 2.6V
#define STPMIC_LDO3_PRESET_18		0x12	// 2.7V
#define STPMIC_LDO3_PRESET_19		0x13	// 2.8V
#define STPMIC_LDO3_PRESET_20		0x14	// 2.9V
#define STPMIC_LDO3_PRESET_21		0x15	// 3.0V
#define STPMIC_LDO3_PRESET_22		0x16	// 3.1V
#define STPMIC_LDO3_PRESET_23		0x17	// 3.2V
#define STPMIC_LDO3_PRESET_24		0x18	// 3.3V
#define STPMIC_LDO3_PRESET_25		0x19	// 3.3V
#define STPMIC_LDO3_PRESET_26		0x1A	// 3.3V
#define STPMIC_LDO3_PRESET_27		0x1B	// 3.3V
#define STPMIC_LDO3_PRESET_28		0x1C	// 3.3V
#define STPMIC_LDO3_PRESET_29		0x1D	// 3.3V
#define STPMIC_LDO3_PRESET_30		0x1E	// 3.3V
#define STPMIC_LDO3_PRESET_31		0x1F	// VOUT2/2(sink/source)

// STPMIC_LDO4_MAIN_CR - LDO4 MAIN mode control registers
//
#define STPMIC_LDO4_MAIN_CR				0x28	//LDO4 MAIN mode control registers
#define STPMIC_LDO4_MAIN_ENA			0U		//LDOx enable bit
#define STPMIC_LDO4_MAIN_SRC_VIN		2U		//Force VIN as input source.
#define STPMIC_LDO4_MAIN_SRC_BOOST		3U		//Force BSTOUT as input source.
#define STPMIC_LDO4_MAIN_SRC_VBUSOTG	4U		//Force VBUSOTG as input source.

// STPMIC_LDO5_MAIN_CR - LDO5 MAIN mode control registers
//
#define STPMIC_LDO5_MAIN_CR		0x29	//LDO5 MAIN mode control registers
#define STPMIC_LDO5_MAIN_ENA	0U		//LDOx enable bit
#define STPMIC_LDO5_MAIN_VOUT	2U		//LDOx output voltage setting.

#define STPMIC_LDO5_PRESET_0		0x00	// 1.7V
#define STPMIC_LDO5_PRESET_1		0x01	// 1.7V
#define STPMIC_LDO5_PRESET_2		0x02	// 1.7V
#define STPMIC_LDO5_PRESET_3		0x03	// 1.7V
#define STPMIC_LDO5_PRESET_4		0x04	// 1.7V
#define STPMIC_LDO5_PRESET_5		0x05	// 1.7V
#define STPMIC_LDO5_PRESET_6		0x06	// 1.7V
#define STPMIC_LDO5_PRESET_7		0x07	// 1.7V
#define STPMIC_LDO5_PRESET_8		0x08	// 1.7V
#define STPMIC_LDO5_PRESET_9		0x09	// 1.8V
#define STPMIC_LDO5_PRESET_10		0x0A	// 1.9V
#define STPMIC_LDO5_PRESET_11		0x0B	// 2.0V
#define STPMIC_LDO5_PRESET_12		0x0C	// 2.1V
#define STPMIC_LDO5_PRESET_13		0x0D	// 2.2V
#define STPMIC_LDO5_PRESET_14		0x0E	// 2.3V
#define STPMIC_LDO5_PRESET_15		0x0F	// 2.4V
#define STPMIC_LDO5_PRESET_16		0x10	// 2.5V
#define STPMIC_LDO5_PRESET_17		0x11	// 2.6V
#define STPMIC_LDO5_PRESET_18		0x12	// 2.7V
#define STPMIC_LDO5_PRESET_19		0x13	// 2.8V
#define STPMIC_LDO5_PRESET_20		0x14	// 2.9V
#define STPMIC_LDO5_PRESET_21		0x15	// 3.0V
#define STPMIC_LDO5_PRESET_22		0x16	// 3.1V
#define STPMIC_LDO5_PRESET_23		0x17	// 3.2V
#define STPMIC_LDO5_PRESET_24		0x18	// 3.3V
#define STPMIC_LDO5_PRESET_25		0x19	// 3.4V
#define STPMIC_LDO5_PRESET_26		0x1A	// 3.5V
#define STPMIC_LDO5_PRESET_27		0x1B	// 3.6V
#define STPMIC_LDO5_PRESET_28		0x1C	// 3.7V
#define STPMIC_LDO5_PRESET_29		0x1D	// 3.8V
#define STPMIC_LDO5_PRESET_30		0x1E	// 3.9V
#define STPMIC_LDO5_PRESET_31		0x1F	// 3.9V

// STPMIC_LDO6_MAIN_CR - LDO6 MAIN mode control registers
//
#define STPMIC_LDO6_MAIN_CR		0x2A	//LDO6 MAIN mode control registers
#define STPMIC_LDO6_MAIN_ENA	0U		//LDOx enable bit
#define STPMIC_LDO6_MAIN_VOUT	2U		//LDOx output voltage setting.

#define STPMIC_LDO6_PRESET_0		0x00	// 1.7V
#define STPMIC_LDO6_PRESET_1		0x01	// 1.7V
#define STPMIC_LDO6_PRESET_2		0x02	// 1.7V
#define STPMIC_LDO6_PRESET_3		0x03	// 1.7V
#define STPMIC_LDO6_PRESET_4		0x04	// 1.7V
#define STPMIC_LDO6_PRESET_5		0x05	// 1.7V
#define STPMIC_LDO6_PRESET_6		0x06	// 1.7V
#define STPMIC_LDO6_PRESET_7		0x07	// 1.7V
#define STPMIC_LDO6_PRESET_8		0x08	// 1.7V
#define STPMIC_LDO6_PRESET_9		0x09	// 1.8V
#define STPMIC_LDO6_PRESET_10		0x0A	// 1.9V
#define STPMIC_LDO6_PRESET_11		0x0B	// 2.0V
#define STPMIC_LDO6_PRESET_12		0x0C	// 2.1V
#define STPMIC_LDO6_PRESET_13		0x0D	// 2.2V
#define STPMIC_LDO6_PRESET_14		0x0E	// 2.3V
#define STPMIC_LDO6_PRESET_15		0x0F	// 2.4V
#define STPMIC_LDO6_PRESET_16		0x10	// 2.5V
#define STPMIC_LDO6_PRESET_17		0x11	// 2.6V
#define STPMIC_LDO6_PRESET_18		0x12	// 2.7V
#define STPMIC_LDO6_PRESET_19		0x13	// 2.8V
#define STPMIC_LDO6_PRESET_20		0x14	// 2.9V
#define STPMIC_LDO6_PRESET_21		0x15	// 3.0V
#define STPMIC_LDO6_PRESET_22		0x16	// 3.1V
#define STPMIC_LDO6_PRESET_23		0x17	// 3.2V
#define STPMIC_LDO6_PRESET_24		0x18	// 3.3V
#define STPMIC_LDO6_PRESET_25		0x19	// 3.3V
#define STPMIC_LDO6_PRESET_26		0x1A	// 3.3V
#define STPMIC_LDO6_PRESET_27		0x1B	// 3.3V
#define STPMIC_LDO6_PRESET_28		0x1C	// 3.3V
#define STPMIC_LDO6_PRESET_29		0x1D	// 3.3V
#define STPMIC_LDO6_PRESET_30		0x1E	// 3.3V
#define STPMIC_LDO6_PRESET_31		0x1F	// 3.3V

// BUCK1_ALT_CR - BUCK1 ALTERNATE mode control registers
//
#define STPMIC_BUCK1_ALT_CR			0x30	//BUCK1 ALTERNATE mode control registers
#define STPMIC_BUCK1_ALT_ENA		0U		//Buck enable bit
#define STPMIC_BUCK1_ALT_PREG_MODE	1U		//Force high power or low power mode of buck
#define STPMIC_BUCK1_ALT_VOUT		2U		//Buck output settings

// BUCK2_ALT_CR - BUCK2 ALTERNATE mode control registers
//
#define STPMIC_BUCK2_ALT_CR			0x31	//BUCK2 ALTERNATE mode control registers
#define STPMIC_BUCK2_ALT_ENA		0U		//Buck enable bit
#define STPMIC_BUCK2_ALT_PREG_MODE	1U		//Force high power or low power mode of buck
#define STPMIC_BUCK2_ALT_VOUT		2U		//Buck output settings

// BUCK3_ALT_CR - BUCK3 ALTERNATE mode control registers
//
#define STPMIC_BUCK3_ALT_CR			0x32	//BUCK3 ALTERNATE mode control registers
#define STPMIC_BUCK3_ALT_ENA		0U		//Buck enable bit
#define STPMIC_BUCK3_ALT_PREG_MODE	1U		//Force high power or low power mode of buck
#define STPMIC_BUCK3_ALT_VOUT		2U		//Buck output settings

// BUCK4_ALT_CR - BUCK4 ALTERNATE mode control registers
//
#define STPMIC_BUCK4_ALT_CR			0x33	//BUCK4 ALTERNATE mode control registers
#define STPMIC_BUCK4_ALT_ENA		0U		//Buck enable bit
#define STPMIC_BUCK4_ALT_PREG_MODE	1U		//Force high power or low power mode of buck
#define STPMIC_BUCK4_ALT_VOUT		2U		//Buck output settings

// REFDDR_ALT_CR - REFDDR ALTERNATE mode control register
//
#define STPMIC_REFDDR_ALT_CR		0x34	//REFDDR ALTERNATE mode control register
#define STPMIC_REFDDR_ALT_ENA		0U		//REFDDR Enable bit

// LDO1_ALT_CR - LDO1 ALTERNATE mode control registers
//
#define STPMIC_LDO1_ALT_CR			0x35	//LDO1 ALTERNATE mode control registers
#define STPMIC_LDO1_ALT_ENA			0U		//LDO1 enable bit
#define STPMIC_LDO1_ALT_VOUT		2U		//LDO1 output settings

// LDO2_ALT_CR - LDO2 ALTERNATE mode control registers
//
#define STPMIC_LDO2_ALT_CR			0x36	//LDO2 ALTERNATE mode control registers
#define STPMIC_LDO2_ALT_ENA			0U		//LDO2 enable bit
#define STPMIC_LDO2_ALT_VOUT		2U		//LDO2 output settings

// LDO3_ALT_CR - LDO3 ALTERNATE mode control registers
//
#define STPMIC_LDO3_ALT_CR			0x37	//LDO3 ALTERNATE mode control registers
#define STPMIC_LDO3_ALT_ENA			0U		//LDO3 enable bit
#define STPMIC_LDO3_ALT_VOUT		2U		//LDO3 output settings
#define STPMIC_LDO3_ALT_BYPASS		7U		//force bypass mode of LDO3

// LDO4_ALT_CR - LDO4 ALTERNATE mode control registers
//
#define STPMIC_LDO4_ALT_CR			0x38	//LDO4 ALTERNATE mode control registers
#define STPMIC_LDO4_ALT_ENA			0U		//LDO4 enable bit

// LDO5_ALT_CR - LDO5 ALTERNATE mode control registers
//
#define STPMIC_LDO5_ALT_CR			0x39	//LDO5 ALTERNATE mode control registers
#define STPMIC_LDO5_ALT_ENA			0U		//LDO5 enable bit
#define STPMIC_LDO5_ALT_VOUT		2U		//LDO5 output settings

// LDO6_ALT_CR - LDO6 ALTERNATE mode control registers
//
#define STPMIC_LDO6_ALT_CR			0x3A	//LDO6 ALTERNATE mode control registers
#define STPMIC_LDO6_ALT_ENA			0U		//LDO6 enable bit
#define STPMIC_LDO6_ALT_VOUT		2U		//LDO6 output settings

// BST_SW_CR - Boost/switch control register
//
#define STPMIC_BST_SW_CR				0x40	//Boost/switch control register
#define STPMIC_BST_SW_BST_ON			0U		//BOOST enable bit
#define STPMIC_BST_SW_VBUSOTG_ON 		1U		//PWR_USB_SW switch enable
#define STPMIC_BST_SW_SWOUT_ON 			2U		//PWR_SW switch enable bit
#define STPMIC_BST_SW_OCP_SWOUT_LIM 	3U		//Overcurrent limit protection of PWR_SW switch
#define STPMIC_BST_SW_VBUSOTG_PD 		4U		//PWR_USB_SW pull-down activation
#define STPMIC_BST_SW_SWOUT_PD 			5U		//SWOUT (PWR_SW) pull-down activation
#define STPMIC_BST_SW_VBUSOTG_DET_DIS 	6U		//PWR_USB_SW detection circuit disable



// LDO control registers



// LDO VOUT Register Presets
#define STPMIC_LDO_VOUT_3_3V	0x7D	//Set LDO to 3.3V out. LDO3 - VOUT 2/2 (sink/source)



#endif /* STPMIC1_DRIVER_STPMIC1_DEF_H_ */