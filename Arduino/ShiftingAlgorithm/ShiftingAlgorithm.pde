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
// unsigned long ttemp;
float averagingTime = 2000; //ms
float pitchData = 0;
float wheelData = 0;
float pedalData = 0;
int optimizedGear = 0;

float desiredPower = 0;
float desiredCadence = 0;
float bikeWeight = 0;
float riderWeight = 0;
float frontalArea = 0;

byte msg[16];

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
  float mph;
  int prnt1;
  int pedal_int;
  int speed_int;

  tcur = millis();
  // measure parameters
  
  /*
  Serial.print("tcur = ");
  Serial.println(tcur);
  Serial.print("tprev = ");
  Serial.println(tprev);
  */
  
  /*
  Serial.print("Millis before sample loop: ");
  ttemp = millis();
  Serial.println(ttemp);
  */
  
  while( (float)(tcur - tprev) <= averagingTime )
  { 
     pitch.sample();
     tcur = millis();
  }
  
  /*
  Serial.print("Millis after sample loop: ");
  ttemp = millis();
  Serial.println(ttemp);
  */
  
    tprev = tcur;
    wheelData = getAverageSpeedKPH();
    /*
    Serial.print("WheelData = ");
    Serial.println(wheelData);
    */
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
  
  /*
  Serial.print("Millis before write: ");
  ttemp = millis();
  Serial.println(ttemp);
  */
  
    // Write speed (mph), optimizedGear, cadence (rpm) to the Android app
    if(acc.isConnected())
    {
       // Serial.println("sending Android speed data (mph): ");
       mph = mps*2.2369; // meters per second to mph conversion
       speed_int = int(mph);
       // Serial.println(mph);
       // Serial.print("speed int: ");
       // Serial.println(speed_int);
       msg[0]= (byte)((speed_int & (int)0xFF00) >> 8);
       msg[1] = (byte)(speed_int & (int)0x00FF);
       msg[2] = byte(optimizedGear); // send current gear
       pedal_int = int(pedalData);
       // Serial.print("pedal int: ");
       // Serial.println(pedal_int);
       msg[3] = (byte)((pedal_int & (int)0xFF00) >> 8); // send cadence
       msg[4] = (byte)(pedal_int & (int)0x00FF);
       acc.write(msg,5);
    }
    /*
 Serial.print("Millis after write: ");
 ttemp = millis();
 Serial.println(ttemp);
 */
    
    myGears.changeCurrentVelocity(filt_mps);
    myGears.changeCurrentCadence(pedalData);
    
/*    if (pitchData < -5.0f) {
      pitchData = -5.0f;
    }
    */
    // Serial.println("passed pitch test");
    
    //reset user preferences with updates from Android
    desiredPower = (float)pitch.getDesiredPower();
    desiredCadence = (float)pitch.getDesiredCadence();
    riderWeight = (float)pitch.getRiderWeight();
    bikeWeight = (float)pitch.getBikeWeight();
    frontalArea = (float)pitch.getFrontalArea();
    myGears.changeDesiredPower(desiredPower);
    myGears.changeDesiredCadence(desiredCadence);
    myGears.changeRiderWeight(riderWeight);
    myGears.changeBikeWeight(bikeWeight);
    myGears.changeFrontalArea(frontalArea);

/*
  Serial.print("Millis before optimizeGear: ");
  ttemp = millis();
  Serial.println(ttemp);
  */
  
    // calculate optimal gear based on pitch and user pref
    optimizedGear = myGears.optimizeGear(pitchData);
    myGears.changeGear(optimizedGear);

/*
  Serial.print("Millis after optimizeGear: ");
  ttemp = millis();
  Serial.println(ttemp);
  */
  
    // print useful information to computer - for debugging
    Serial.print(" Pitch: ");
    Serial.print(pitchData);
    Serial.println();
    Serial.print(" desired power: ");
    Serial.print(desiredPower);
    Serial.println();
    Serial.print(" desired cadence: ");
    Serial.print(desiredCadence);
    Serial.println();
    Serial.print(" rider weight: ");
    Serial.print(riderWeight);
    Serial.println();
    Serial.print(" bike weight: ");
    Serial.print(bikeWeight);
    Serial.println();
    Serial.print(" frontal area: ");
    Serial.print(frontalArea);
    Serial.println();

  // delay(25);  
}

