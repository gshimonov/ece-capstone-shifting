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

unsigned long lastPulse = 0;
unsigned long time = 0;
unsigned long debounceTime = 0;
unsigned long now = 0;

double circum = 2097.0; // wheel circum: 2097mm
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

void loop()
{
speedSample = analogRead(speedPin);

if(speedSample < 100)
{
 now = millis();
 debounceTime = now - lastPulse;
 if( debounceTime > 50)
 {
   time = debounceTime;
   lastPulse = now;
   kph = (circum/double(time))*3.6;
   if(kph > 136.97424) //max speed 85 mph
   {
     kph = 0;
   }
   Serial.println(kph);
 }
}


}
