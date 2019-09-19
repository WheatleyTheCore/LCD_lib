/*
 * LCD_lib.h
 *
 *  Created on: Sep 15, 2019
 *      Author: glado
 */

#ifndef LCD_LIB_H_
#define LCD_LIB_H_

void init(void);

void sendByteDR(byte dataByte);

void sendByteIR(byte dataByte);

void pulseE(void);


#endif /* LCD_LIB_H_ */
