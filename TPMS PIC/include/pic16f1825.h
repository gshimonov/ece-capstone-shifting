
#ifndef	_HTC_H_
#warning Header file pic16f1825.h included directly. Use #include <htc.h> instead.
#endif

/* header file for the MICROCHIP PIC microcontroller
 *  16F1825
 */


#ifndef __PIC16F1825_H
#define __PIC16F1825_H

//
// Configuration mask definitions
//


// Config Register: CONFIG1
#define CONFIG1              0x8007
// Oscillator Selection
// ECH, External Clock, High Power Mode (4-32 MHz): device clock supplied to CLKIN pin
#define FOSC_ECH             0xFFFF
// ECM, External Clock, Medium Power Mode (0.5-4 MHz): device clock supplied to CLKIN pin
#define FOSC_ECM             0xFFFE
// ECL, External Clock, Low Power Mode (0-0.5 MHz): device clock supplied to CLKIN pin
#define FOSC_ECL             0xFFFD
// INTOSC oscillator: I/O function on CLKIN pin
#define FOSC_INTOSC          0xFFFC
// EXTRC oscillator: External RC circuit connected to CLKIN pin
#define FOSC_EXTRC           0xFFFB
// HS Oscillator, High-speed crystal/resonator connected between OSC1 and OSC2 pins
#define FOSC_HS              0xFFFA
// XT Oscillator, Crystal/resonator connected between OSC1 and OSC2 pins
#define FOSC_XT              0xFFF9
// LP Oscillator, Low-power crystal connected between OSC1 and OSC2 pins
#define FOSC_LP              0xFFF8
// Watchdog Timer Enable
// WDT enabled
#define WDTE_ON              0xFFFF
// WDT enabled while running and disabled in Sleep
#define WDTE_NSLEEP          0xFFF7
// WDT controlled by the SWDTEN bit in the WDTCON register
#define WDTE_SWDTEN          0xFFEF
// WDT disabled
#define WDTE_OFF             0xFFE7
// Power-up Timer Enable
// PWRT disabled
#define PWRTE_OFF            0xFFFF
// PWRT enabled
#define PWRTE_ON             0xFFDF
// MCLR Pin Function Select
// MCLR/VPP pin function is MCLR
#define MCLRE_ON             0xFFFF
// MCLR/VPP pin function is digital input
#define MCLRE_OFF            0xFFBF
// Flash Program Memory Code Protection
// Program memory code protection is disabled
#define CP_OFF               0xFFFF
// Program memory code protection is enabled
#define CP_ON                0xFF7F
// Data Memory Code Protection
// Data memory code protection is disabled
#define CPD_OFF              0xFFFF
// Data memory code protection is enabled
#define CPD_ON               0xFEFF
// Brown-out Reset Enable
// Brown-out Reset enabled
#define BOREN_ON             0xFFFF
// Brown-out Reset enabled while running and disabled in Sleep
#define BOREN_NSLEEP         0xFDFF
// Brown-out Reset controlled by the SBOREN bit in the BORCON register
#define BOREN_SBODEN         0xFBFF
// Brown-out Reset disabled
#define BOREN_OFF            0xF9FF
// Clock Out Enable
// CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin
#define CLKOUTEN_OFF         0xFFFF
// CLKOUT function is enabled on the CLKOUT pin
#define CLKOUTEN_ON          0xF7FF
// Internal/External Switchover
// Internal/External Switchover mode is enabled
#define IESO_ON              0xFFFF
// Internal/External Switchover mode is disabled
#define IESO_OFF             0xEFFF
// Fail-Safe Clock Monitor Enable
// Fail-Safe Clock Monitor is enabled
#define FCMEN_ON             0xFFFF
// Fail-Safe Clock Monitor is disabled
#define FCMEN_OFF            0xDFFF


// Config Register: CONFIG2
#define CONFIG2              0x8008
// Flash Memory Self-Write Protection
// Write protection off
#define WRT_OFF              0xFFFF
// 000h to 1FFh write protected, 200h to 1FFFh may be modified by EECON control
#define WRT_BOOT             0xFFFE
// 000h to FFFh write protected, 1000h to 1FFFh may be modified by EECON control
#define WRT_HALF             0xFFFD
// 000h to 1FFFh write protected, no addresses may be modified by EECON control
#define WRT_ALL              0xFFFC
// PLL Enable
// 4x PLL enabled
#define PLLEN_ON             0xFFFF
// 4x PLL disabled
#define PLLEN_OFF            0xFEFF
// Stack Overflow/Underflow Reset Enable
// Stack Overflow or Underflow will cause a Reset
#define STVREN_ON            0xFFFF
// Stack Overflow or Underflow will not cause a Reset
#define STVREN_OFF           0xFDFF
// Brown-out Reset Voltage Selection
// Brown-out Reset Voltage (VBOR) set to 1.9V
#define BORV_LO              0xFFFF
// Brown-out Reset Voltage (VBOR) set to 2.7V
#define BORV_HI              0xFBFF
// Low-Voltage Programming Enable
// Low-voltage programming enabled
#define LVP_ON               0xFFFF
// High-voltage on MCLR/VPP must be used for programming
#define LVP_OFF              0xDFFF


//
// Special function register definitions
//


// Register: INDF0
volatile unsigned char           INDF0               @ 0x000;
// bit and bitfield definitions

// Register: INDF1
volatile unsigned char           INDF1               @ 0x001;
// bit and bitfield definitions

// Register: PCL
volatile unsigned char           PCL                 @ 0x002;
// bit and bitfield definitions

// Register: STATUS
volatile unsigned char           STATUS              @ 0x003;
// bit and bitfield definitions
volatile bit CARRY               @ ((unsigned)&STATUS*8)+0;
volatile bit DC                  @ ((unsigned)&STATUS*8)+1;
volatile bit ZERO                @ ((unsigned)&STATUS*8)+2;
volatile bit nPD                 @ ((unsigned)&STATUS*8)+3;
volatile bit nTO                 @ ((unsigned)&STATUS*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C                   : 1;
        unsigned	DC                  : 1;
        unsigned	Z                   : 1;
        unsigned	nPD                 : 1;
        unsigned	nTO                 : 1;
        unsigned	                    : 2;
        unsigned	: 1;
    };
} STATUSbits @ 0x003;
#endif
// bit and bitfield definitions

// Register: FSR0L
volatile unsigned char           FSR0L               @ 0x004;
// bit and bitfield definitions

// Register: FSR0H
volatile unsigned char           FSR0H               @ 0x005;
// bit and bitfield definitions

// Register: FSR0
volatile unsigned int            FSR0                @ 0x004;
// bit and bitfield definitions

// Register: FSR1L
volatile unsigned char           FSR1L               @ 0x006;
// bit and bitfield definitions

// Register: FSR1H
volatile unsigned char           FSR1H               @ 0x007;
// bit and bitfield definitions

// Register: FSR1
volatile unsigned int            FSR1                @ 0x006;

// Register: BSR
volatile unsigned char           BSR                 @ 0x008;
// bit and bitfield definitions
volatile bit BSR0                @ ((unsigned)&BSR*8)+0;
volatile bit BSR1                @ ((unsigned)&BSR*8)+1;
volatile bit BSR2                @ ((unsigned)&BSR*8)+2;
volatile bit BSR3                @ ((unsigned)&BSR*8)+3;
volatile bit BSR4                @ ((unsigned)&BSR*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BSR0                : 1;
        unsigned	BSR1                : 1;
        unsigned	BSR2                : 1;
        unsigned	BSR3                : 1;
        unsigned	BSR4                : 1;
    };
    struct {
        unsigned	BSR                 : 5;
    };
} BSRbits @ 0x008;
#endif

// Register: WREG
volatile unsigned char           WREG                @ 0x009;
// bit and bitfield definitions

// Register: PCLATH
volatile unsigned char           PCLATH              @ 0x00A;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PCLATH              : 7;
    };
} PCLATHbits @ 0x00A;
#endif

// Register: INTCON
volatile unsigned char           INTCON              @ 0x00B;
// bit and bitfield definitions
volatile bit IOCIF               @ ((unsigned)&INTCON*8)+0;
volatile bit INTF                @ ((unsigned)&INTCON*8)+1;
volatile bit TMR0IF              @ ((unsigned)&INTCON*8)+2;
volatile bit IOCIE               @ ((unsigned)&INTCON*8)+3;
volatile bit INTE                @ ((unsigned)&INTCON*8)+4;
volatile bit TMR0IE              @ ((unsigned)&INTCON*8)+5;
volatile bit PEIE                @ ((unsigned)&INTCON*8)+6;
volatile bit GIE                 @ ((unsigned)&INTCON*8)+7;
volatile bit T0IF                @ ((unsigned)&INTCON*8)+2;
volatile bit T0IE                @ ((unsigned)&INTCON*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOCIF               : 1;
        unsigned	INTF                : 1;
        unsigned	TMR0IF              : 1;
        unsigned	IOCIE               : 1;
        unsigned	INTE                : 1;
        unsigned	TMR0IE              : 1;
        unsigned	PEIE                : 1;
        unsigned	GIE                 : 1;
    };
    struct {
        unsigned	                    : 2;
        unsigned	T0IF                : 1;
        unsigned	: 2;
        unsigned	T0IE                : 1;
    };
} INTCONbits @ 0x00B;
#endif

// Register: PORTA
volatile unsigned char           PORTA               @ 0x00C;
// bit and bitfield definitions
volatile bit RA0                 @ ((unsigned)&PORTA*8)+0;
volatile bit RA1                 @ ((unsigned)&PORTA*8)+1;
volatile bit RA2                 @ ((unsigned)&PORTA*8)+2;
volatile bit RA3                 @ ((unsigned)&PORTA*8)+3;
volatile bit RA4                 @ ((unsigned)&PORTA*8)+4;
volatile bit RA5                 @ ((unsigned)&PORTA*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RA0                 : 1;
        unsigned	RA1                 : 1;
        unsigned	RA2                 : 1;
        unsigned	RA3                 : 1;
        unsigned	RA4                 : 1;
        unsigned	RA5                 : 1;
        unsigned	                    : 1;
        unsigned	: 1;
    };
} PORTAbits @ 0x00C;
#endif

// Register: PORTC
volatile unsigned char           PORTC               @ 0x00E;
// bit and bitfield definitions
volatile bit RC0                 @ ((unsigned)&PORTC*8)+0;
volatile bit RC1                 @ ((unsigned)&PORTC*8)+1;
volatile bit RC2                 @ ((unsigned)&PORTC*8)+2;
volatile bit RC3                 @ ((unsigned)&PORTC*8)+3;
volatile bit RC4                 @ ((unsigned)&PORTC*8)+4;
volatile bit RC5                 @ ((unsigned)&PORTC*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RC0                 : 1;
        unsigned	RC1                 : 1;
        unsigned	RC2                 : 1;
        unsigned	RC3                 : 1;
        unsigned	RC4                 : 1;
        unsigned	RC5                 : 1;
        unsigned	                    : 1;
        unsigned	: 1;
    };
} PORTCbits @ 0x00E;
#endif

// Register: PIR1
volatile unsigned char           PIR1                @ 0x011;
// bit and bitfield definitions
// TMR1 Overflow Interrupt Flag bit
volatile bit TMR1IF              @ ((unsigned)&PIR1*8)+0;
// TMR2 to PR2 Match Interrupt Flag bit
volatile bit TMR2IF              @ ((unsigned)&PIR1*8)+1;
// CCP1 Interrupt Flag bit
volatile bit CCP1IF              @ ((unsigned)&PIR1*8)+2;
// Master Synchronous Serial Port (MSSP) Interrupt Flag bit
volatile bit SSP1IF              @ ((unsigned)&PIR1*8)+3;
// EUSART Transmit Interrupt Flag bit
volatile bit TXIF                @ ((unsigned)&PIR1*8)+4;
// EUSART Receive Interrupt Flag bit
volatile bit RCIF                @ ((unsigned)&PIR1*8)+5;
// A/D Converter Interrupt Flag bit
volatile bit ADIF                @ ((unsigned)&PIR1*8)+6;
// Timer1 Gate Interrupt Flag bit
volatile bit TMR1GIF             @ ((unsigned)&PIR1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TMR1IF              : 1;
        unsigned	TMR2IF              : 1;
        unsigned	CCP1IF              : 1;
        unsigned	SSP1IF              : 1;
        unsigned	TXIF                : 1;
        unsigned	RCIF                : 1;
        unsigned	ADIF                : 1;
        unsigned	TMR1GIF             : 1;
    };
} PIR1bits @ 0x011;
#endif

// Register: PIR2
volatile unsigned char           PIR2                @ 0x012;
// bit and bitfield definitions
volatile bit CCP2IF              @ ((unsigned)&PIR2*8)+0;
volatile bit BCL1IF              @ ((unsigned)&PIR2*8)+3;
volatile bit EEIF                @ ((unsigned)&PIR2*8)+4;
volatile bit C1IF                @ ((unsigned)&PIR2*8)+5;
volatile bit C2IF                @ ((unsigned)&PIR2*8)+6;
volatile bit OSFIF               @ ((unsigned)&PIR2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP2IF              : 1;
        unsigned	                    : 1;
        unsigned	: 1;
        unsigned	BCL1IF              : 1;
        unsigned	EEIF                : 1;
        unsigned	C1IF                : 1;
        unsigned	C2IF                : 1;
        unsigned	OSFIF               : 1;
    };
} PIR2bits @ 0x012;
#endif

// Register: PIR3
volatile unsigned char           PIR3                @ 0x013;
// bit and bitfield definitions
volatile bit TMR4IF              @ ((unsigned)&PIR3*8)+1;
volatile bit TMR6IF              @ ((unsigned)&PIR3*8)+3;
volatile bit CCP3IF              @ ((unsigned)&PIR3*8)+4;
volatile bit CCP4IF              @ ((unsigned)&PIR3*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 1;
        unsigned	TMR4IF              : 1;
        unsigned	: 1;
        unsigned	TMR6IF              : 1;
        unsigned	CCP3IF              : 1;
        unsigned	CCP4IF              : 1;
    };
} PIR3bits @ 0x013;
#endif

// Register: TMR0
volatile unsigned char           TMR0                @ 0x015;
// bit and bitfield definitions
// bit and bitfield definitions

// Register: TMR1L
volatile unsigned char           TMR1L               @ 0x016;
// bit and bitfield definitions

// Register: TMR1H
volatile unsigned char           TMR1H               @ 0x017;
// bit and bitfield definitions

// Register: TMR1
volatile unsigned int            TMR1                @ 0x016;

// Register: T1CON
volatile unsigned char           T1CON               @ 0x018;
// bit and bitfield definitions
volatile bit TMR1ON              @ ((unsigned)&T1CON*8)+0;
volatile bit nT1SYNC             @ ((unsigned)&T1CON*8)+2;
volatile bit T1OSCEN             @ ((unsigned)&T1CON*8)+3;
volatile bit T1CKPS0             @ ((unsigned)&T1CON*8)+4;
volatile bit T1CKPS1             @ ((unsigned)&T1CON*8)+5;
volatile bit TMR1CS0             @ ((unsigned)&T1CON*8)+6;
volatile bit TMR1CS1             @ ((unsigned)&T1CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TMR1ON              : 1;
        unsigned	                    : 1;
        unsigned	nT1SYNC             : 1;
        unsigned	T1OSCEN             : 1;
        unsigned	T1CKPS0             : 1;
        unsigned	T1CKPS1             : 1;
        unsigned	TMR1CS0             : 1;
        unsigned	TMR1CS1             : 1;
    };
    struct {
        unsigned	: 4;
        unsigned	T1CKPS              : 2;
        unsigned	TMR1CS              : 2;
    };
} T1CONbits @ 0x018;
#endif

// Register: T1GCON
volatile unsigned char           T1GCON              @ 0x019;
// bit and bitfield definitions
volatile bit T1GSS0              @ ((unsigned)&T1GCON*8)+0;
volatile bit T1GSS1              @ ((unsigned)&T1GCON*8)+1;
volatile bit T1GVAL              @ ((unsigned)&T1GCON*8)+2;
volatile bit T1GGO               @ ((unsigned)&T1GCON*8)+3;
volatile bit T1GSPM              @ ((unsigned)&T1GCON*8)+4;
volatile bit T1GTM               @ ((unsigned)&T1GCON*8)+5;
volatile bit T1GPOL              @ ((unsigned)&T1GCON*8)+6;
volatile bit TMR1GE              @ ((unsigned)&T1GCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	T1GSS0              : 1;
        unsigned	T1GSS1              : 1;
        unsigned	T1GVAL              : 1;
        unsigned	T1GGO               : 1;
        unsigned	T1GSPM              : 1;
        unsigned	T1GTM               : 1;
        unsigned	T1GPOL              : 1;
        unsigned	TMR1GE              : 1;
    };
    struct {
        unsigned	T1GSS               : 2;
    };
} T1GCONbits @ 0x019;
#endif

// Register: TMR2
volatile unsigned char           TMR2                @ 0x01A;
// bit and bitfield definitions

// Register: PR2
volatile unsigned char           PR2                 @ 0x01B;
// bit and bitfield definitions

// Register: T2CON
volatile unsigned char           T2CON               @ 0x01C;
// bit and bitfield definitions
volatile bit T2CKPS0             @ ((unsigned)&T2CON*8)+0;
volatile bit T2CKPS1             @ ((unsigned)&T2CON*8)+1;
volatile bit TMR2ON              @ ((unsigned)&T2CON*8)+2;
volatile bit T2OUTPS0            @ ((unsigned)&T2CON*8)+3;
volatile bit T2OUTPS1            @ ((unsigned)&T2CON*8)+4;
volatile bit T2OUTPS2            @ ((unsigned)&T2CON*8)+5;
volatile bit T2OUTPS3            @ ((unsigned)&T2CON*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	T2CKPS0             : 1;
        unsigned	T2CKPS1             : 1;
        unsigned	TMR2ON              : 1;
        unsigned	T2OUTPS0            : 1;
        unsigned	T2OUTPS1            : 1;
        unsigned	T2OUTPS2            : 1;
        unsigned	T2OUTPS3            : 1;
    };
    struct {
        unsigned	T2CKPS              : 2;
        unsigned	                    : 1;
        unsigned	T2OUTPS             : 4;
    };
} T2CONbits @ 0x01C;
#endif

// Register: CPSCON0
volatile unsigned char           CPSCON0             @ 0x01E;
// bit and bitfield definitions
volatile bit T0XCS               @ ((unsigned)&CPSCON0*8)+0;
volatile bit CPSOUT              @ ((unsigned)&CPSCON0*8)+1;
volatile bit CPSRNG0             @ ((unsigned)&CPSCON0*8)+2;
volatile bit CPSRNG1             @ ((unsigned)&CPSCON0*8)+3;
volatile bit CPSRM               @ ((unsigned)&CPSCON0*8)+6;
volatile bit CPSON               @ ((unsigned)&CPSCON0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	T0XCS               : 1;
        unsigned	CPSOUT              : 1;
        unsigned	CPSRNG0             : 1;
        unsigned	CPSRNG1             : 1;
        unsigned	                    : 2;
        unsigned	CPSRM               : 1;
        unsigned	CPSON               : 1;
    };
    struct {
        unsigned	: 2;
        unsigned	CPSRNG              : 2;
    };
} CPSCON0bits @ 0x01E;
#endif

// Register: CPSCON1
volatile unsigned char           CPSCON1             @ 0x01F;
// bit and bitfield definitions
volatile bit CPSCH0              @ ((unsigned)&CPSCON1*8)+0;
volatile bit CPSCH1              @ ((unsigned)&CPSCON1*8)+1;
volatile bit CPSCH2              @ ((unsigned)&CPSCON1*8)+2;
volatile bit CPSCH3              @ ((unsigned)&CPSCON1*8)+3;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CPSCH0              : 1;
        unsigned	CPSCH1              : 1;
        unsigned	CPSCH2              : 1;
        unsigned	CPSCH3              : 1;
    };
    struct {
        unsigned	CPSCH               : 3;
        unsigned	                    : 1;
    };
} CPSCON1bits @ 0x01F;
#endif

//
// Special function register definitions: Bank 1
//


// Register: TRISA
// PORTA Data Direction Control Register
volatile unsigned char           TRISA               @ 0x08C;
// bit and bitfield definitions
volatile bit TRISA0              @ ((unsigned)&TRISA*8)+0;
volatile bit TRISA1              @ ((unsigned)&TRISA*8)+1;
volatile bit TRISA2              @ ((unsigned)&TRISA*8)+2;
volatile bit TRISA3              @ ((unsigned)&TRISA*8)+3;
volatile bit TRISA4              @ ((unsigned)&TRISA*8)+4;
volatile bit TRISA5              @ ((unsigned)&TRISA*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TRISA0              : 1;
        unsigned	TRISA1              : 1;
        unsigned	TRISA2              : 1;
        unsigned	TRISA3              : 1;
        unsigned	TRISA4              : 1;
        unsigned	TRISA5              : 1;
        unsigned	                    : 1;
        unsigned	: 1;
    };
    struct {
        unsigned	TRISA               : 6;
        unsigned	: 2;
    };
} TRISAbits @ 0x08C;
#endif

// Register: TRISC
// PORTB Data Direction Control Register
volatile unsigned char           TRISC               @ 0x08E;
// bit and bitfield definitions
volatile bit TRISC0              @ ((unsigned)&TRISC*8)+0;
volatile bit TRISC1              @ ((unsigned)&TRISC*8)+1;
volatile bit TRISC2              @ ((unsigned)&TRISC*8)+2;
volatile bit TRISC3              @ ((unsigned)&TRISC*8)+3;
volatile bit TRISC4              @ ((unsigned)&TRISC*8)+4;
volatile bit TRISC5              @ ((unsigned)&TRISC*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TRISC0              : 1;
        unsigned	TRISC1              : 1;
        unsigned	TRISC2              : 1;
        unsigned	TRISC3              : 1;
        unsigned	TRISC4              : 1;
        unsigned	TRISC5              : 1;
        unsigned	                    : 1;
        unsigned	: 1;
    };
    struct {
        unsigned	TRISC               : 6;
        unsigned	: 2;
    };
} TRISCbits @ 0x08E;
#endif

// Register: PIE1
// Peripheral Interrupt Enable Register 1
volatile unsigned char           PIE1                @ 0x091;
// bit and bitfield definitions
// TMR1 Overflow Interrupt Enable bit
volatile bit TMR1IE              @ ((unsigned)&PIE1*8)+0;
// TMR2 to PR2 Match Interrupt Enable bit
volatile bit TMR2IE              @ ((unsigned)&PIE1*8)+1;
// CCP1 Interrupt Enable bit
volatile bit CCP1IE              @ ((unsigned)&PIE1*8)+2;
// Master Synchronous Serial Port (MSSP) Interrupt Enable bit
volatile bit SSP1IE              @ ((unsigned)&PIE1*8)+3;
// EUSART Transmit Interrupt Enable bit
volatile bit TXIE                @ ((unsigned)&PIE1*8)+4;
// EUSART Receive Interrupt Enable bit
volatile bit RCIE                @ ((unsigned)&PIE1*8)+5;
// A/D Converter Interrupt Enable bit
volatile bit ADIE                @ ((unsigned)&PIE1*8)+6;
// Timer1 Gate Interrupt Enable bit
volatile bit TMR1GIE             @ ((unsigned)&PIE1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TMR1IE              : 1;
        unsigned	TMR2IE              : 1;
        unsigned	CCP1IE              : 1;
        unsigned	SSP1IE              : 1;
        unsigned	TXIE                : 1;
        unsigned	RCIE                : 1;
        unsigned	ADIE                : 1;
        unsigned	TMR1GIE             : 1;
    };
} PIE1bits @ 0x091;
#endif

// Register: PIE2
// Peripheral Interrupt Enable Register 2
volatile unsigned char           PIE2                @ 0x092;
// bit and bitfield definitions
volatile bit CCP2IE              @ ((unsigned)&PIE2*8)+0;
// MSSP Bus Collision Interrupt Interrupt Enable bit
volatile bit BCL1IE              @ ((unsigned)&PIE2*8)+3;
// EEPROM Write Completion Interrupt Enable bit
volatile bit EEIE                @ ((unsigned)&PIE2*8)+4;
// Comparator C1 Interrupt Enable bit
volatile bit C1IE                @ ((unsigned)&PIE2*8)+5;
// Comparator C2 Interrupt Enable bit
volatile bit C2IE                @ ((unsigned)&PIE2*8)+6;
// CCP2 Interrupt Enable bit
volatile bit OSFIE               @ ((unsigned)&PIE2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP2IE              : 1;
        unsigned	                    : 1;
        unsigned	: 1;
        unsigned	BCL1IE              : 1;
        unsigned	EEIE                : 1;
        unsigned	C1IE                : 1;
        unsigned	C2IE                : 1;
        unsigned	OSFIE               : 1;
    };
} PIE2bits @ 0x092;
#endif

// Register: PIE3
volatile unsigned char           PIE3                @ 0x093;
// bit and bitfield definitions
volatile bit TMR4IE              @ ((unsigned)&PIE3*8)+1;
volatile bit TMR6IE              @ ((unsigned)&PIE3*8)+3;
volatile bit CCP3IE              @ ((unsigned)&PIE3*8)+4;
volatile bit CCP4IE              @ ((unsigned)&PIE3*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 1;
        unsigned	TMR4IE              : 1;
        unsigned	: 1;
        unsigned	TMR6IE              : 1;
        unsigned	CCP3IE              : 1;
        unsigned	CCP4IE              : 1;
    };
} PIE3bits @ 0x093;
#endif

// Register: OPTION_REG
// Option Register
volatile unsigned char           OPTION_REG          @ 0x095;
// bit and bitfield definitions
// Prescaler Rate Select bits
volatile bit PS0                 @ ((unsigned)&OPTION_REG*8)+0;
// Prescaler Rate Select bits
volatile bit PS1                 @ ((unsigned)&OPTION_REG*8)+1;
// Prescaler Rate Select bits
volatile bit PS2                 @ ((unsigned)&OPTION_REG*8)+2;
// Prescaler Active bit
volatile bit PSA                 @ ((unsigned)&OPTION_REG*8)+3;
// TMR0 Source Edge Select bit
volatile bit TMR0SE              @ ((unsigned)&OPTION_REG*8)+4;
// TMR0 Clock Source Select bit
volatile bit TMR0CS              @ ((unsigned)&OPTION_REG*8)+5;
// Interrupt Edge Select bit
volatile bit INTEDG              @ ((unsigned)&OPTION_REG*8)+6;
// Weak Pull-up Enable bit
volatile bit nWPUEN              @ ((unsigned)&OPTION_REG*8)+7;
volatile bit T0SE                @ ((unsigned)&OPTION_REG*8)+4;
volatile bit T0CS                @ ((unsigned)&OPTION_REG*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PS0                 : 1;
        unsigned	PS1                 : 1;
        unsigned	PS2                 : 1;
        unsigned	PSA                 : 1;
        unsigned	TMR0SE              : 1;
        unsigned	TMR0CS              : 1;
        unsigned	INTEDG              : 1;
        unsigned	nWPUEN              : 1;
    };
    struct {
        unsigned	PS                  : 3;
        unsigned	                    : 1;
        unsigned	T0SE                : 1;
        unsigned	T0CS                : 1;
    };
} OPTION_REGbits @ 0x095;
#endif

// Register: PCON
// Power Control Register
volatile unsigned char           PCON                @ 0x096;
// bit and bitfield definitions
// Brown-out Reset Status bit
volatile bit nBOR                @ ((unsigned)&PCON*8)+0;
// Power-on Reset Status bit
volatile bit nPOR                @ ((unsigned)&PCON*8)+1;
// RESET Instruction Flag bit
volatile bit nRI                 @ ((unsigned)&PCON*8)+2;
// MCLR Reset Flag bit
volatile bit nRMCLR              @ ((unsigned)&PCON*8)+3;
// Stack Underflow Flag bit
volatile bit STKUNF              @ ((unsigned)&PCON*8)+6;
// Stack Overflow Flag bit
volatile bit STKOVF              @ ((unsigned)&PCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	nBOR                : 1;
        unsigned	nPOR                : 1;
        unsigned	nRI                 : 1;
        unsigned	nRMCLR              : 1;
        unsigned	                    : 1;
        unsigned	: 1;
        unsigned	STKUNF              : 1;
        unsigned	STKOVF              : 1;
    };
} PCONbits @ 0x096;
#endif

// Register: WDTCON
// Watchdog Timer Control Register
volatile unsigned char           WDTCON              @ 0x097;
// bit and bitfield definitions
// Software Enable/Disable for Watch Dog Timer bit
volatile bit SWDTEN              @ ((unsigned)&WDTCON*8)+0;
// Watchdog Timer Period Select bits
volatile bit WDTPS0              @ ((unsigned)&WDTCON*8)+1;
// Watchdog Timer Period Select bits
volatile bit WDTPS1              @ ((unsigned)&WDTCON*8)+2;
// Watchdog Timer Period Select bits
volatile bit WDTPS2              @ ((unsigned)&WDTCON*8)+3;
// Watchdog Timer Period Select bits
volatile bit WDTPS3              @ ((unsigned)&WDTCON*8)+4;
// Watchdog Timer Period Select bits
volatile bit WDTPS4              @ ((unsigned)&WDTCON*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SWDTEN              : 1;
        unsigned	WDTPS0              : 1;
        unsigned	WDTPS1              : 1;
        unsigned	WDTPS2              : 1;
        unsigned	WDTPS3              : 1;
        unsigned	WDTPS4              : 1;
    };
    struct {
        unsigned	                    : 1;
        unsigned	WDTPS               : 5;
    };
} WDTCONbits @ 0x097;
#endif

// Register: OSCTUNE
// Oscillator Tuning Register
volatile unsigned char           OSCTUNE             @ 0x098;
// bit and bitfield definitions
// Frequency Tuning bits
volatile bit TUN0                @ ((unsigned)&OSCTUNE*8)+0;
// Frequency Tuning bits
volatile bit TUN1                @ ((unsigned)&OSCTUNE*8)+1;
// Frequency Tuning bits
volatile bit TUN2                @ ((unsigned)&OSCTUNE*8)+2;
// Frequency Tuning bits
volatile bit TUN3                @ ((unsigned)&OSCTUNE*8)+3;
// Frequency Tuning bits
volatile bit TUN4                @ ((unsigned)&OSCTUNE*8)+4;
// Frequency Tuning bits
volatile bit TUN5                @ ((unsigned)&OSCTUNE*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TUN0                : 1;
        unsigned	TUN1                : 1;
        unsigned	TUN2                : 1;
        unsigned	TUN3                : 1;
        unsigned	TUN4                : 1;
        unsigned	TUN5                : 1;
    };
    struct {
        unsigned	TUN                 : 6;
    };
} OSCTUNEbits @ 0x098;
#endif

// Register: OSCCON
// Oscillator Control Register
volatile unsigned char           OSCCON              @ 0x099;
// bit and bitfield definitions
// System clock select bit
volatile bit SCS0                @ ((unsigned)&OSCCON*8)+0;
// System clock select bit
volatile bit SCS1                @ ((unsigned)&OSCCON*8)+1;
// Internal Oscillator Frequency Select bits
volatile bit IRCF0               @ ((unsigned)&OSCCON*8)+3;
// Internal Oscillator Frequency Select bits
volatile bit IRCF1               @ ((unsigned)&OSCCON*8)+4;
// Internal Oscillator Frequency Select bits
volatile bit IRCF2               @ ((unsigned)&OSCCON*8)+5;
// Internal Oscillator Frequency Select bits
volatile bit IRCF3               @ ((unsigned)&OSCCON*8)+6;
// Software PLL Enable bit
volatile bit SPLLEN              @ ((unsigned)&OSCCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SCS0                : 1;
        unsigned	SCS1                : 1;
        unsigned	                    : 1;
        unsigned	IRCF0               : 1;
        unsigned	IRCF1               : 1;
        unsigned	IRCF2               : 1;
        unsigned	IRCF3               : 1;
        unsigned	SPLLEN              : 1;
    };
    struct {
        unsigned	SCS                 : 2;
        unsigned	: 1;
        unsigned	IRCF                : 4;
    };
} OSCCONbits @ 0x099;
#endif

// Register: OSCSTAT
// Oscillator Status Register
volatile unsigned char           OSCSTAT             @ 0x09A;
// bit and bitfield definitions
// Low Freqency Internal Oscillator Ready bit
volatile bit HFIOFS              @ ((unsigned)&OSCSTAT*8)+0;
// Low Freqency Internal Oscillator Ready bit
volatile bit LFIOFR              @ ((unsigned)&OSCSTAT*8)+1;
// Medium Freqency Internal Oscillator Ready bit
volatile bit MFIOFR              @ ((unsigned)&OSCSTAT*8)+2;
// High Freqency Internal Oscillator Status Locked bit
volatile bit HFIOFL              @ ((unsigned)&OSCSTAT*8)+3;
// High Freqency Internal Oscillator Ready bit
volatile bit HFIOFR              @ ((unsigned)&OSCSTAT*8)+4;
// Oscillator Start-up Time-out Status bit
volatile bit OSTS                @ ((unsigned)&OSCSTAT*8)+5;
// 4x PLL Ready bit
volatile bit PLLR                @ ((unsigned)&OSCSTAT*8)+6;
// Timer1 Oscillator Ready bit
volatile bit T1OSCR              @ ((unsigned)&OSCSTAT*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	HFIOFS              : 1;
        unsigned	LFIOFR              : 1;
        unsigned	MFIOFR              : 1;
        unsigned	HFIOFL              : 1;
        unsigned	HFIOFR              : 1;
        unsigned	OSTS                : 1;
        unsigned	PLLR                : 1;
        unsigned	T1OSCR              : 1;
    };
} OSCSTATbits @ 0x09A;
#endif
// bit and bitfield definitions

// Register: ADRESL
// A/D Result Register LSB
volatile unsigned char           ADRESL              @ 0x09B;
// bit and bitfield definitions

// Register: ADRESH
// A/D Result Register MSB
volatile unsigned char           ADRESH              @ 0x09C;
// bit and bitfield definitions

// Register: ADRES
volatile unsigned int            ADRES               @ 0x09B;

// Register: ADCON0
// Analog-to-Digital Control Register 0
volatile unsigned char           ADCON0              @ 0x09D;
// bit and bitfield definitions
// A/D Module Enable bit
volatile bit ADON                @ ((unsigned)&ADCON0*8)+0;
// A/D Conversion Status bit
volatile bit GO_nDONE            @ ((unsigned)&ADCON0*8)+1;
// Analog Channel Select bits
volatile bit CHS0                @ ((unsigned)&ADCON0*8)+2;
// Analog Channel Select bits
volatile bit CHS1                @ ((unsigned)&ADCON0*8)+3;
// Analog Channel Select bits
volatile bit CHS2                @ ((unsigned)&ADCON0*8)+4;
// Analog Channel Select bits
volatile bit CHS3                @ ((unsigned)&ADCON0*8)+5;
// Analog Channel Select bits
volatile bit CHS4                @ ((unsigned)&ADCON0*8)+6;
// A/D Conversion Status bit
volatile bit ADGO                @ ((unsigned)&ADCON0*8)+1;
// A/D Conversion Status bit
volatile bit GO                  @ ((unsigned)&ADCON0*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ADON                : 1;
        unsigned	GO_nDONE            : 1;
        unsigned	CHS0                : 1;
        unsigned	CHS1                : 1;
        unsigned	CHS2                : 1;
        unsigned	CHS3                : 1;
        unsigned	CHS4                : 1;
        unsigned	                    : 1;
    };
    struct {
        unsigned	: 1;
        unsigned	ADGO                : 1;
        unsigned	CHS                 : 5;
    };
    struct {
        unsigned	: 1;
        unsigned	GO                  : 1;
    };
} ADCON0bits @ 0x09D;
#endif

// Register: ADCON1
// Analog-to-Digital Control Register 1
volatile unsigned char           ADCON1              @ 0x09E;
// bit and bitfield definitions
// A/D Positive Voltage Reference Configuration
volatile bit ADPREF0             @ ((unsigned)&ADCON1*8)+0;
// A/D Positive Voltage Reference Configuration
volatile bit ADPREF1             @ ((unsigned)&ADCON1*8)+1;
// A/D Negative Voltage Reference Configuration
volatile bit ADNREF              @ ((unsigned)&ADCON1*8)+2;
// A/D Conversion Clock Select bits
volatile bit ADCS0               @ ((unsigned)&ADCON1*8)+4;
// A/D Conversion Clock Select bits
volatile bit ADCS1               @ ((unsigned)&ADCON1*8)+5;
// A/D Conversion Clock Select bits
volatile bit ADCS2               @ ((unsigned)&ADCON1*8)+6;
// A/D Result Format Select bit
volatile bit ADFM                @ ((unsigned)&ADCON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ADPREF0             : 1;
        unsigned	ADPREF1             : 1;
        unsigned	ADNREF              : 1;
        unsigned	                    : 1;
        unsigned	ADCS0               : 1;
        unsigned	ADCS1               : 1;
        unsigned	ADCS2               : 1;
        unsigned	ADFM                : 1;
    };
    struct {
        unsigned	ADPREF              : 2;
        unsigned	: 2;
        unsigned	ADCS                : 3;
    };
} ADCON1bits @ 0x09E;
#endif

//
// Special function register definitions: Bank 2
//


// Register: LATA
volatile unsigned char           LATA                @ 0x10C;
// bit and bitfield definitions
volatile bit LATA0               @ ((unsigned)&LATA*8)+0;
volatile bit LATA1               @ ((unsigned)&LATA*8)+1;
volatile bit LATA2               @ ((unsigned)&LATA*8)+2;
volatile bit LATA4               @ ((unsigned)&LATA*8)+4;
volatile bit LATA5               @ ((unsigned)&LATA*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LATA0               : 1;
        unsigned	LATA1               : 1;
        unsigned	LATA2               : 1;
        unsigned	                    : 1;
        unsigned	LATA4               : 1;
        unsigned	LATA5               : 1;
        unsigned	: 1;
        unsigned	: 1;
    };
    struct {
        unsigned	LATA                : 6;
        unsigned	: 2;
    };
} LATAbits @ 0x10C;
#endif

// Register: LATC
volatile unsigned char           LATC                @ 0x10E;
// bit and bitfield definitions
volatile bit LATC0               @ ((unsigned)&LATC*8)+0;
volatile bit LATC1               @ ((unsigned)&LATC*8)+1;
volatile bit LATC2               @ ((unsigned)&LATC*8)+2;
volatile bit LATC3               @ ((unsigned)&LATC*8)+3;
volatile bit LATC4               @ ((unsigned)&LATC*8)+4;
volatile bit LATC5               @ ((unsigned)&LATC*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LATC0               : 1;
        unsigned	LATC1               : 1;
        unsigned	LATC2               : 1;
        unsigned	LATC3               : 1;
        unsigned	LATC4               : 1;
        unsigned	LATC5               : 1;
        unsigned	                    : 1;
        unsigned	: 1;
    };
    struct {
        unsigned	LATC                : 6;
        unsigned	: 2;
    };
} LATCbits @ 0x10E;
#endif

// Register: CM1CON0
volatile unsigned char           CM1CON0             @ 0x111;
// bit and bitfield definitions
// Comparator Output Synchronous Mode bit
volatile bit C1SYNC              @ ((unsigned)&CM1CON0*8)+0;
// Comparator Hysteresis Enable bit
volatile bit C1HYS               @ ((unsigned)&CM1CON0*8)+1;
// Comparator Speed/Power Select bit
volatile bit C1SP                @ ((unsigned)&CM1CON0*8)+2;
// Comparator Output Polarity Select bit
volatile bit C1POL               @ ((unsigned)&CM1CON0*8)+4;
// Comparator Output Enable bit
volatile bit C1OE                @ ((unsigned)&CM1CON0*8)+5;
// Comparator Output bit
volatile bit C1OUT               @ ((unsigned)&CM1CON0*8)+6;
// Comparator Enable bit
volatile bit C1ON                @ ((unsigned)&CM1CON0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C1SYNC              : 1;
        unsigned	C1HYS               : 1;
        unsigned	C1SP                : 1;
        unsigned	                    : 1;
        unsigned	C1POL               : 1;
        unsigned	C1OE                : 1;
        unsigned	C1OUT               : 1;
        unsigned	C1ON                : 1;
    };
} CM1CON0bits @ 0x111;
#endif

// Register: CM1CON1
volatile unsigned char           CM1CON1             @ 0x112;
// bit and bitfield definitions
// Comparator Negative Input Channel Select bits
volatile bit C1NCH0              @ ((unsigned)&CM1CON1*8)+0;
// Comparator Negative Input Channel Select bits
volatile bit C1NCH1              @ ((unsigned)&CM1CON1*8)+1;
// Comparator Positive Input Channel Select bits
volatile bit C1PCH0              @ ((unsigned)&CM1CON1*8)+4;
// Comparator Positive Input Channel Select bits
volatile bit C1PCH1              @ ((unsigned)&CM1CON1*8)+5;
// Comparator Interrupt on Negative going edge Enable bits
volatile bit C1INTN              @ ((unsigned)&CM1CON1*8)+6;
// Comparator Interrupt on Positive going edge Enable bits
volatile bit C1INTP              @ ((unsigned)&CM1CON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C1NCH0              : 1;
        unsigned	C1NCH1              : 1;
        unsigned	                    : 2;
        unsigned	C1PCH0              : 1;
        unsigned	C1PCH1              : 1;
        unsigned	C1INTN              : 1;
        unsigned	C1INTP              : 1;
    };
    struct {
        unsigned	C1NCH               : 2;
        unsigned	: 2;
        unsigned	C1PCH               : 2;
    };
} CM1CON1bits @ 0x112;
#endif

// Register: CM2CON0
volatile unsigned char           CM2CON0             @ 0x113;
// bit and bitfield definitions
volatile bit C2SYNC              @ ((unsigned)&CM2CON0*8)+0;
volatile bit C2HYS               @ ((unsigned)&CM2CON0*8)+1;
volatile bit C2SP                @ ((unsigned)&CM2CON0*8)+2;
volatile bit C2POL               @ ((unsigned)&CM2CON0*8)+4;
volatile bit C2OE                @ ((unsigned)&CM2CON0*8)+5;
volatile bit C2OUT               @ ((unsigned)&CM2CON0*8)+6;
volatile bit C2ON                @ ((unsigned)&CM2CON0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C2SYNC              : 1;
        unsigned	C2HYS               : 1;
        unsigned	C2SP                : 1;
        unsigned	                    : 1;
        unsigned	C2POL               : 1;
        unsigned	C2OE                : 1;
        unsigned	C2OUT               : 1;
        unsigned	C2ON                : 1;
    };
} CM2CON0bits @ 0x113;
#endif

// Register: CM2CON1
volatile unsigned char           CM2CON1             @ 0x114;
// bit and bitfield definitions
// Comparator Negative Input Channel Select bits
volatile bit C2NCH0              @ ((unsigned)&CM2CON1*8)+0;
// Comparator Negative Input Channel Select bits
volatile bit C2NCH1              @ ((unsigned)&CM2CON1*8)+1;
// Comparator Positive Input Channel Select bits
volatile bit C2PCH0              @ ((unsigned)&CM2CON1*8)+4;
// Comparator Positive Input Channel Select bits
volatile bit C2PCH1              @ ((unsigned)&CM2CON1*8)+5;
// Comparator Interrupt on Negative going edge Enable bits
volatile bit C2INTN              @ ((unsigned)&CM2CON1*8)+6;
// Comparator Interrupt on Positive going edge Enable bits
volatile bit C2INTP              @ ((unsigned)&CM2CON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C2NCH0              : 1;
        unsigned	C2NCH1              : 1;
        unsigned	                    : 2;
        unsigned	C2PCH0              : 1;
        unsigned	C2PCH1              : 1;
        unsigned	C2INTN              : 1;
        unsigned	C2INTP              : 1;
    };
    struct {
        unsigned	C2NCH               : 2;
        unsigned	: 2;
        unsigned	C2PCH               : 2;
    };
} CM2CON1bits @ 0x114;
#endif

// Register: CMOUT
// Comparator Output Register
volatile unsigned char           CMOUT               @ 0x115;
// bit and bitfield definitions
volatile bit MC1OUT              @ ((unsigned)&CMOUT*8)+0;
volatile bit MC2OUT              @ ((unsigned)&CMOUT*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	MC1OUT              : 1;
        unsigned	MC2OUT              : 1;
    };
} CMOUTbits @ 0x115;
#endif

// Register: BORCON
// Brown-out Reset Control Register
volatile unsigned char           BORCON              @ 0x116;
// bit and bitfield definitions
// Brown-out Reset Circuit Ready Status bit
volatile bit BORRDY              @ ((unsigned)&BORCON*8)+0;
// Software Brown Out Reset Enable bit
volatile bit SBOREN              @ ((unsigned)&BORCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BORRDY              : 1;
        unsigned	                    : 6;
        unsigned	SBOREN              : 1;
    };
} BORCONbits @ 0x116;
#endif

// Register: FVRCON
// Fixed Voltage Reference Control Register
volatile unsigned char           FVRCON              @ 0x117;
// bit and bitfield definitions
// A/D Converter Fixed Voltage Reference Selection
volatile bit ADFVR0              @ ((unsigned)&FVRCON*8)+0;
// A/D Converter Fixed Voltage Reference Selection
volatile bit ADFVR1              @ ((unsigned)&FVRCON*8)+1;
// Comparator and D/A Converter Fixed Voltage Reference Selection
volatile bit CDAFVR0             @ ((unsigned)&FVRCON*8)+2;
// Comparator and D/A Converter Fixed Voltage Reference Selection
volatile bit CDAFVR1             @ ((unsigned)&FVRCON*8)+3;
// Temperature Indicator Range Selection
volatile bit TSRNG               @ ((unsigned)&FVRCON*8)+4;
// Temperature Indicator Enable
volatile bit TSEN                @ ((unsigned)&FVRCON*8)+5;
// Fixed Voltage Reference Ready Flag
volatile bit FVRRDY              @ ((unsigned)&FVRCON*8)+6;
// Fixed Voltage Reference Enable
volatile bit FVREN               @ ((unsigned)&FVRCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ADFVR0              : 1;
        unsigned	ADFVR1              : 1;
        unsigned	CDAFVR0             : 1;
        unsigned	CDAFVR1             : 1;
        unsigned	TSRNG               : 1;
        unsigned	TSEN                : 1;
        unsigned	FVRRDY              : 1;
        unsigned	FVREN               : 1;
    };
    struct {
        unsigned	ADFVR               : 2;
        unsigned	CDAFVR              : 2;
    };
} FVRCONbits @ 0x117;
#endif

// Register: DACCON0
// Voltage Reference Control Register 0
volatile unsigned char           DACCON0             @ 0x118;
// bit and bitfield definitions
// DAC1 Negative Source Select bits
volatile bit DACNSS              @ ((unsigned)&DACCON0*8)+0;
// DAC1 Positive Source Select bits
volatile bit DACPSS0             @ ((unsigned)&DACCON0*8)+2;
// DAC1 Positive Source Select bits
volatile bit DACPSS1             @ ((unsigned)&DACCON0*8)+3;
// DAC1 Voltage Output Enable bit
volatile bit DACOE               @ ((unsigned)&DACCON0*8)+5;
// DAC 1 Low Power Voltage State Select bit
volatile bit DACLPS              @ ((unsigned)&DACCON0*8)+6;
// DAC 1 Enable bit
volatile bit DACEN               @ ((unsigned)&DACCON0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	DACNSS              : 1;
        unsigned	                    : 1;
        unsigned	DACPSS0             : 1;
        unsigned	DACPSS1             : 1;
        unsigned	: 1;
        unsigned	DACOE               : 1;
        unsigned	DACLPS              : 1;
        unsigned	DACEN               : 1;
    };
    struct {
        unsigned	: 2;
        unsigned	DACPSS              : 2;
    };
} DACCON0bits @ 0x118;
#endif

// Register: DACCON1
// Voltage Reference Control Register 1
volatile unsigned char           DACCON1             @ 0x119;
// bit and bitfield definitions
// DAC1 Voltage Output Select bits
volatile bit DACR0               @ ((unsigned)&DACCON1*8)+0;
// DAC1 Voltage Output Select bits
volatile bit DACR1               @ ((unsigned)&DACCON1*8)+1;
// DAC1 Voltage Output Select bits
volatile bit DACR2               @ ((unsigned)&DACCON1*8)+2;
// DAC1 Voltage Output Select bits
volatile bit DACR3               @ ((unsigned)&DACCON1*8)+3;
// DAC1 Voltage Output Select bits
volatile bit DACR4               @ ((unsigned)&DACCON1*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	DACR0               : 1;
        unsigned	DACR1               : 1;
        unsigned	DACR2               : 1;
        unsigned	DACR3               : 1;
        unsigned	DACR4               : 1;
        unsigned	                    : 1;
    };
    struct {
        unsigned	DACR                : 5;
    };
} DACCON1bits @ 0x119;
#endif

// Register: SRCON0
// SR Latch Control Register 0
volatile unsigned char           SRCON0              @ 0x11A;
// bit and bitfield definitions
// Pulse Reset Input of the SR Latch
volatile bit SRPR                @ ((unsigned)&SRCON0*8)+0;
// Pulse Set Input of the SR Latch
volatile bit SRPS                @ ((unsigned)&SRCON0*8)+1;
// SR Latch Q Output Enable bit
volatile bit SRNQEN              @ ((unsigned)&SRCON0*8)+2;
// SR Latch Q Output Enable bit
volatile bit SRQEN               @ ((unsigned)&SRCON0*8)+3;
// SR Latch Clock divider bits
volatile bit SRCLK0              @ ((unsigned)&SRCON0*8)+4;
// SR Latch Clock divider bits
volatile bit SRCLK1              @ ((unsigned)&SRCON0*8)+5;
// SR Latch Clock divider bits
volatile bit SRCLK2              @ ((unsigned)&SRCON0*8)+6;
// SR Latch Enable bit
volatile bit SRLEN               @ ((unsigned)&SRCON0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SRPR                : 1;
        unsigned	SRPS                : 1;
        unsigned	SRNQEN              : 1;
        unsigned	SRQEN               : 1;
        unsigned	SRCLK0              : 1;
        unsigned	SRCLK1              : 1;
        unsigned	SRCLK2              : 1;
        unsigned	SRLEN               : 1;
    };
    struct {
        unsigned	                    : 4;
        unsigned	SRCLK               : 3;
    };
} SRCON0bits @ 0x11A;
#endif

// Register: SRCON1
// SR Latch Control Register 1
volatile unsigned char           SRCON1              @ 0x11B;
// bit and bitfield definitions
// SR Latch C1 Reset Enable bit
volatile bit SRRC1E              @ ((unsigned)&SRCON1*8)+0;
volatile bit SRRCKE              @ ((unsigned)&SRCON1*8)+2;
// SR Latch Peripheral Reset Enable bit
volatile bit SRRPE               @ ((unsigned)&SRCON1*8)+3;
// SR Latch C1 Set Enable bit
volatile bit SRSC1E              @ ((unsigned)&SRCON1*8)+4;
// SR Latch Set Clock Enable bit
volatile bit SRSCKE              @ ((unsigned)&SRCON1*8)+6;
// SR Latch Peripheral Set Enable bit
volatile bit SRSPE               @ ((unsigned)&SRCON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SRRC1E              : 1;
        unsigned	                    : 1;
        unsigned	SRRCKE              : 1;
        unsigned	SRRPE               : 1;
        unsigned	SRSC1E              : 1;
        unsigned	: 1;
        unsigned	SRSCKE              : 1;
        unsigned	SRSPE               : 1;
    };
} SRCON1bits @ 0x11B;
#endif

// Register: APFCON0
// Alternate Pin Function Control Register
volatile unsigned char           APFCON0             @ 0x11D;
// bit and bitfield definitions
volatile bit TXCKSEL             @ ((unsigned)&APFCON0*8)+2;
volatile bit T1GSEL              @ ((unsigned)&APFCON0*8)+3;
// Timer1 Gate Input Pin Selection
volatile bit SSSEL               @ ((unsigned)&APFCON0*8)+5;
// CCP3 Input/Output Pin Selection
volatile bit SDOSEL              @ ((unsigned)&APFCON0*8)+6;
volatile bit RXDTSEL             @ ((unsigned)&APFCON0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 1;
        unsigned	: 1;
        unsigned	TXCKSEL             : 1;
        unsigned	T1GSEL              : 1;
        unsigned	: 1;
        unsigned	SSSEL               : 1;
        unsigned	SDOSEL              : 1;
        unsigned	RXDTSEL             : 1;
    };
} APFCON0bits @ 0x11D;
#endif

// Register: APFCON1
volatile unsigned char           APFCON1             @ 0x11E;
// bit and bitfield definitions
volatile bit CCP2SEL             @ ((unsigned)&APFCON1*8)+0;
volatile bit P2BSEL              @ ((unsigned)&APFCON1*8)+1;
volatile bit P1CSEL              @ ((unsigned)&APFCON1*8)+2;
volatile bit P1DSEL              @ ((unsigned)&APFCON1*8)+3;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP2SEL             : 1;
        unsigned	P2BSEL              : 1;
        unsigned	P1CSEL              : 1;
        unsigned	P1DSEL              : 1;
    };
} APFCON1bits @ 0x11E;
#endif

//
// Special function register definitions: Bank 3
//


// Register: ANSELA
volatile unsigned char           ANSELA              @ 0x18C;
// bit and bitfield definitions
volatile bit ANSA0               @ ((unsigned)&ANSELA*8)+0;
volatile bit ANSA1               @ ((unsigned)&ANSELA*8)+1;
volatile bit ANSA2               @ ((unsigned)&ANSELA*8)+2;
volatile bit ANSA4               @ ((unsigned)&ANSELA*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ANSA0               : 1;
        unsigned	ANSA1               : 1;
        unsigned	ANSA2               : 1;
        unsigned	                    : 1;
        unsigned	ANSA4               : 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 1;
    };
    struct {
        unsigned	ANSELA              : 5;
        unsigned	: 1;
    };
} ANSELAbits @ 0x18C;
#endif

// Register: ANSELC
volatile unsigned char           ANSELC              @ 0x18E;
// bit and bitfield definitions
volatile bit ANSC0               @ ((unsigned)&ANSELC*8)+0;
volatile bit ANSC1               @ ((unsigned)&ANSELC*8)+1;
volatile bit ANSC2               @ ((unsigned)&ANSELC*8)+2;
volatile bit ANSC3               @ ((unsigned)&ANSELC*8)+3;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ANSC0               : 1;
        unsigned	ANSC1               : 1;
        unsigned	ANSC2               : 1;
        unsigned	ANSC3               : 1;
        unsigned	                    : 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 1;
    };
    struct {
        unsigned	ANSELC              : 4;
        unsigned	: 4;
    };
} ANSELCbits @ 0x18E;
#endif
// bit and bitfield definitions

// Register: EEADRL
volatile unsigned char           EEADRL              @ 0x191;
// bit and bitfield definitions

// Register: EEADRH
volatile unsigned char           EEADRH              @ 0x192;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	EEADRH              : 7;
    };
} EEADRHbits @ 0x192;
#endif

// Register: EEADR
volatile unsigned int            EEADR               @ 0x191;
// bit and bitfield definitions

// Register: EEDATL
volatile unsigned char           EEDATL              @ 0x193;
volatile unsigned char           EEDATA              @ 0x193;
// bit and bitfield definitions

// Register: EEDATH
volatile unsigned char           EEDATH              @ 0x194;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	EEDATH              : 6;
    };
} EEDATHbits @ 0x194;
#endif

// Register: EEDAT
volatile unsigned int            EEDAT               @ 0x193;

// Register: EECON1
volatile unsigned char           EECON1              @ 0x195;
// bit and bitfield definitions
// Read Control bit
volatile bit RD                  @ ((unsigned)&EECON1*8)+0;
// Write Control bit
volatile bit WR                  @ ((unsigned)&EECON1*8)+1;
// Program/Erase Enable bit
volatile bit WREN                @ ((unsigned)&EECON1*8)+2;
// Sequence Error Flag bit
volatile bit WRERR               @ ((unsigned)&EECON1*8)+3;
// Program FLASH Erase Enable bit
volatile bit FREE                @ ((unsigned)&EECON1*8)+4;
// Load Write Latches Only bit
volatile bit LWLO                @ ((unsigned)&EECON1*8)+5;
// FLASH Program / Data EEPROM or Configuration Select bit
volatile bit CFGS                @ ((unsigned)&EECON1*8)+6;
// FLASH Program / Data EEPROM Memory Select bit
volatile bit EEPGD               @ ((unsigned)&EECON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RD                  : 1;
        unsigned	WR                  : 1;
        unsigned	WREN                : 1;
        unsigned	WRERR               : 1;
        unsigned	FREE                : 1;
        unsigned	LWLO                : 1;
        unsigned	CFGS                : 1;
        unsigned	EEPGD               : 1;
    };
} EECON1bits @ 0x195;
#endif

// Register: EECON2
volatile unsigned char           EECON2              @ 0x196;
// bit and bitfield definitions

// Register: RCREG
volatile unsigned char           RCREG               @ 0x199;
// bit and bitfield definitions

// Register: TXREG
volatile unsigned char           TXREG               @ 0x19A;
// bit and bitfield definitions

// Register: SPBRGL
volatile unsigned char           SPBRGL              @ 0x19B;
volatile unsigned char           SPBRG               @ 0x19B;
// bit and bitfield definitions

// Register: SPBRGH
volatile unsigned char           SPBRGH              @ 0x19C;
// bit and bitfield definitions

// Register: RCSTA
// Receive Status and Control Register
volatile unsigned char           RCSTA               @ 0x19D;
// bit and bitfield definitions
// 9th bit of received data (can be parity bit)
volatile bit RX9D                @ ((unsigned)&RCSTA*8)+0;
// Overrun Error bit
volatile bit OERR                @ ((unsigned)&RCSTA*8)+1;
// Framing Error bit
volatile bit FERR                @ ((unsigned)&RCSTA*8)+2;
// Address Detect Enable bit
volatile bit ADDEN               @ ((unsigned)&RCSTA*8)+3;
// Continuous Receive Enable bit
volatile bit CREN                @ ((unsigned)&RCSTA*8)+4;
// Single Receive Enable bit
volatile bit SREN                @ ((unsigned)&RCSTA*8)+5;
// 9-bit Receive Enable bit
volatile bit RX9                 @ ((unsigned)&RCSTA*8)+6;
// Serial Port Enable bit
volatile bit SPEN                @ ((unsigned)&RCSTA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RX9D                : 1;
        unsigned	OERR                : 1;
        unsigned	FERR                : 1;
        unsigned	ADDEN               : 1;
        unsigned	CREN                : 1;
        unsigned	SREN                : 1;
        unsigned	RX9                 : 1;
        unsigned	SPEN                : 1;
    };
} RCSTAbits @ 0x19D;
#endif

// Register: TXSTA
// Transmit Status and Control Register
volatile unsigned char           TXSTA               @ 0x19E;
// bit and bitfield definitions
// 9th bit of transmit data; can be used as parity bit
volatile bit TX9D                @ ((unsigned)&TXSTA*8)+0;
// Transmit Operation Idle Status bit
volatile bit TRMT                @ ((unsigned)&TXSTA*8)+1;
// High Baud Rate Select bit
volatile bit BRGH                @ ((unsigned)&TXSTA*8)+2;
// Send BREAK character bit
volatile bit SENDB               @ ((unsigned)&TXSTA*8)+3;
// USART Mode Select bit
volatile bit SYNC                @ ((unsigned)&TXSTA*8)+4;
// Transmit Enable bit
volatile bit TXEN                @ ((unsigned)&TXSTA*8)+5;
// 9-bit Transmit Enable bit
volatile bit TX9                 @ ((unsigned)&TXSTA*8)+6;
// Clock Source Select bit
volatile bit CSRC                @ ((unsigned)&TXSTA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TX9D                : 1;
        unsigned	TRMT                : 1;
        unsigned	BRGH                : 1;
        unsigned	SENDB               : 1;
        unsigned	SYNC                : 1;
        unsigned	TXEN                : 1;
        unsigned	TX9                 : 1;
        unsigned	CSRC                : 1;
    };
} TXSTAbits @ 0x19E;
#endif

// Register: BAUDCON
// Baud Rate Control Register
volatile unsigned char           BAUDCON             @ 0x19F;
// bit and bitfield definitions
// Auto-Baud Detect Enable bit
volatile bit ABDEN               @ ((unsigned)&BAUDCON*8)+0;
// Wake-Up Enable bit
volatile bit WUE                 @ ((unsigned)&BAUDCON*8)+1;
// 16-bit Baud Rate Register enable bit
volatile bit BRG16               @ ((unsigned)&BAUDCON*8)+3;
// Clock/Transmit Polarity Select bit
volatile bit SCKP                @ ((unsigned)&BAUDCON*8)+4;
// Receive Operation Idle Status bit
volatile bit RCIDL               @ ((unsigned)&BAUDCON*8)+6;
// BRG Rollover Status bit
volatile bit ABDOVF              @ ((unsigned)&BAUDCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ABDEN               : 1;
        unsigned	WUE                 : 1;
        unsigned	                    : 1;
        unsigned	BRG16               : 1;
        unsigned	SCKP                : 1;
        unsigned	: 1;
        unsigned	RCIDL               : 1;
        unsigned	ABDOVF              : 1;
    };
} BAUDCONbits @ 0x19F;
#endif

//
// Special function register definitions: Bank 4
//


// Register: WPUA
volatile unsigned char           WPUA                @ 0x20C;
// bit and bitfield definitions
volatile bit WPUA0               @ ((unsigned)&WPUA*8)+0;
volatile bit WPUA1               @ ((unsigned)&WPUA*8)+1;
volatile bit WPUA2               @ ((unsigned)&WPUA*8)+2;
volatile bit WPUA3               @ ((unsigned)&WPUA*8)+3;
volatile bit WPUA4               @ ((unsigned)&WPUA*8)+4;
volatile bit WPUA5               @ ((unsigned)&WPUA*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	WPUA0               : 1;
        unsigned	WPUA1               : 1;
        unsigned	WPUA2               : 1;
        unsigned	WPUA3               : 1;
        unsigned	WPUA4               : 1;
        unsigned	WPUA5               : 1;
    };
    struct {
        unsigned	WPUA                : 6;
        unsigned	                    : 2;
    };
} WPUAbits @ 0x20C;
#endif

// Register: WPUC
volatile unsigned char           WPUC                @ 0x20E;
// bit and bitfield definitions
volatile bit WPUC0               @ ((unsigned)&WPUC*8)+0;
volatile bit WPUC1               @ ((unsigned)&WPUC*8)+1;
volatile bit WPUC2               @ ((unsigned)&WPUC*8)+2;
volatile bit WPUC3               @ ((unsigned)&WPUC*8)+3;
volatile bit WPUC4               @ ((unsigned)&WPUC*8)+4;
volatile bit WPUC5               @ ((unsigned)&WPUC*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	WPUC0               : 1;
        unsigned	WPUC1               : 1;
        unsigned	WPUC2               : 1;
        unsigned	WPUC3               : 1;
        unsigned	WPUC4               : 1;
        unsigned	WPUC5               : 1;
    };
} WPUCbits @ 0x20E;
#endif

// Register: SSP1BUF
volatile unsigned char           SSP1BUF             @ 0x211;
volatile unsigned char           SSPBUF              @ 0x211;
// bit and bitfield definitions

// Register: SSP1ADD
volatile unsigned char           SSP1ADD             @ 0x212;
volatile unsigned char           SSPADD              @ 0x212;
// bit and bitfield definitions

// Register: SSP1MSK
volatile unsigned char           SSP1MSK             @ 0x213;
volatile unsigned char           SSPMSK              @ 0x213;
// bit and bitfield definitions

// Register: SSP1STAT
volatile unsigned char           SSP1STAT            @ 0x214;
volatile unsigned char           SSPSTAT             @ 0x214;
// bit and bitfield definitions
volatile bit BF                  @ ((unsigned)&SSP1STAT*8)+0;
volatile bit UA                  @ ((unsigned)&SSP1STAT*8)+1;
volatile bit R_nW                @ ((unsigned)&SSP1STAT*8)+2;
volatile bit S                   @ ((unsigned)&SSP1STAT*8)+3;
volatile bit P                   @ ((unsigned)&SSP1STAT*8)+4;
volatile bit D_nA                @ ((unsigned)&SSP1STAT*8)+5;
volatile bit CKE                 @ ((unsigned)&SSP1STAT*8)+6;
volatile bit SMP                 @ ((unsigned)&SSP1STAT*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BF                  : 1;
        unsigned	UA                  : 1;
        unsigned	R_nW                : 1;
        unsigned	S                   : 1;
        unsigned	P                   : 1;
        unsigned	D_nA                : 1;
        unsigned	CKE                 : 1;
        unsigned	SMP                 : 1;
    };
} SSP1STATbits @ 0x214;
#endif

// Register: SSP1CON1
volatile unsigned char           SSP1CON1            @ 0x215;
volatile unsigned char           SSPCON1             @ 0x215;
volatile unsigned char           SSPCON              @ 0x215;
// bit and bitfield definitions
volatile bit SSPM0               @ ((unsigned)&SSP1CON1*8)+0;
volatile bit SSPM1               @ ((unsigned)&SSP1CON1*8)+1;
volatile bit SSPM2               @ ((unsigned)&SSP1CON1*8)+2;
volatile bit SSPM3               @ ((unsigned)&SSP1CON1*8)+3;
volatile bit CKP                 @ ((unsigned)&SSP1CON1*8)+4;
volatile bit SSPEN               @ ((unsigned)&SSP1CON1*8)+5;
volatile bit SSPOV               @ ((unsigned)&SSP1CON1*8)+6;
volatile bit WCOL                @ ((unsigned)&SSP1CON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SSPM0               : 1;
        unsigned	SSPM1               : 1;
        unsigned	SSPM2               : 1;
        unsigned	SSPM3               : 1;
        unsigned	CKP                 : 1;
        unsigned	SSPEN               : 1;
        unsigned	SSPOV               : 1;
        unsigned	WCOL                : 1;
    };
    struct {
        unsigned	SSPM                : 4;
    };
} SSP1CON1bits @ 0x215;
#endif

// Register: SSP1CON2
volatile unsigned char           SSP1CON2            @ 0x216;
volatile unsigned char           SSPCON2             @ 0x216;
// bit and bitfield definitions
volatile bit SEN                 @ ((unsigned)&SSP1CON2*8)+0;
volatile bit RSEN                @ ((unsigned)&SSP1CON2*8)+1;
volatile bit PEN                 @ ((unsigned)&SSP1CON2*8)+2;
volatile bit RCEN                @ ((unsigned)&SSP1CON2*8)+3;
volatile bit ACKEN               @ ((unsigned)&SSP1CON2*8)+4;
volatile bit ACKDT               @ ((unsigned)&SSP1CON2*8)+5;
volatile bit ACKSTAT             @ ((unsigned)&SSP1CON2*8)+6;
volatile bit GCEN                @ ((unsigned)&SSP1CON2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEN                 : 1;
        unsigned	RSEN                : 1;
        unsigned	PEN                 : 1;
        unsigned	RCEN                : 1;
        unsigned	ACKEN               : 1;
        unsigned	ACKDT               : 1;
        unsigned	ACKSTAT             : 1;
        unsigned	GCEN                : 1;
    };
} SSP1CON2bits @ 0x216;
#endif

// Register: SSP1CON3
volatile unsigned char           SSP1CON3            @ 0x217;
volatile unsigned char           SSPCON3             @ 0x217;
// bit and bitfield definitions
volatile bit DHEN                @ ((unsigned)&SSP1CON3*8)+0;
volatile bit AHEN                @ ((unsigned)&SSP1CON3*8)+1;
volatile bit SBCDE               @ ((unsigned)&SSP1CON3*8)+2;
volatile bit SDAHT               @ ((unsigned)&SSP1CON3*8)+3;
volatile bit BOEN                @ ((unsigned)&SSP1CON3*8)+4;
volatile bit SCIE                @ ((unsigned)&SSP1CON3*8)+5;
volatile bit PCIE                @ ((unsigned)&SSP1CON3*8)+6;
volatile bit ACKTIM              @ ((unsigned)&SSP1CON3*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	DHEN                : 1;
        unsigned	AHEN                : 1;
        unsigned	SBCDE               : 1;
        unsigned	SDAHT               : 1;
        unsigned	BOEN                : 1;
        unsigned	SCIE                : 1;
        unsigned	PCIE                : 1;
        unsigned	ACKTIM              : 1;
    };
} SSP1CON3bits @ 0x217;
#endif

//
// Special function register definitions: Bank 5
//


// Register: CCPR1L
volatile unsigned char           CCPR1L              @ 0x291;
// bit and bitfield definitions

// Register: CCPR1H
volatile unsigned char           CCPR1H              @ 0x292;
// bit and bitfield definitions

// Register: CCP1CON
volatile unsigned char           CCP1CON             @ 0x293;
// bit and bitfield definitions
volatile bit CCP1M0              @ ((unsigned)&CCP1CON*8)+0;
volatile bit CCP1M1              @ ((unsigned)&CCP1CON*8)+1;
volatile bit CCP1M2              @ ((unsigned)&CCP1CON*8)+2;
volatile bit CCP1M3              @ ((unsigned)&CCP1CON*8)+3;
volatile bit DC1B0               @ ((unsigned)&CCP1CON*8)+4;
volatile bit DC1B1               @ ((unsigned)&CCP1CON*8)+5;
volatile bit P1M0                @ ((unsigned)&CCP1CON*8)+6;
volatile bit P1M1                @ ((unsigned)&CCP1CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP1M0              : 1;
        unsigned	CCP1M1              : 1;
        unsigned	CCP1M2              : 1;
        unsigned	CCP1M3              : 1;
        unsigned	DC1B0               : 1;
        unsigned	DC1B1               : 1;
        unsigned	P1M0                : 1;
        unsigned	P1M1                : 1;
    };
    struct {
        unsigned	CCP1M               : 4;
        unsigned	DC1B                : 2;
        unsigned	P1M                 : 2;
    };
} CCP1CONbits @ 0x293;
#endif

// Register: PWM1CON
volatile unsigned char           PWM1CON             @ 0x294;
// bit and bitfield definitions
volatile bit P1DC0               @ ((unsigned)&PWM1CON*8)+0;
volatile bit P1DC1               @ ((unsigned)&PWM1CON*8)+1;
volatile bit P1DC2               @ ((unsigned)&PWM1CON*8)+2;
volatile bit P1DC3               @ ((unsigned)&PWM1CON*8)+3;
volatile bit P1DC4               @ ((unsigned)&PWM1CON*8)+4;
volatile bit P1DC5               @ ((unsigned)&PWM1CON*8)+5;
volatile bit P1DC6               @ ((unsigned)&PWM1CON*8)+6;
volatile bit P1RSEN              @ ((unsigned)&PWM1CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	P1DC0               : 1;
        unsigned	P1DC1               : 1;
        unsigned	P1DC2               : 1;
        unsigned	P1DC3               : 1;
        unsigned	P1DC4               : 1;
        unsigned	P1DC5               : 1;
        unsigned	P1DC6               : 1;
        unsigned	P1RSEN              : 1;
    };
    struct {
        unsigned	P1DC                : 7;
    };
} PWM1CONbits @ 0x294;
#endif

// Register: CCP1AS
volatile unsigned char           CCP1AS              @ 0x295;
volatile unsigned char           ECCP1AS             @ 0x295;
// bit and bitfield definitions
volatile bit PSS1BD0             @ ((unsigned)&CCP1AS*8)+0;
volatile bit PSS1BD1             @ ((unsigned)&CCP1AS*8)+1;
volatile bit PSS1AC0             @ ((unsigned)&CCP1AS*8)+2;
volatile bit PSS1AC1             @ ((unsigned)&CCP1AS*8)+3;
volatile bit CCP1AS0             @ ((unsigned)&CCP1AS*8)+4;
volatile bit CCP1AS1             @ ((unsigned)&CCP1AS*8)+5;
volatile bit CCP1AS2             @ ((unsigned)&CCP1AS*8)+6;
volatile bit CCP1ASE             @ ((unsigned)&CCP1AS*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PSS1BD0             : 1;
        unsigned	PSS1BD1             : 1;
        unsigned	PSS1AC0             : 1;
        unsigned	PSS1AC1             : 1;
        unsigned	CCP1AS0             : 1;
        unsigned	CCP1AS1             : 1;
        unsigned	CCP1AS2             : 1;
        unsigned	CCP1ASE             : 1;
    };
    struct {
        unsigned	PSS1BD              : 2;
        unsigned	PSS1AC              : 2;
        unsigned	CCP1AS              : 3;
    };
} CCP1ASbits @ 0x295;
#endif

// Register: PSTR1CON
volatile unsigned char           PSTR1CON            @ 0x296;
// bit and bitfield definitions
volatile bit STR1A               @ ((unsigned)&PSTR1CON*8)+0;
volatile bit STR1B               @ ((unsigned)&PSTR1CON*8)+1;
volatile bit STR1C               @ ((unsigned)&PSTR1CON*8)+2;
volatile bit STR1D               @ ((unsigned)&PSTR1CON*8)+3;
volatile bit STR1SYNC            @ ((unsigned)&PSTR1CON*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	STR1A               : 1;
        unsigned	STR1B               : 1;
        unsigned	STR1C               : 1;
        unsigned	STR1D               : 1;
        unsigned	STR1SYNC            : 1;
    };
} PSTR1CONbits @ 0x296;
#endif

// Register: CCPR2L
volatile unsigned char           CCPR2L              @ 0x298;
// bit and bitfield definitions

// Register: CCPR2H
volatile unsigned char           CCPR2H              @ 0x299;
// bit and bitfield definitions

// Register: CCP2CON
volatile unsigned char           CCP2CON             @ 0x29A;
// bit and bitfield definitions
volatile bit CCP2M0              @ ((unsigned)&CCP2CON*8)+0;
volatile bit CCP2M1              @ ((unsigned)&CCP2CON*8)+1;
volatile bit CCP2M2              @ ((unsigned)&CCP2CON*8)+2;
volatile bit CCP2M3              @ ((unsigned)&CCP2CON*8)+3;
volatile bit DC2B0               @ ((unsigned)&CCP2CON*8)+4;
volatile bit DC2B1               @ ((unsigned)&CCP2CON*8)+5;
volatile bit P2M0                @ ((unsigned)&CCP2CON*8)+6;
volatile bit P2M1                @ ((unsigned)&CCP2CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP2M0              : 1;
        unsigned	CCP2M1              : 1;
        unsigned	CCP2M2              : 1;
        unsigned	CCP2M3              : 1;
        unsigned	DC2B0               : 1;
        unsigned	DC2B1               : 1;
        unsigned	P2M0                : 1;
        unsigned	P2M1                : 1;
    };
    struct {
        unsigned	CCP2M               : 4;
        unsigned	DC2B                : 2;
        unsigned	P2M                 : 2;
    };
} CCP2CONbits @ 0x29A;
#endif

// Register: PWM2CON
volatile unsigned char           PWM2CON             @ 0x29B;
// bit and bitfield definitions
volatile bit P2DC0               @ ((unsigned)&PWM2CON*8)+0;
volatile bit P2DC1               @ ((unsigned)&PWM2CON*8)+1;
volatile bit P2DC2               @ ((unsigned)&PWM2CON*8)+2;
volatile bit P2DC3               @ ((unsigned)&PWM2CON*8)+3;
volatile bit P2DC4               @ ((unsigned)&PWM2CON*8)+4;
volatile bit P2DC5               @ ((unsigned)&PWM2CON*8)+5;
volatile bit P2DC6               @ ((unsigned)&PWM2CON*8)+6;
volatile bit P2RSEN              @ ((unsigned)&PWM2CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	P2DC0               : 1;
        unsigned	P2DC1               : 1;
        unsigned	P2DC2               : 1;
        unsigned	P2DC3               : 1;
        unsigned	P2DC4               : 1;
        unsigned	P2DC5               : 1;
        unsigned	P2DC6               : 1;
        unsigned	P2RSEN              : 1;
    };
    struct {
        unsigned	P2DC                : 7;
    };
} PWM2CONbits @ 0x29B;
#endif

// Register: CCP2AS
volatile unsigned char           CCP2AS              @ 0x29C;
// bit and bitfield definitions
volatile bit PSS2BD0             @ ((unsigned)&CCP2AS*8)+0;
volatile bit PSS2BD1             @ ((unsigned)&CCP2AS*8)+1;
volatile bit PSS2AC0             @ ((unsigned)&CCP2AS*8)+2;
volatile bit PSS2AC1             @ ((unsigned)&CCP2AS*8)+3;
volatile bit CCP2AS0             @ ((unsigned)&CCP2AS*8)+4;
volatile bit CCP2AS1             @ ((unsigned)&CCP2AS*8)+5;
volatile bit CCP2AS2             @ ((unsigned)&CCP2AS*8)+6;
volatile bit CCP2ASE             @ ((unsigned)&CCP2AS*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PSS2BD0             : 1;
        unsigned	PSS2BD1             : 1;
        unsigned	PSS2AC0             : 1;
        unsigned	PSS2AC1             : 1;
        unsigned	CCP2AS0             : 1;
        unsigned	CCP2AS1             : 1;
        unsigned	CCP2AS2             : 1;
        unsigned	CCP2ASE             : 1;
    };
    struct {
        unsigned	PSS2BD              : 2;
        unsigned	PSS2AC              : 2;
        unsigned	CCP2AS              : 3;
    };
} CCP2ASbits @ 0x29C;
#endif

// Register: PSTR2CON
volatile unsigned char           PSTR2CON            @ 0x29D;
// bit and bitfield definitions
volatile bit STR2A               @ ((unsigned)&PSTR2CON*8)+0;
volatile bit STR2B               @ ((unsigned)&PSTR2CON*8)+1;
volatile bit STR2C               @ ((unsigned)&PSTR2CON*8)+2;
volatile bit STR2D               @ ((unsigned)&PSTR2CON*8)+3;
volatile bit STR2SYNC            @ ((unsigned)&PSTR2CON*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	STR2A               : 1;
        unsigned	STR2B               : 1;
        unsigned	STR2C               : 1;
        unsigned	STR2D               : 1;
        unsigned	STR2SYNC            : 1;
    };
} PSTR2CONbits @ 0x29D;
#endif

// Register: CCPTMRS
volatile unsigned char           CCPTMRS             @ 0x29E;
// bit and bitfield definitions
volatile bit C1TSEL0             @ ((unsigned)&CCPTMRS*8)+0;
volatile bit C1TSEL1             @ ((unsigned)&CCPTMRS*8)+1;
volatile bit C2TSEL0             @ ((unsigned)&CCPTMRS*8)+2;
volatile bit C2TSEL1             @ ((unsigned)&CCPTMRS*8)+3;
volatile bit C3TSEL0             @ ((unsigned)&CCPTMRS*8)+4;
volatile bit C3TSEL1             @ ((unsigned)&CCPTMRS*8)+5;
volatile bit C4TSEL0             @ ((unsigned)&CCPTMRS*8)+6;
volatile bit C4TSEL1             @ ((unsigned)&CCPTMRS*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C1TSEL0             : 1;
        unsigned	C1TSEL1             : 1;
        unsigned	C2TSEL0             : 1;
        unsigned	C2TSEL1             : 1;
        unsigned	C3TSEL0             : 1;
        unsigned	C3TSEL1             : 1;
        unsigned	C4TSEL0             : 1;
        unsigned	C4TSEL1             : 1;
    };
    struct {
        unsigned	C1TSEL              : 2;
        unsigned	C2TSEL              : 2;
        unsigned	C3TSEL              : 2;
        unsigned	C4TSEL              : 2;
    };
} CCPTMRSbits @ 0x29E;
#endif

//
// Special function register definitions: Bank 6
//


// Register: CCPR3L
volatile unsigned char           CCPR3L              @ 0x311;
// bit and bitfield definitions

// Register: CCPR3H
volatile unsigned char           CCPR3H              @ 0x312;
// bit and bitfield definitions

// Register: CCP3CON
volatile unsigned char           CCP3CON             @ 0x313;
// bit and bitfield definitions
volatile bit CCP3M0              @ ((unsigned)&CCP3CON*8)+0;
volatile bit CCP3M1              @ ((unsigned)&CCP3CON*8)+1;
volatile bit CCP3M2              @ ((unsigned)&CCP3CON*8)+2;
volatile bit CCP3M3              @ ((unsigned)&CCP3CON*8)+3;
volatile bit DC3B0               @ ((unsigned)&CCP3CON*8)+4;
volatile bit DC3B1               @ ((unsigned)&CCP3CON*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP3M0              : 1;
        unsigned	CCP3M1              : 1;
        unsigned	CCP3M2              : 1;
        unsigned	CCP3M3              : 1;
        unsigned	DC3B0               : 1;
        unsigned	DC3B1               : 1;
    };
    struct {
        unsigned	CCP3M               : 4;
        unsigned	DC3B                : 2;
    };
} CCP3CONbits @ 0x313;
#endif

// Register: CCPR4L
volatile unsigned char           CCPR4L              @ 0x318;
// bit and bitfield definitions

// Register: CCPR4H
volatile unsigned char           CCPR4H              @ 0x319;
// bit and bitfield definitions

// Register: CCP4CON
volatile unsigned char           CCP4CON             @ 0x31A;
// bit and bitfield definitions
volatile bit CCP4M0              @ ((unsigned)&CCP4CON*8)+0;
volatile bit CCP4M1              @ ((unsigned)&CCP4CON*8)+1;
volatile bit CCP4M2              @ ((unsigned)&CCP4CON*8)+2;
volatile bit CCP4M3              @ ((unsigned)&CCP4CON*8)+3;
volatile bit DC4B0               @ ((unsigned)&CCP4CON*8)+4;
volatile bit DC4B1               @ ((unsigned)&CCP4CON*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP4M0              : 1;
        unsigned	CCP4M1              : 1;
        unsigned	CCP4M2              : 1;
        unsigned	CCP4M3              : 1;
        unsigned	DC4B0               : 1;
        unsigned	DC4B1               : 1;
    };
    struct {
        unsigned	CCP4M               : 4;
        unsigned	DC4B                : 2;
    };
} CCP4CONbits @ 0x31A;
#endif

//
// Special function register definitions: Bank 7
//


// Register: INLVLA
volatile unsigned char           INLVLA              @ 0x38C;
// bit and bitfield definitions
volatile bit INLVLA0             @ ((unsigned)&INLVLA*8)+0;
volatile bit INLVLA1             @ ((unsigned)&INLVLA*8)+1;
volatile bit INLVLA2             @ ((unsigned)&INLVLA*8)+2;
volatile bit INLVLA3             @ ((unsigned)&INLVLA*8)+3;
volatile bit INLVLA4             @ ((unsigned)&INLVLA*8)+4;
volatile bit INLVLA5             @ ((unsigned)&INLVLA*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	INLVLA0             : 1;
        unsigned	INLVLA1             : 1;
        unsigned	INLVLA2             : 1;
        unsigned	INLVLA3             : 1;
        unsigned	INLVLA4             : 1;
        unsigned	INLVLA5             : 1;
    };
    struct {
        unsigned	INLVLA              : 6;
    };
} INLVLAbits @ 0x38C;
#endif

// Register: INLVLC
volatile unsigned char           INLVLC              @ 0x38E;
// bit and bitfield definitions
volatile bit INLVLC0             @ ((unsigned)&INLVLC*8)+0;
volatile bit INLVLC1             @ ((unsigned)&INLVLC*8)+1;
volatile bit INLVLC2             @ ((unsigned)&INLVLC*8)+2;
volatile bit INLVLC3             @ ((unsigned)&INLVLC*8)+3;
volatile bit INLVLC4             @ ((unsigned)&INLVLC*8)+4;
volatile bit INLVLC5             @ ((unsigned)&INLVLC*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	INLVLC0             : 1;
        unsigned	INLVLC1             : 1;
        unsigned	INLVLC2             : 1;
        unsigned	INLVLC3             : 1;
        unsigned	INLVLC4             : 1;
        unsigned	INLVLC5             : 1;
    };
    struct {
        unsigned	INLVLC              : 6;
    };
} INLVLCbits @ 0x38E;
#endif

// Register: IOCAP
// Interrupt-On-Change Positive Edge Register
volatile unsigned char           IOCAP               @ 0x391;
// bit and bitfield definitions
volatile bit IOCAP0              @ ((unsigned)&IOCAP*8)+0;
volatile bit IOCAP1              @ ((unsigned)&IOCAP*8)+1;
volatile bit IOCAP2              @ ((unsigned)&IOCAP*8)+2;
volatile bit IOCAP3              @ ((unsigned)&IOCAP*8)+3;
volatile bit IOCAP4              @ ((unsigned)&IOCAP*8)+4;
volatile bit IOCAP5              @ ((unsigned)&IOCAP*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOCAP0              : 1;
        unsigned	IOCAP1              : 1;
        unsigned	IOCAP2              : 1;
        unsigned	IOCAP3              : 1;
        unsigned	IOCAP4              : 1;
        unsigned	IOCAP5              : 1;
        unsigned	                    : 1;
        unsigned	: 1;
    };
    struct {
        unsigned	IOCAP               : 6;
        unsigned	: 2;
    };
} IOCAPbits @ 0x391;
#endif

// Register: IOCAN
// Interrupt-On-Change Negative Edge Register
volatile unsigned char           IOCAN               @ 0x392;
// bit and bitfield definitions
volatile bit IOCAN0              @ ((unsigned)&IOCAN*8)+0;
volatile bit IOCAN1              @ ((unsigned)&IOCAN*8)+1;
volatile bit IOCAN2              @ ((unsigned)&IOCAN*8)+2;
volatile bit IOCAN3              @ ((unsigned)&IOCAN*8)+3;
volatile bit IOCAN4              @ ((unsigned)&IOCAN*8)+4;
volatile bit IOCAN5              @ ((unsigned)&IOCAN*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOCAN0              : 1;
        unsigned	IOCAN1              : 1;
        unsigned	IOCAN2              : 1;
        unsigned	IOCAN3              : 1;
        unsigned	IOCAN4              : 1;
        unsigned	IOCAN5              : 1;
        unsigned	                    : 1;
        unsigned	: 1;
    };
    struct {
        unsigned	IOCAN               : 6;
        unsigned	: 2;
    };
} IOCANbits @ 0x392;
#endif

// Register: IOCAF
// Interrupt-On-Change Flag Register
volatile unsigned char           IOCAF               @ 0x393;
// bit and bitfield definitions
volatile bit IOCAF0              @ ((unsigned)&IOCAF*8)+0;
volatile bit IOCAF1              @ ((unsigned)&IOCAF*8)+1;
volatile bit IOCAF2              @ ((unsigned)&IOCAF*8)+2;
volatile bit IOCAF3              @ ((unsigned)&IOCAF*8)+3;
volatile bit IOCAF4              @ ((unsigned)&IOCAF*8)+4;
volatile bit IOCAF5              @ ((unsigned)&IOCAF*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOCAF0              : 1;
        unsigned	IOCAF1              : 1;
        unsigned	IOCAF2              : 1;
        unsigned	IOCAF3              : 1;
        unsigned	IOCAF4              : 1;
        unsigned	IOCAF5              : 1;
        unsigned	                    : 1;
        unsigned	: 1;
    };
    struct {
        unsigned	IOCAF               : 6;
        unsigned	: 2;
    };
} IOCAFbits @ 0x393;
#endif

// Register: CLKRCON
volatile unsigned char           CLKRCON             @ 0x39A;
// bit and bitfield definitions
volatile bit CLKRDIV0            @ ((unsigned)&CLKRCON*8)+0;
volatile bit CLKRDIV1            @ ((unsigned)&CLKRCON*8)+1;
volatile bit CLKRDIV2            @ ((unsigned)&CLKRCON*8)+2;
volatile bit CLKRDC0             @ ((unsigned)&CLKRCON*8)+3;
volatile bit CLKRDC1             @ ((unsigned)&CLKRCON*8)+4;
volatile bit CLKRSLR             @ ((unsigned)&CLKRCON*8)+5;
volatile bit CLKROE              @ ((unsigned)&CLKRCON*8)+6;
volatile bit CLKREN              @ ((unsigned)&CLKRCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CLKRDIV0            : 1;
        unsigned	CLKRDIV1            : 1;
        unsigned	CLKRDIV2            : 1;
        unsigned	CLKRDC0             : 1;
        unsigned	CLKRDC1             : 1;
        unsigned	CLKRSLR             : 1;
        unsigned	CLKROE              : 1;
        unsigned	CLKREN              : 1;
    };
    struct {
        unsigned	CLKRDIV             : 3;
        unsigned	CLKRDC              : 2;
    };
} CLKRCONbits @ 0x39A;
#endif

// Register: MDCON
volatile unsigned char           MDCON               @ 0x39C;
// bit and bitfield definitions
volatile bit MDBIT               @ ((unsigned)&MDCON*8)+0;
volatile bit MDOUT               @ ((unsigned)&MDCON*8)+3;
volatile bit MDOPOL              @ ((unsigned)&MDCON*8)+4;
volatile bit MDSLR               @ ((unsigned)&MDCON*8)+5;
volatile bit MDOE                @ ((unsigned)&MDCON*8)+6;
volatile bit MDEN                @ ((unsigned)&MDCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	MDBIT               : 1;
        unsigned	                    : 2;
        unsigned	MDOUT               : 1;
        unsigned	MDOPOL              : 1;
        unsigned	MDSLR               : 1;
        unsigned	MDOE                : 1;
        unsigned	MDEN                : 1;
    };
} MDCONbits @ 0x39C;
#endif

// Register: MDSRC
volatile unsigned char           MDSRC               @ 0x39D;
// bit and bitfield definitions
volatile bit MDMS0               @ ((unsigned)&MDSRC*8)+0;
volatile bit MDMS1               @ ((unsigned)&MDSRC*8)+1;
volatile bit MDMS2               @ ((unsigned)&MDSRC*8)+2;
volatile bit MDMS3               @ ((unsigned)&MDSRC*8)+3;
volatile bit MDMSODIS            @ ((unsigned)&MDSRC*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	MDMS0               : 1;
        unsigned	MDMS1               : 1;
        unsigned	MDMS2               : 1;
        unsigned	MDMS3               : 1;
        unsigned	                    : 3;
        unsigned	MDMSODIS            : 1;
    };
    struct {
        unsigned	MDMS                : 4;
    };
} MDSRCbits @ 0x39D;
#endif

// Register: MDCARL
volatile unsigned char           MDCARL              @ 0x39E;
// bit and bitfield definitions
volatile bit MDCL0               @ ((unsigned)&MDCARL*8)+0;
volatile bit MDCL1               @ ((unsigned)&MDCARL*8)+1;
volatile bit MDCL2               @ ((unsigned)&MDCARL*8)+2;
volatile bit MDCL3               @ ((unsigned)&MDCARL*8)+3;
volatile bit MDCLSYNC            @ ((unsigned)&MDCARL*8)+5;
volatile bit MDCLPOL             @ ((unsigned)&MDCARL*8)+6;
volatile bit MDCLODIS            @ ((unsigned)&MDCARL*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	MDCL0               : 1;
        unsigned	MDCL1               : 1;
        unsigned	MDCL2               : 1;
        unsigned	MDCL3               : 1;
        unsigned	                    : 1;
        unsigned	MDCLSYNC            : 1;
        unsigned	MDCLPOL             : 1;
        unsigned	MDCLODIS            : 1;
    };
    struct {
        unsigned	MDCL                : 4;
    };
} MDCARLbits @ 0x39E;
#endif

// Register: MDCARH
volatile unsigned char           MDCARH              @ 0x39F;
// bit and bitfield definitions
volatile bit MDCH0               @ ((unsigned)&MDCARH*8)+0;
volatile bit MDCH1               @ ((unsigned)&MDCARH*8)+1;
volatile bit MDCH2               @ ((unsigned)&MDCARH*8)+2;
volatile bit MDCH3               @ ((unsigned)&MDCARH*8)+3;
volatile bit MDCHSYNC            @ ((unsigned)&MDCARH*8)+5;
volatile bit MDCHPOL             @ ((unsigned)&MDCARH*8)+6;
volatile bit MDCHODIS            @ ((unsigned)&MDCARH*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	MDCH0               : 1;
        unsigned	MDCH1               : 1;
        unsigned	MDCH2               : 1;
        unsigned	MDCH3               : 1;
        unsigned	                    : 1;
        unsigned	MDCHSYNC            : 1;
        unsigned	MDCHPOL             : 1;
        unsigned	MDCHODIS            : 1;
    };
    struct {
        unsigned	MDCH                : 4;
    };
} MDCARHbits @ 0x39F;
#endif

//
// Special function register definitions: Bank 8
//


// Register: TMR4
volatile unsigned char           TMR4                @ 0x415;
// bit and bitfield definitions

// Register: PR4
volatile unsigned char           PR4                 @ 0x416;
// bit and bitfield definitions

// Register: T4CON
volatile unsigned char           T4CON               @ 0x417;
// bit and bitfield definitions
volatile bit T4CKPS0             @ ((unsigned)&T4CON*8)+0;
volatile bit T4CKPS1             @ ((unsigned)&T4CON*8)+1;
volatile bit TMR4ON              @ ((unsigned)&T4CON*8)+2;
volatile bit T4OUTPS0            @ ((unsigned)&T4CON*8)+3;
volatile bit T4OUTPS1            @ ((unsigned)&T4CON*8)+4;
volatile bit T4OUTPS2            @ ((unsigned)&T4CON*8)+5;
volatile bit T4OUTPS3            @ ((unsigned)&T4CON*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	T4CKPS0             : 1;
        unsigned	T4CKPS1             : 1;
        unsigned	TMR4ON              : 1;
        unsigned	T4OUTPS0            : 1;
        unsigned	T4OUTPS1            : 1;
        unsigned	T4OUTPS2            : 1;
        unsigned	T4OUTPS3            : 1;
    };
    struct {
        unsigned	T4CKPS              : 2;
        unsigned	                    : 1;
        unsigned	T4OUTPS             : 4;
    };
} T4CONbits @ 0x417;
#endif

// Register: TMR6
volatile unsigned char           TMR6                @ 0x41C;
// bit and bitfield definitions

// Register: PR6
volatile unsigned char           PR6                 @ 0x41D;
// bit and bitfield definitions

// Register: T6CON
volatile unsigned char           T6CON               @ 0x41E;
// bit and bitfield definitions
volatile bit T6CKPS0             @ ((unsigned)&T6CON*8)+0;
volatile bit T6CKPS1             @ ((unsigned)&T6CON*8)+1;
volatile bit TMR6ON              @ ((unsigned)&T6CON*8)+2;
volatile bit T6OUTPS0            @ ((unsigned)&T6CON*8)+3;
volatile bit T6OUTPS1            @ ((unsigned)&T6CON*8)+4;
volatile bit T6OUTPS2            @ ((unsigned)&T6CON*8)+5;
volatile bit T6OUTPS3            @ ((unsigned)&T6CON*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	T6CKPS0             : 1;
        unsigned	T6CKPS1             : 1;
        unsigned	TMR6ON              : 1;
        unsigned	T6OUTPS0            : 1;
        unsigned	T6OUTPS1            : 1;
        unsigned	T6OUTPS2            : 1;
        unsigned	T6OUTPS3            : 1;
    };
    struct {
        unsigned	T6CKPS              : 2;
        unsigned	                    : 1;
        unsigned	T6OUTPS             : 4;
    };
} T6CONbits @ 0x41E;
#endif

//
// Special function register definitions: Bank 31
//


// Register: STATUS_SHAD
volatile unsigned char           STATUS_SHAD         @ 0xFE4;
// bit and bitfield definitions
volatile bit C_SHAD              @ ((unsigned)&STATUS_SHAD*8)+0;
volatile bit DC_SHAD             @ ((unsigned)&STATUS_SHAD*8)+1;
volatile bit Z_SHAD              @ ((unsigned)&STATUS_SHAD*8)+2;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C_SHAD              : 1;
        unsigned	DC_SHAD             : 1;
        unsigned	Z_SHAD              : 1;
    };
} STATUS_SHADbits @ 0xFE4;
#endif

// Register: WREG_SHAD
volatile unsigned char           WREG_SHAD           @ 0xFE5;
// bit and bitfield definitions

// Register: BSR_SHAD
volatile unsigned char           BSR_SHAD            @ 0xFE6;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BSR_SHAD            : 5;
    };
} BSR_SHADbits @ 0xFE6;
#endif

// Register: PCLATH_SHAD
volatile unsigned char           PCLATH_SHAD         @ 0xFE7;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PCLATH_SHAD         : 7;
    };
} PCLATH_SHADbits @ 0xFE7;
#endif

// Register: FSR0L_SHAD
volatile unsigned char           FSR0L_SHAD          @ 0xFE8;
// bit and bitfield definitions

// Register: FSR0H_SHAD
volatile unsigned char           FSR0H_SHAD          @ 0xFE9;
// bit and bitfield definitions

// Register: FSR1L_SHAD
volatile unsigned char           FSR1L_SHAD          @ 0xFEA;
// bit and bitfield definitions

// Register: FSR1H_SHAD
volatile unsigned char           FSR1H_SHAD          @ 0xFEB;
// bit and bitfield definitions

// Register: STKPTR
// Current Stack pointer
volatile unsigned char           STKPTR              @ 0xFED;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	STKPTR              : 5;
    };
} STKPTRbits @ 0xFED;
#endif

// Register: TOSL
// Top of Stack Low byte
volatile unsigned char           TOSL                @ 0xFEE;
// bit and bitfield definitions

// Register: TOSH
// Top of Stack High byte
volatile unsigned char           TOSH                @ 0xFEF;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TOSH                : 7;
    };
} TOSHbits @ 0xFEF;
#endif

#endif
