#include <gears.h>
#include <Servo.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"	// for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif

extern Servo myServo;

gears::gears(int servoPin)
	: servoPin(servoPin),
	  frontalArea(0.4), //m^2
      dragCoefficient(0.5), //constant
	  airDensity(1.226), //kg/m^3
	  bikeWeight(10),
	  riderWeight(83), //kg
	  rollingCoefficient(.004), //constant
	  desiredCadence(95), // rev/min, multiply by 60 for SI units
	  desiredPower(200), //Watts
	  currentGear(0)
{
	  //initialize upshift array
	  upshift[0] = 38;
	  upshift[1] = 53;
	  upshift[2] = 68;
	  upshift[3] = 85;
	  upshift[4] = 101;
	  upshift[5] = 119;
	  upshift[6] = 132;
	  
	  //initialize downshift array
	  downshift[0] = 20;
	  downshift[1] = 35;
	  downshift[2] = 51;
	  downshift[3] = 67;
	  downshift[4] = 85;
	  downshift[5] = 100;
	  downshift[6] = 117;
	  
	  ratios[0] = 1;
	  ratios[1] = 1.3;
	  ratios[2] = 1.48;
	  ratios[3] = 1.69;
	  ratios[4] = 1.92;
	  ratios[5] = 2.2;
	  ratios[6] = 2.5;
	  ratios[7] = 3.25;
	  
	  myServo.attach(servoPin); // attaches the servo on pin "servoPin" to the servo object
	  myServo.write(downshift[0]);
}

//functions that change parameters
void gears::changeFrontalArea(double input)
{
	frontalArea = input;
}
void gears::changeDragCoefficient(double input)
{
	dragCoefficient = input;
}
void gears::changeAirDensity(double input)
{
	airDensity = input;
}
void gears::changeBikeWeight(double input)
{
	bikeWeight = input;
}
void gears::changeRiderWeight(double input)
{
	riderWeight = input;
}
void gears::changeRollingCoefficient(double input)
{
	rollingCoefficient = input;
}
void gears::changeDesiredCadence(double input)
{
	desiredCadence = input;
}
void gears::changeDesiredPower(double input)
{
	desiredPower = input;
}

//debug code that goes through each gear
//read and write gear position
void gears::sweepGears(void)
{
	for(int i = 0; i <= 6; i++)
	  {
	    myServo.write(upshift[i]);
	    Serial.println(myServo.read());
	    currentGear = i + 2;
	    delay(1000);
	  }
	  delay(2000);
	  for(int i = 6; i >= 0; i--)
	  {
	    myServo.write(downshift[i]);
	    Serial.println(myServo.read());
	    currentGear = i+1;
	    delay(1000);
	  }
	  delay(2000);
}

int gears::readGear(void)
{
	return myServo.read();
}

void gears::changeGear(int gear)
{
	if(gear < currentGear)
	{
		myServo.write(downshift[gear - 1]);
		currentGear = gear;
	}
	else if(gear > currentGear)
	{
		myServo.write(upshift[gear - 2]);
		currentGear = gear;
	}
}

int gears::optimizeGear(double pitch)
{
	double minimum = 1000;
	int gear = 0;
	double velocity;
	double cadence;
	double power;
	double velocity_high = 30; //mps
	double velocity_low = 0; //mps
	double err = 1000;
	
	while(err > .1)
	{
		velocity = (velocity_high + velocity_low)/2;
		power = velocity*(.5*frontalArea*dragCoefficient*airDensity*sq(velocity) + 
				(riderWeight + bikeWeight)*9.8*rollingCoefficient + 
				(riderWeight + bikeWeight)*9.8*tan(pi*pitch/180));
		if(power > desiredPower)
		{
			velocity_high = (velocity_high + velocity_low)/2;
		}
		else
		{
			velocity_low = (velocity_high + velocity_low)/2;
		}
		err = abs(power - desiredPower);
	}
	
	for(int i = 0; i < 8; i++)
	{
		cadence = velocity / (ratios[i]*125.82*(53/25)); //wheel is 2097mm, ratio on gear 1 is 53/25
		if(abs(desiredCadence - cadence) < minimum)
		{
			minimum = abs(desiredCadence - cadence);
			gear = i + 1;
		}
		
	}
	return gear;
}
