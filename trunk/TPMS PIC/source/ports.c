//ports.c
#include <htc.h>
//SPI
//SCK - PIC9 - RF11
//MOSI - PIC7(SD0)-RF13
//MISO PIC8 (SDI) - RF14
//RC3/Active - PIC6-RF6
//PC4/RDYN PIC4-RF~16
//PC5/REQN PIC4 - 12
//
//PIC1 (OSC1)- RF19(~RESET)
//PIC2 (OSC2)- RF

void init_ports()
{
APFCON0bits.SDOSEL=0;  //on RC2(=pin7)
APFCON0bits.SSSEL=1;
}


//TRISx - data direction
//PORTx - reads the levels of the pins on the device
//LATx - output latch
//1825 - porta+portc


//ANSELx-  analog select
//	LATA=	
//	PORTA=
//	TRISA=