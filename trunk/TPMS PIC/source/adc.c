/*
File: adc.c
Date:
Info: datasheet p.150 
Functions:
	-adc_init()
	-adc_get_sample()
Notes: Analog input is on pin 6, RC3/AN7
*/
	#include <htc.h>
	#include <adc.h>
/*
Considerations:
	-For now using 8 MSBs instead of full 10 bit
Process for onfigure for ADC:
	1) Port configuration
	2) Channel selection
	3) ADC voltage reference selection
	4) ADC conversion clock source
	5) interrupt control
	6) result formatting
*/

void adc_init()
{
	TRISCbits.TRISC3=1; //set RC3 input
	ANSELCbits.ANSC3=1; //set RC analog input
	//weak pull up??

	ADCON0=0b00011100;
	//ADCON1=0b
	ADCON0bits.CHS=1;
}

unsigned char adc_get_sample(void) //triggers adc_sample
{
	ADCON0bits.ADON=1; //ADC turned on here to conserve power
	ADCON0bits.ADGO=1;
	while (ADGO)
	{
		continue;
	}
  //get's 8 MSb's from ADC result high register
	return (ADRESH);
}