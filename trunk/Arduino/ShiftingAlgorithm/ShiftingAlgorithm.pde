#include <Max3421e.h>
#include <Usb.h>
#include <AndroidAccessory.h>
#include <androidData.h>
#include <rpm.h>
#include <Servo.h>
#include <gears.h>
  
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
#define wheelPin    3
#define pedalPin     2
#define servoPin      9
#define wheelPower    48
#define pedalPower    49
       
  AndroidAccessory acc("Manufacturer",
  "Model",
  "Description",
  "1.0",
  "http://yoursite.com",
  "0000000012345678");

  androidData pitch(1);
  rpm wheel(wheelPin, debounceTime);
  rpm pedal(pedalPin, debounceTime);
  Servo myServo;
  gears myGears(servoPin);

double start = 0;
double t = 0;
double averagingTime = 2000; // 2 seconds
double pitchData = 0;
double wheelData = 0;
double pedalData = 0;
int optimizedGear = 0;
byte msg[1];

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
  pinMode(wheelPower, OUTPUT);
  pinMode(pedalPower, OUTPUT);
  
  digitalWrite(wheelPower, HIGH);
  digitalWrite(pedalPower, HIGH);

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
  wheelData = wheel.getAverage(); //...
  pedalData = pedal.getAverage(); //...
//  kph = (circum/double(time))*3.6;

// Write to Android
if(acc.isConnected())
{
	msg[0]=0.12582*wheelData;
	acc.write(msg,1);
}

  //calculate speed for desired power
  //optimizedGear = myGears.optimizeGear(pitchData);
  optimizedGear = 3;
  //optimizedGear = myGears.optimizeGear(-3, pedalData); //debug value of +7 degrees
  //shift to calculated gear for desired power
  myGears.changeGear(optimizedGear);
  
 /*
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
  Serial.println(pedalData);
 */
  
  //Serial.print("Pitch: ");
  //Serial.print(pitchData);
  Serial.print(" Optimized gear: ");
  Serial.print(optimizedGear);
  Serial.print(" Pedal RPM: ");
  Serial.print(pedalData);
  Serial.print(" wheel m/s: ");
  Serial.println(125.82*wheelData/3600);
  
  delay(500);
  
}
