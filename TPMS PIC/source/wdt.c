/*
File: wdt.c
Date:
Info: datasheet p.103
*/
#include <htc.h>
#include <wdt.h>
void wdt_init()
{
	WDTCONbits.SWDTEN=1;  //software Enable/Disable for Watchdog Timer 
	WDTCONbits.WDTPS=0b10010;
}
