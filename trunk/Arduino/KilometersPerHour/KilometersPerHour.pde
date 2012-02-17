// Increase ADC sample rate to 1us per call
#define FASTADC 1

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

int speedPin = 0;
double speedSample;
int threshold = 100;
unsigned long before = 0;
unsigned long now;
unsigned long time;
float circum = 2097.0; // wheel circum: 2097mm
//float mps; //meters per second
double kph; //kilometers per hour


void setup()
{
  #if FASTADC
  // set prescale to 16
  sbi(ADCSRA,ADPS2) ;
  cbi(ADCSRA,ADPS1) ;
  cbi(ADCSRA,ADPS0) ;
  #endif
  // set communiation speed
  Serial.begin(9600);
}

boolean flag = false;
boolean computed = false;

void loop()
{
  speedSample = analogRead(speedPin);

  if(speedSample < 100) {
    flag = true;
  }
  else {
    flag = false;
    computed = false;
  }
  if (flag == true && computed == false) {
    now = millis();
    time = now - before;
    before = millis();
    computed = true;
  }
  kph = (circum/double(time))*3.6;
  Serial.println(kph);
}
