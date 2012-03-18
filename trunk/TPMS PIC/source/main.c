/*
File: main.c
Date:
 
*/

#include <htc.h>
#include <adc.h>
#include <wdt.h>
#include <interrupts.h>
//#include <configuration.h>

__CONFIG(FOSC_INTOSC & WDTE_SWDTEN);
void main(void)
{
	//ports_init();
	wdt_init();
	adc_init();
	interrupts_init();
	
	char x;
	x=adc_get_sample();
}