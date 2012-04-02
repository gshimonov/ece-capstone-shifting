/*  Code to measure speed using a reed switch on an analog
    GPIO pin on the Arduino mega2560.
    
    Uses solely interrupts and timer functions for detection
    of the reed switch's low pulse.  Does not poll at all.
    
    Created by Daniel Ford on March 21, 2012
    Last updated by Daniel Ford on March 21, 2012
*/

void timer3_setup(void);
void timer4_setup(void);
void timers_sync(void);
void pedal_setup(void);
void wheel_setup(void);
void wheel_low_handler(void);
void pedal_low_handler(void);
void do_wheel_speed(void);
void do_pedal_speed(void);
void update_wheel_speed(void);
void update_pedal_cadence(void);

// Increase ADC sample rate to 1us per call
#define FASTADC 0

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

int derp; // dummy var
volatile char newWheelSpdFlag;
volatile char newPedalSpdFlag;
// volatile char wheelPrintFlg1, wheelPrintFlg2;
// volatile char pedalPrintFlg1, pedalPrintFlg2;
volatile char wheelIntFlg;
volatile char pedalIntFlg;
volatile char wheelStartFlg;
volatile char pedalStartFlg;
int pedalIntPin = 3;
int wheelIntPin = 2;
int pedalIntNum = 1;
int wheelIntNum = 0;
// unsigned int nWheelIntCalls;
// unsigned int nPedalIntCalls;
static volatile unsigned int wheelTime;
static volatile unsigned int pedalTime;
unsigned int tempTime;
unsigned int wheelRead;
unsigned int pedalRead;
float tempFloat;
//float mps; //meters per second
float wheelKPH; //kilometers per hour
float pedalRPM;

#define WHEEL_CIRCUM_MM            (2097.0f) // wheel circum: 2097mm
#define SPEED_CONV                 (3.6f) // mm/msec to kph
#define PEDAL_CONV                 (60.0f) // rps to rpm
#define MAX_KPH                    (128.0f) // max rider speed believable
#define MIN_GEAR_RAT               (53/22)
#define MIN_WHEEL_TIME_THRESH_MS   (SPEED_CONV*( WHEEL_CIRCUM_MM / MAX_KPH ) )
#define MIN_PEDAL_TIME_THRESH_MS   (MIN_GEAR_RAT*MIN_WHEEL_TIME_THRESH_MS)

#define TMR_COUNTS_PER_MS          (15.625f)

void setup()
{
  noInterrupts();
  #if FASTADC
  
  // set prescale to 16
  sbi(ADCSRA,ADPS2) ;
  cbi(ADCSRA,ADPS1) ;
  cbi(ADCSRA,ADPS0) ;
  #endif
  // 5V reference
  analogReference(DEFAULT);
  
  timer3_setup();
  timer4_setup();
  timers_sync();
  pedal_setup();
  wheel_setup();
  
  // set communiation speed
  Serial.begin(9600);
  
  interrupts();
}

void pedal_setup(void)
{
  pinMode(pedalIntPin,INPUT);
  // attach pedal interrupt handler
  attachInterrupt(pedalIntNum,pedal_low_handler,FALLING);
  // nPedalIntCalls=0;
  pedalIntFlg=0;
  pedalTime = 0xFFFF;
  pedalStartFlg = 0;
}

void wheel_setup(void)
{
  // interrupt pins as input
  pinMode(wheelIntPin,INPUT);
  // attach the handler for the wheel magnet
  attachInterrupt(wheelIntNum,wheel_low_handler,FALLING);
  wheelStartFlg = 1;
  // nWheelIntCalls=0;
  wheelIntFlg=0;
  wheelTime = 0xFFFF;
}

void timers_sync(void)
{
  // clear prescaler and start counting
  _SFR_BYTE(GTCCR) = 0x0F;
  derp = 0; // act as 3 NOPs
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
  // no timer interrupts enabled
  _SFR_BYTE(TIMSK3) = 0x00;
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
  // no timer interrupts enabled
  _SFR_BYTE(TIMSK4) = 0x00;
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
  // nWheelIntCalls+=1;   
  if( wheelStartFlg != 0 ) {
    wheelStartFlg = 0;
    // wheelPrintFlg1 = 1;
    // need at least two samples for speed
    TCNT3H=0;
    TCNT3L=0;
  } else {
    // wheelPrintFlg2 = 1;
    tempTime=0;
    tempTime+=((unsigned int)(TCNT3L));
    tempTime+=((unsigned int)(TCNT3H)) << 8;
    tempFloat=(float)tempTime;
    if( (tempFloat / TMR_COUNTS_PER_MS) > MIN_WHEEL_TIME_THRESH_MS )
    {
      wheelTime = tempTime;
      newWheelSpdFlag = 1;
      TCNT3H=0;
      TCNT3L=0;
    }
  }
  wheelIntFlg=0;
}

void do_pedal_time() 
{
  // nPedalIntCalls+=1;
  if( pedalStartFlg != 0 ) {
    pedalStartFlg = 0;
    // pedalPrintFlg1 = 1;
    // need at least two samples for speed
    TCNT4H=0;
    TCNT4L=0;
  } else {
    // pedalPrintFlg2 = 1;
    tempTime=0;
    tempTime+=((unsigned int)(TCNT4L));
    tempTime+=((unsigned int)(TCNT4H)) << 8;
    tempFloat=(float)tempTime;
    if( (tempFloat / TMR_COUNTS_PER_MS) > MIN_PEDAL_TIME_THRESH_MS )
    {
      pedalTime = tempTime;
      newPedalSpdFlag = 1;
      TCNT4H=0;
      TCNT4L=0;
    }
  }
  pedalIntFlg=0;
}

void update_wheel_speed(void)
{
  wheelRead = digitalRead(wheelIntPin);
  if( wheelRead == HIGH )
    wheelIntFlg = 0;
    
  if( wheelTime == 0xFFFF ) {
    wheelKPH = 0;
  } else if( newWheelSpdFlag != 0 ) {
    newWheelSpdFlag = 0;
    // wheelTime is in counts of (1024*0.0625 us) = 64 us.
    // convert up to ms
    tempFloat = ((float)wheelTime) / TMR_COUNTS_PER_MS;
    // now convert to kph
    wheelKPH = (WHEEL_CIRCUM_MM * SPEED_CONV)/tempFloat;
    Serial.print("Velocity from wheel (kph): ");
    Serial.println(wheelKPH);
    // Serial.print("Num wheel interrupt calls: ");
    // Serial.println(nWheelIntCalls);
  }
}

void update_pedal_cadence(void)
{
  pedalRead = digitalRead(pedalIntPin);
  if( pedalRead == HIGH )
    pedalIntFlg = 0;
    
  if( pedalTime == 0xFFFF ) {
    pedalRPM = 0;
  } else if( newPedalSpdFlag != 0 ) {
    newPedalSpdFlag = 0;
    // pedalTime is in counts of (1024*0.0625 us) = 64 us.
    // convert up to s
    tempFloat = ((float)pedalTime) / (TMR_COUNTS_PER_MS*1000.0f);
    // now convert to rpm
    pedalRPM = (PEDAL_CONV/tempFloat);
    Serial.print("Pedal cadence (rpm): ");
    Serial.println(pedalRPM);
    // Serial.print("Num pedal interrupt calls: ");
    // Serial.println(nPedalIntCalls);
  } 
}

void loop()
{

  update_wheel_speed();
  update_pedal_cadence();
  
  /*
  if(wheelPrintFlg1 != 0) {
    wheelPrintFlg1=0;
    Serial.print("Outside wheel handler: first sample, time = ");
    Serial.println(wheelTime);
  } else if(wheelPrintFlg2 != 0) {
    wheelPrintFlg2 = 0;
    Serial.print("Outside wheel handler: time = ");
    Serial.println(wheelTime);
  }
  */
  
  /*
  if(pedalPrintFlg1 != 0) {
    pedalPrintFlg1=0;
    Serial.print("Outside pedal handler: first sample, time = ");
    Serial.println(pedalTime);
  } else if(pedalPrintFlg2 != 0) {
    pedalPrintFlg2 = 0;
    Serial.print("Outside pedal handler: time = ");
    Serial.println(pedalTime);
  }
  */
    
  /*
  tempTime=0;
  tempTime+=((unsigned int)(TCNT3L));
  tempTime+=((unsigned int)(TCNT3H)) << 8;
  Serial.print("Timer3 val: ");
  Serial.println(tempTime);
  */
  delay(100);
  
}
