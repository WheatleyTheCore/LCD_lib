/* ###################################################################
**     Filename    : main.c
**     Project     : MC9S08JM60
**     Processor   : MC9S08JM60CLHE
**     Version     : Driver 01.12
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2019-07-25, 12:21, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.12
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Bit1.h"
#include "RS.h"
#include "TI1.h"
#include "EC321.h"
#include "DataPins.h"
#include "E.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "LCD_lib.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

// Global variables for communicating with ISR
dword volatile count;
byte volatile flag;

void main(void)
{
	PE_low_level_init();
  /* Write your local variable definition here */
	init();
	
	
	// BEGIN SENDING CHAR
	
	sendByteDR(0x0f); //first half
	sendByteDR(0x04); //second half
	
	
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  for(;;) {
	  
	  
	  if (flag == 1){
		  // Display new value
		  //EI2C1_SendChar(count);
		  flag = 0;
	  }
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
