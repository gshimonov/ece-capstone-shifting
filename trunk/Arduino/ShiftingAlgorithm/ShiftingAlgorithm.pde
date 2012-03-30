  #include <Max3421e.h>
  #include <Usb.h>
  #include <AndroidAccessory.h>
  #include <androidData.h>
  #include <rpm.h>
  #include <forceWind.h>
  #include <forces.h>
  #include <calculateVelocity.h>
  
// Increase ADC sample rate to 1us per call
#define FASTADC 1

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

#define debounceTime 50
#define wheelPin     0
#define pedalPin     1
#define degToRad     0.0174532925f
#define windConstants 0.3165f
       
  AndroidAccessory acc("Manufacturer",
  "Model",
  "Description",
  "1.0",
  "http://yoursite.com",
  "0000000012345678");

  androidData pitch(1);
  rpm wheel(wheelPin, debounceTime);
  rpm pedal(pedalPin, debounceTime);
  forceWind wind;
  forces rollingResistance(80.0); // 80.0: dummy weight (person + bike)
  forces slope(80.0); // 80.0: dummy weight (person + bike)
  calculateVelocity cv;

double start = 0;
double t = 0;
double averagingTime = 2000; // 2 seconds
double pitchData = 0;
double wheelData = 0;
double pedalData = 0;
double fWind = 0; // force due to wind resistance
double fRollingRes = 0; //force due to rolling resistance
double fSlope = 0; //force due to 
double grade = 0;
double desiredVelocity = 0;

void setup()
{
  #if FASTADC
  // set prescale to 16
  sbi(ADCSRA,ADPS2) ;
  cbi(ADCSRA,ADPS1) ;
  cbi(ADCSRA,ADPS0) ;
  #endif
  
  Serial.begin(9600);
  acc.powerOn(); // Initialize USB accessory

//  androidData pitch(); //this will have input parameters to know what buffer to read from Android
//  velocity wheel(); //this will have input parameters to know what pin to read from, etc.
//  velocity cadence(); //...
}


//debug variables
int iteration;
int samples;

void loop()
{
  iteration = 0;
  t = 0;
  start = millis();
  //measure parameters
  while(t < averagingTime)
  {
    pitch.sample();
    wheel.sample();
    pedal.sample();
    t = millis()-start;
    iteration = iteration + 1;
  }
  samples = pitch.getCounter();
  pitchData = -pitch.getAverage(); //average data in sample array and then delete info in array
                                   //sign change for correctness
  wheelData = wheel.getAverage(); //...
  pedalData = pedal.getAverage(); //...
//  kph = (circum/double(time))*3.6;

if(acc.isConnected())
{
	byte msg[1];
	msg[0]=0.12582*wheelData;
	acc.write(msg,1);
}

  //calculate speed for desired power
  
  grade = tan(pitchData*degToRad); //get grade by computing tangent of pitch (in radians)
  
  fWind = wind.fWind(5.0); // plug in actual velocity in meters/second
  fRollingRes = rollingResistance.fRollingResistance();
  fSlope = slope.fSlope(grade);
  desiredVelocity = cv.getVelocity(250, 0.4, windConstants, fSlope, fRollingRes);
  
  
  Serial.print("loop time: ");
  Serial.print(t);
  Serial.print(" loop iterations: ");
  Serial.print(iteration);
  Serial.print(" android samples: ");
  Serial.print(samples);
  Serial.print(" pitch: ");
  Serial.print(pitchData);
  Serial.print(" kph: ");
  Serial.print(0.12582*wheelData); //0.12582 kph/rpm using 2097mm wheel
  Serial.print(" Pedal RPM: ");
  Serial.print(pedalData);
  Serial.print(" fWind: ");
  Serial.print(fWind);
  Serial.print(" grade: ");
  Serial.print(grade);
  Serial.print(" fRl ");
  Serial.print(fRollingRes);
  Serial.print(" fSl ");
  Serial.println(fSlope);
}
