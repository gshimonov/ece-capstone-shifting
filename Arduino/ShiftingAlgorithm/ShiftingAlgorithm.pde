#include <Max3421e.h>
#include <Usb.h>
#include <AndroidAccessory.h>
#include <androidData.h>
#include <rpm.h>
#include <rpm_int.h>
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

unsigned long tcur, tprev;
float averagingTime = 2000; //ms
float pitchData = 0;
float wheelData = 0;
float pedalData = 0;
int optimizedGear = 0;
byte msg[1];

void setup()
{
  analogReference(DEFAULT);
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
  
  myServo.attach(servoPin, 1100, 1900);
  pinMode(5, OUTPUT);

  timer3_setup();
  timer4_setup();
  timers_sync();
  pedal_setup();
  wheel_setup();

  tprev = millis();
}

void loop()
{
  float mps;
  float filt_mps;
  float tmpflt;
  int prnt1;

  tcur = millis();
  // measure parameters
  
  while( (float)(tcur - tprev) <= averagingTime )
  { 
     pitch.sample();
     tcur = millis();
  }
  
    tprev = tcur;
    wheelData = getAverageSpeedKPH();
    Serial.print("WheelData = ");
    Serial.println(wheelData);
    pedalData = getAverageCadenceRPM();
    pitchData = pitch.getAverage(); // average data in sample array and then delete info in array

    // mps = 125.82*wheelData/3600; // convert to meters per second from rpm
    mps = wheelData*(1000.0f/3600.0f); // convert from kph to meters per second
    if(mps < 1.0f)
    {
      filt_mps = 1.0f;
    } else {
      filt_mps = mps;
    }
    
    // Write to Android
    if(acc.isConnected())
    {
       Serial.println("sending Android speed data: ");
       tmpflt = mps*2.2369;
       Serial.println(tmpflt);
       msg[0]= byte(tmpflt); // meters per second to mph conversion
       Serial.println("Rounded:");
       prnt1 = (int)msg[0];
       Serial.println(prnt1);
       acc.write(msg,1);
    }
    
    myGears.changeCurrentVelocity(filt_mps);
    myGears.changeCurrentCadence(pedalData);

    // calculate speed for desired power
    optimizedGear = myGears.optimizeGear(pitchData);
    myGears.changeGear(optimizedGear);

    // print useful information to computer - for debugging
    Serial.print(" Pitch: ");
    Serial.print(pitchData);
    Serial.print(" Optimized gear: ");
    Serial.print(optimizedGear);
    Serial.print(" Pedal RPM: ");
    Serial.print(pedalData);
    Serial.print(" wheel m/s: ");
    Serial.println(mps);


  // delay(25);  
}

