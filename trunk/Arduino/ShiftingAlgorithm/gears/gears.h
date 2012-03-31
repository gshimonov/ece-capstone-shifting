#ifndef __gears_h__
#define __gears_h__

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"	// for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif

#define pi 3.14159265

class gears {
private:
	
	//Arduino control pin for servo
	int servoPin;
	
	//parameters for calculation, don't change very often
	double frontalArea; //m^2
	double dragCoefficient; //constant
	double airDensity; //kg/m^3
	double bikeWeight; //kg
	double riderWeight; //kg
	double rollingCoefficient; //constant
	
	//user preferences
	double desiredCadence;
	double desiredPower;
	
	//current gear
	int currentGear;
	
	//servo positions for each gear (must be calibrated)
	int upshift[7]; 
	int downshift[7];
	double ratios[8];
	
public:
	gears(int servoPin); //class constructor
	
	//functions to change parameters
	void changeFrontalArea(double input);
	void changeDragCoefficient(double input);
	void changeAirDensity(double input);
	void changeBikeWeight(double input);
	void changeRiderWeight(double input);
	void changeRollingCoefficient(double input);
	void changeDesiredCadence(double input);
	void changeDesiredPower(double input);
	
	//read and write gear position
	void sweepGears(void);
	int readGear(void); //returns the gear that the bike is currently in
	void changeGear(int gearNumber); //writes to the servo to change to a specified gear
	
	//calculate desired velocity
	int optimizeGear(double pitch);
};

#endif /* __gears_h__ */