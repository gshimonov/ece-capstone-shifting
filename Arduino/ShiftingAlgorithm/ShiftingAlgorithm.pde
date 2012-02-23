  #include <Max3421e.h>
  #include <Usb.h>
  #include <AndroidAccessory.h>
  #include <androidData.h>

// Increase ADC sample rate to 1us per call
#define FASTADC 1

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif
       
  AndroidAccessory acc("Manufacturer",
  "Model",
  "Description",
  "1.0",
  "http://yoursite.com",
  "0000000012345678");

  androidData pitch(1);

double start = 0;
double t = 0;
double averagingTime = 2000; // 2 seconds
double pitchData = 0;

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



void loop()
{
  t = 0;
  start = millis();
  //measure parameters
  while(t < averagingTime)
  {
    pitch.sample();
//    wheel.sample();
//    cadence.sample();
    t = millis()-start;
  }
  Serial.print("time: ");
  Serial.print(t);
  Serial.print(" samples: ");
  Serial.println(pitch.getCounter());
  
  pitchData = pitch.getAverage(); //average data in sample array and then delete info in array
//  wheelData = wheel.getAverage(); //...
//  cadenceData = cadence.getAverage(); //...

  //calculate speed for desired power
  Serial.println(pitchData);
}
