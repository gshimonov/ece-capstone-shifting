//configuration.h


/*  Configuration Word 1 */
/* p52/418)

/* bit13 */ 	#pragma config  FCMEN 		=OFF//??
/* bit12 */ 	#pragma config  IESO 		=OFF//??
/* bit11 */ 	#pragma config  CLKOUTEN	=ON//??disable clkout
/* bit10-09 */ 	#pragma config  BOREN		=0b10
/* bit08 */ 	#pragma config  CPD			=OFF
/* bit07 */ 	#pragma config  CP			=OFF
/* bit06 */ 	#pragma config  MCLRE		=OFF/??
/* bit05 */ 	#pragma config  PWRTE		=ON//??
/* bit4-3*/ 	#pragma config  WDTE 		=ON
/* bit2-0 */ 	#pragma config  FOSC 		=INTOCS//??

/*  Configuration Word 2 */
/* bit13 */ 	#pragma config  LVP			=OFF 
/* bit12 */ 	#pragma config  DEBUG		=OFF
/* bit11 */ 	//unimplemented
/* bit10 */ 	#pragma config  BORV 		=0
/* bit09 */ 	#pragma config  STVREN 		=OFF //stack overflow/underflow 
/* bit08 */ 	#pragma config  PLLEN 		=OFF
/* bit07 */ 	//unimplemented
/* bit06 */ 	//unimplemented
/* bit05 */ 	//unimplemented
/* bit04 */ 	//reserved, should be 1
/* bit03 */ 	//unimplemented
/* bit02 */ 	//unimplemented
/* bit1-0 */ 	#pragma config  WRTflash	=0b11 //program memory write

///* bit03 */ #pragma config  data eeprom






