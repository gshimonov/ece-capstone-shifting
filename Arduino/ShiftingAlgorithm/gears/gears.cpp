
#include <servo.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"	// for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif

gears::gears(int servoPin)
	: servoPin(servoPin),
	  frontalArea(.5), //m^2
      dragCoefficient(.5), //constant
	  airDensity(1.226), //kg/m^3
	  riderWeight(83), //kg
	  rollingCoefficient(.004), //constant
	  desiredCadence(95), // rev/min, multiply by 60 for SI units
	  desiredPower(200), //Watts
	  currentGear(0)
{
	  //initialize upshift array
	  upshift[0] = 34;
	  upshift[1] = 50;
	  upshift[2] = 64;
	  upshift[3] = 83;
	  upshift[4] = 99;
	  upshift[5] = 115;
	  upshift[6] = 129;
	  
	  //initialize downshift array
	  downshift[0] = 10;
	  downshift[1] = 24;
	  downshift[2] = 40;
	  downshift[3] = 56;
	  downshift[4] = 73;
	  downshift[5] = 91;
	  downshift[6] = 107;
	  
	  myservo.attach(9); // attaches the servo on pin 9 to the servo object
	  myservo.write(downshift[0]);
}

//functions that change parameters
void changeFrontalArea(double input)
{
	frontalArea = input;
}
void changeDragCoefficient(double input)
{
	dragCoefficient = input;
}
void changeAirDensity(double input)
{
	airDensity = input;
}
void changeBikeWeight(double input)
{
	bikeWeight = input;
}
void changeRiderWeight(double input)
{
	riderWeight = input;
}
void changeRollingCoefficient(double input)
{
	rollingCoefficient = input;
}
void changePitch(double input)
{
	pitch = input;
}
void changeDesiredCadence(double input)
{
	desiredCadence = input;
}
void changeDesiredPower(double input)
{
	desiredPower = input;
}

//read and write gear position
void sweepGears(void)
{
	for(int i = 0; i <= 6; i++)
	  {
	    myservo.write(upshift[i]);
	    Serial.println(myservo.read());
	    currentGear = i + 2;
	    delay(1000);
	  }
	  delay(2000);
	  for(int i = 6; i >= 0; i--)
	  {
	    myservo.write(downshift[i]);
	    Serial.println(myservo.read());
	    currentGear = i+1;
	    delay(1000);
	  }
	  delay(2000);
}

int readGear(void)
{
	return myservo.read();
}

void changeGear(int gear)
{
	if(gear < currentGear)
	{
		myservo.write(downshift[gear - 1])
	}
	else if(gear > currentGear)
	{
		myservo.write(upshift[gear - 2])
	}
}

void desiredVelocity()
{
	dobule velocity;
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
	return velocity;
}
