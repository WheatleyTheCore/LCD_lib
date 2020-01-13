# LCD Lib

This is a LCD library for NXP Chips, specifically the MC9S08 family, and is meant to be used with processor expert. It is designed for LCDs using the HD44780 chipset.

It uses the 4 bit interface, rather than the 8 bit one to interface with the LCD screen to minimize the number of wires needed. Info on both can be found on page 32-33 of the datasheet found at:
https://www.sparkfun.com/datasheets/LCD/HD44780.pdf

## Setting It Up
This library uses 3 components
- An E line, to tell the LCD when to read the data lines, which is a simple ioBit.
- A RS line, to say wether it should display what is sent or if what is sent is an instruction. It is also an ioBit
- Data lines, of which you need 4. For this, use ioBits, with 4 bits set in the inspector. 

## Wiring

- Check https://www.sparkfun.com/datasheets/LCD/GDM1602K.pdf to see what goes where. You use the last 4 data pins(DB4-DB7) for the data lines, with bit 0 of the ioBits going to DB4 and so on.

## Usage

Now that everything is set up, you can use the library.

Before you enter the infinite loop in the main function, call init() to begin interfacing with the LCD. 

To send instructions(which are found in the HD44780 datasheet(the first link)) you use sendByteIR. Using hex(e.g. 0x74) is easiest.

To send characters, you use it as follows:
- to send letters, you use sendByteDR('a'), of course substituting whatever you want to use for a.
- to send special characters, you send sendByteDR(0x54), substituting whatever you want to send for 0x54. Characters are found on page 17-18 of the HD44780 datasheet.

To send numbers, use sendNumberDR(), using whatever number you want to send as a parameter(the type of the parameter should be some sort of int).

