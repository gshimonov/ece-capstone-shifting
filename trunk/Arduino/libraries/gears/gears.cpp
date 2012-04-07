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
	  currentVelocity(0),
	  currentCadence(0),
	  currentGear(0)
{
	  //initialize shift array
	  shift[0] = 1835;
	  shift[1] = 1760;
	  shift[2] = 1670;
	  shift[3] = 1590;
	  shift[4] = 1505;
	  shift[5] = 1430;
	  shift[6] = 1350;
	  shift[7] = 1265;
	  
	  ratios[0] = 1;
	  ratios[1] = 1.3;
	  ratios[2] = 1.48;
	  ratios[3] = 1.69;
	  ratios[4] = 1.92;
	  ratios[5] = 2.2;
	  ratios[6] = 2.5;
	  ratios[7] = 3.25;
}

//functions that change parameters
void gears::changeFrontalArea(float input)
{
	frontalArea = input;
}
void gears::changeDragCoefficient(float input)
{
	dragCoefficient = input;
}
void gears::changeAirDensity(float input)
{
	airDensity = input;
}
void gears::changeBikeWeight(float input)
{
	bikeWeight = input;
}
void gears::changeRiderWeight(float input)
{
	riderWeight = input;
}
void gears::changeRollingCoefficient(float input)
{
	rollingCoefficient = input;
}
void gears::changeDesiredCadence(float input)
{
	desiredCadence = input;
}
void gears::changeDesiredPower(float input)
{
	desiredPower = input;
}
void gears::changeCurrentVelocity(float input)
{
	currentVelocity = input;
}
void gears::changeCurrentCadence(float input)
{
	currentCadence = input;
}

int gears::readGear(void)
{
	return currentGear;
}

void gears::changeGear(int gear)
{
	if(gear != currentGear)
	{
		digitalWrite(5, LOW);
		delay(100);
		myServo.writeMicroseconds(shift[gear - 1]);
		Serial.println(shift[gear-1]);
		delay(500);
		digitalWrite(5, HIGH);
		currentGear = gear;
	}
}

int gears::optimizeGear(float pitch)
{
	float minimum = 1000.0f;
	int gear = 0;
	float velocity;
	float cadence;
	float power;
	float velocity_high = 40.0f; //mps
	float velocity_low = 0.0f; //mps
	float err = 1000.0f;
	
	Serial.println("current velocity is: ");
	Serial.print(currentVelocity);
	Serial.println();
	
	Serial.println("current cadence is: ");
	Serial.print(currentCadence);
	Serial.println();
	
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
      Serial.print("err: ");
      Serial.println(err);
	}
   Serial.println("left loop");

	if(currentVelocity >= (0.80 * velocity))
	{
		Serial.println("power based mode");
		for(int i = 0; i < 8; i++)
		{
			cadence = velocity / (ratios[i]*.03495*(53/25)); //wheel is 2097mm, ratio on gear 1 is 53/25
			if(abs(desiredCadence - cadence) < minimum)
			{
				minimum = abs(desiredCadence - cadence);
				gear = i + 1;
			}
		}
	}
	else
	{
		Serial.println("ramp up mode");
		for(int i = 0; i < 8; i++)
			{
				cadence = currentVelocity / (ratios[i]*.03495*(53/25)); //wheel is 2097mm, ratio on gear 1 is 53/25
				if(abs(desiredCadence - cadence) < minimum)
				{
					minimum = abs(desiredCadence - cadence);
					gear = i + 1;
				}
			}
	}
	return gear;
}
