/*  Code to measure speed using a reed switch on an analog
    GPIO pin on the Arduino mega2560.
    
    Uses solely interrupts and timer functions for detection
    of the reed switch's low pulse.  Does not poll at all.
    
    Created by Daniel Ford on April 3, 2012
    Last updated by Daniel Ford on April 3, 2012
*/

#include "rpm_int.h"

int derp; // dummy var
volatile float wheelKPHBuf[NUM_WHEEL_KPH_SAMPLES];
volatile float pedalRPMBuf[NUM_PEDAL_RPM_SAMPLES];
volatile char wheelKPHInd;
volatile char pedalRPMInd;
volatile char wheelIntFlg;
volatile char pedalIntFlg;
volatile char wheelStartFlg;
volatile char pedalStartFlg;
int pedalIntPin = 3;
int wheelIntPin = 2;
int pedalIntNum = 1;
int wheelIntNum = 0;

ISR(TIMER3_OVF_vect)
{
  wheelStartFlg = 1;
  log_zero_speed();
}

ISR(TIMER4_OVF_vect)
{
  pedalStartFlg = 1;
  log_zero_cadence();
}

void pedal_setup(void)
{
  int idx;
  pinMode(pedalIntPin,INPUT);
  // attach pedal interrupt handler
  attachInterrupt(pedalIntNum,pedal_low_handler,FALLING);
  pedalIntFlg=0;
  pedalStartFlg = 1;
  pedalRPMInd;
  for( idx=0; idx < NUM_PEDAL_RPM_SAMPLES; idx++ )
  {
     pedalRPMBuf[idx] = 0.0f;
  }
}

void wheel_setup(void)
{
  int idx;
  // interrupt pins as input
  pinMode(wheelIntPin,INPUT);
  // attach the handler for the wheel magnet
  attachInterrupt(wheelIntNum,wheel_low_handler,FALLING);
  wheelIntFlg=0;
  wheelStartFlg = 1;
  wheelKPHInd=0;
  for( idx=0; idx < NUM_WHEEL_KPH_SAMPLES; idx++ )
  {
     wheelKPHBuf[idx] = 0.0f;
  }
}

void timers_sync(void)
{
  // clear prescaler and start counting
  _SFR_BYTE(GTCCR) = 0x0F;
  derp = 0; // act as 4 NOPs
  derp = 0;
  derp = 0;
  derp = 0;
  _SFR_BYTE(GTCCR) = 0x00;
}

void timer3_setup(void)
{
  // enable timer 3
  cbi(PRR1, PRTIM3);
  // set up timer 3 as non-PWM normal mode with down-prescale of 1024
  _SFR_BYTE(TCCR3A) = 0x00;
  _SFR_BYTE(TCCR3B) = 0x05;
  _SFR_BYTE(TCCR3C) = 0x00;
  // only the overflow interrupt enabled
  _SFR_BYTE(TIMSK3) = 0x01;
  // clear the interrupt and overflow flags
  _SFR_BYTE(TIFR3) = 0x00;
  // clear the counts
  TCNT3H = 0;
  TCNT3L = 0;
}

void timer4_setup(void)
{
   // enable timer 3
  cbi(PRR1, PRTIM4);
  // set up timer 3 as non-PWM normal mode with down-prescale of 1024
  _SFR_BYTE(TCCR4A) = 0x00;
  _SFR_BYTE(TCCR4B) = 0x05;
  _SFR_BYTE(TCCR4C) = 0x00;
  // only the overflow interrupt enabled
  _SFR_BYTE(TIMSK4) = 0x01;
  // clear the interrupt and overflow flags
  _SFR_BYTE(TIFR4) = 0x00;
  // clear the counts
  TCNT4H = 0;
  TCNT4L = 0;
} 

void wheel_low_handler()
{
  if( wheelIntFlg != 0 )
    return;
    
  wheelIntFlg=1;
  do_wheel_time();
}

void pedal_low_handler()
{
  if( pedalIntFlg != 0 )
    return;
    
  pedalIntFlg=1;
  do_pedal_time();
}

void do_wheel_time() 
{
  unsigned int tempTime;
  float tempFloat;

  if( wheelStartFlg != 0 ) {
    wheelStartFlg = 0;
    // we're either just starting or the timer wrapped, wait for next interrupt to log speed
    TCNT3H=0;
    TCNT3L=0;
  } else {
    tempTime=0;
    tempTime+=((unsigned int)(TCNT3L));
    tempTime+=((unsigned int)(TCNT3H)) << 8;
    tempFloat=(float)tempTime;
    // wheelTime is in counts of (1024*0.0625 us) = 64 us.
    // convert up to ms
    tempFloat = tempFloat / TMR_COUNTS_PER_MS;
    if(tempFloat > MIN_WHEEL_TIME_THRESH_MS )
    {
      // now convert to kph
      wheelKPHBuf[wheelKPHInd] = (WHEEL_CIRCUM_MM * SPEED_CONV)/tempFloat;
      wheelKPHInd = wheelKPHInd + 1;
      if( wheelKPHInd >= NUM_WHEEL_KPH_SAMPLES )
      {
         wheelKPHInd = 0;
      }
      TCNT3H=0;
      TCNT3L=0;
    }
  }
  wheelIntFlg=0;
}

void do_pedal_time() 
{
  unsigned int tempTime;
  float tempFloat;

  if( pedalStartFlg != 0 ) {
    pedalStartFlg = 0;
    // we're either just starting or the timer wrapped, wait for next interrupt to log cadence
    // need at least two samples for cadence
    TCNT4H=0;
    TCNT4L=0;
  } else {
    tempTime=0;
    tempTime+=((unsigned int)(TCNT4L));
    tempTime+=((unsigned int)(TCNT4H)) << 8;
    tempFloat=(float)tempTime;
    // tempTime is in counts of (1024*0.0625 us) = 64 us.
    // convert up to ms
    tempFloat = tempFloat / TMR_COUNTS_PER_MS;
    if( tempFloat > MIN_PEDAL_TIME_THRESH_MS )
    {
      // now convert to rpm
      pedalRPMBuf[pedalRPMInd] = (PEDAL_CONV/tempFloat);
      pedalRPMInd = pedalRPMInd + 1;
      if( pedalRPMInd >= NUM_PEDAL_RPM_SAMPLES )
      {
         pedalRPMInd = 0;
      }
      TCNT4H=0;
      TCNT4L=0;
    }
  }
  pedalIntFlg=0;
}

void log_zero_speed(void)
{
  wheelKPHBuf[wheelKPHInd] = 0.0f;
  wheelKPHInd = wheelKPHInd + 1;
  if( wheelKPHInd >= NUM_WHEEL_KPH_SAMPLES )
  {
    wheelKPHInd = 0;
  }
}

void log_zero_cadence(void)
{
  pedalRPMBuf[pedalRPMInd] = 0.0f;
  pedalRPMInd = pedalRPMInd + 1;
  if( pedalRPMInd >= NUM_PEDAL_RPM_SAMPLES )
  {
    pedalRPMInd = 0;
  }
}  

