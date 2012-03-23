// Increase ADC sample rate to 1us per call
#define FASTADC 0

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

volatile char newSpdFlag;
volatile char printflg1, printflg2;
volatile char wheelIntFlg = 0;
volatile char startFlg;
int wheelIntPin = 2;
int wheelIntNum = 0;
unsigned int nIntCalls = 0;
static volatile unsigned int wheelTime = 0xFF;
unsigned int tempTime;
unsigned int wheelRead;
float wheelFloat;
float circum = 2097.0; // wheel circum: 2097mm
//float mps; //meters per second
float kph; //kilometers per hour
float speedConv=3.6; // mm/msec to kph


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
  // clear prescaler and start counting
  _SFR_BYTE(GTCCR) = 0x0F;
  kph = 0; // act as 3 NOPs
  kph = 0;
  kph = 0;
  kph = 0;
  _SFR_BYTE(GTCCR) = 0x00;
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
  // set communiation speed
  Serial.begin(9600);
  // interrupt pin as input
  pinMode(wheelIntPin,INPUT);
  // attach the handler for the wheel magnet
  attachInterrupt(wheelIntNum,wheel_low_handler,FALLING);
  interrupts();
  startFlg = 1;
  nIntCalls=0;
  wheelIntFlg=0;
}

void wheel_low_handler()
{
  if( wheelIntFlg != 0 )
    return;
    
  wheelIntFlg=1;
  do_wheel_speed();
}

void do_wheel_speed() 
{
  nIntCalls+=1;   
  newSpdFlag = 1;
  if( startFlg != 0 ) {
    startFlg = 0;
    printflg1 = 1;
    // need at least two samples for speed
    TCNT3H=0;
    TCNT3L=0;
  } else {
    printflg2 = 1;
    wheelTime=0;
    wheelTime+=((unsigned int)(TCNT3L));
    wheelTime+=((unsigned int)(TCNT3H)) << 8;
    TCNT3H=0;
    TCNT3L=0;
  }
}


void loop()
{
  wheelRead = digitalRead(wheelIntPin);
  if( wheelRead == HIGH )
    wheelIntFlg = 0;

  if(printflg1 != 0) {
    printflg1=0;
    Serial.print("Outside handler: first sample, time = ");
    Serial.println(wheelTime);
  } else if(printflg2 != 0) {
    printflg2 = 0;
    Serial.print("Outside handler: time = ");
    Serial.println(wheelTime);
  }
  if( wheelTime == 0xFF ) {
    kph = 0;
  } else if( newSpdFlag != 0 ) {
    newSpdFlag = 0;
    // wheelTime is in counts of (1024*0.0625 us) = 64 us.
    // convert up to ms
    wheelFloat = ((float)wheelTime) / 15.625f;
    // now convert to kph
    kph = (circum/wheelFloat)*speedConv;
    Serial.print("Speed (kph): ");
    Serial.println(kph);
    Serial.print("Num interrupt calls: ");
    Serial.println(nIntCalls);
  }
  /*
  tempTime=0;
  tempTime+=((unsigned int)(TCNT3L));
  tempTime+=((unsigned int)(TCNT3H)) << 8;
  Serial.print("Timer3 val: ");
  Serial.println(tempTime);
  */
  delay(100);
  
}
