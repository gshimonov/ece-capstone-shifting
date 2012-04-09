#ifndef __gears_h__
#define __gears_h__

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"	// for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif

#define pi 3.14159265

#define VEL_DIFF_MIN          (0.25f)     // mps
#define VEL_LOW_START         (0.0f)      // mps
#define VEL_HIGH_START        (100.0f)    // mps
#define ERR_START             (1000.0f)   // unitless
#define CADENCE_MIN_START     (1000.0f)   // rpm
#define GEAR_MAX              (8)
#define GEAR_MIN              (1)

class gears {
private:
	
	//Arduino control pin for servo
	int servoPin;
	
	//parameters for calculation, don't change very often
	float frontalArea; //m^2
	float dragCoefficient; //constant
	float airDensity; //kg/m^3
	float bikeWeight; //kg
	float riderWeight; //kg
	float rollingCoefficient; //constant
	
	//user preferences
	float desiredCadence;
	float desiredPower;
	
	//measured parameters
	float currentVelocity;
	float currentCadence;
	
	//current gear
	int currentGear;
	
	//servo positions for each gear (must be calibrated)
	int shift[8]; 
	float ratios[8];
	
public:
	gears(int servoPin); //class constructor
	
	//functions to change parameters
	void changeFrontalArea(float input);
	void changeDragCoefficient(float input);
	void changeAirDensity(float input);
	void changeBikeWeight(float input);
	void changeRiderWeight(float input);
	void changeRollingCoefficient(float input);
	void changeDesiredCadence(float input);
	void changeDesiredPower(float input);
	void changeCurrentVelocity(float input);
	void changeCurrentCadence(float input);
	
	//read and write gear position
	int readGear(void); //returns the gear that the bike is currently in
	void changeGear(int gearNumber); //writes to the servo to change to a specified gear
	
	//calculate desired velocity
	int optimizeGear(float pitch);
};

#endif /* __gears_h__ */
