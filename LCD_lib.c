
#include "Cpu.h"
#include "E.h"
#include "RS.h"
#include "DataBits.h"
#include "LCD_lib.h"
/* Include Prototypes for your library, if applicable */
/* #include "mylibrary.h" */



/*-----------------------------------------------------------------------*

	Place your 'C' library code here.
	
 *-----------------------------------------------------------------------*/

void init(void){
	Cpu_Delay100US(1000);
	sendByteIR(0x03); //0011
	sendByteIR(0x03); //0011
	sendByteIR(0x03); //0011
	sendByteIR(0x02); //0010
	sendByteIR(0x02); //0010
	sendByteIR(0x08); //1000
	sendByteIR(0x00); //0000
	sendByteIR(0x01); //0001
	sendByteIR(0x00); //0000
	sendByteIR(0x0f); //1111
}

void sendByteDR(byte dataByte) {
	// if RS is low, set it high
	if (!RS_GetVal()) {
		RS_PutVal(1);
	}
	
	//delay
	Cpu_Delay100US(100);
	
	//set dataByte
	DataPins_PutVal(dataByte); 
	
	//pulse E
	pulseE();
}

void sendByteIR(byte dataByte){
	//if RS is high, set low
	if (RS_GetVal()) {
			RS_PutVal(0);
		}
		
		//delay
		Cpu_Delay100US(100);
		
		//set dataByte
		DataPins_PutVal(dataByte); 
		
		//pulse E
		pulseE();
}

void pulseE(void) {
	//delay 100us
	Cpu_Delay100US(100);
	//set E high
	E_PutVal(1);
	// Delay again
	Cpu_Delay100US(100);
	//set E low 
	E_PutVal(0);
	//Delay
	Cpu_Delay100US(100);
}
