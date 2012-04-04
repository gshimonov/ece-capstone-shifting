/*  Code to measure speed using a reed switch on an analog
    GPIO pin on the Arduino mega2560.
    
    Uses solely interrupts and timer functions for detection
    of the reed switch's low pulse.  Does not poll at all.
    
    Created by Daniel Ford on April 3, 2012
    Last updated by Daniel Ford on April 3, 2012
*/

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"	// for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif

void timer3_setup(void);
void timer4_setup(void);
void timers_sync(void);
void pedal_setup(void);
void wheel_setup(void);
void wheel_low_handler(void);
void pedal_low_handler(void);
void do_wheel_speed(void);
void do_pedal_speed(void);
void log_zero_speed(void);
void log_zero_cadence(void);

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

#define WHEEL_CIRCUM_MM            (2097.0f) // wheel circum: 2097mm
#define SPEED_CONV                 (3.6f) // kph per mm/msec
#define PEDAL_CONV                 (60000.0f) // rpm per rpms
#define MAX_KPH                    (128.0f) // max rider speed believable
#define MIN_GEAR_RAT               (53/22)
#define MIN_WHEEL_TIME_THRESH_MS   (SPEED_CONV*( WHEEL_CIRCUM_MM / MAX_KPH ) )
#define MIN_PEDAL_TIME_THRESH_MS   (MIN_GEAR_RAT*MIN_WHEEL_TIME_THRESH_MS)

#define TMR_COUNTS_PER_MS          (15.625f)
#define NUM_WHEEL_KPH_SAMPLES      (5)
#define NUM_PEDAL_RPM_SAMPLES      (5) 

extern int derp; // dummy var
extern volatile float wheelKPHBuf[NUM_WHEEL_KPH_SAMPLES];
extern volatile float pedalRPMBuf[NUM_PEDAL_RPM_SAMPLES];
extern volatile char wheelKPHInd;
extern volatile char pedalRPMInd;
extern volatile char wheelIntFlg;
extern volatile char pedalIntFlg;
extern volatile char wheelStartFlg;
extern volatile char pedalStartFlg;
extern int pedalIntPin = 3;
extern int wheelIntPin = 2;
extern int pedalIntNum = 1;
extern int wheelIntNum = 0;

