#ifndef __rpm_h__
#define __rpm_h__

#include "WProgram.h"

class rpm {
private:
	int analogPin;
	int counter; // Keeps track of number of samples
	double data; // ADC voltage value seen on analog pin
	double sumSpeed; // Keeps track of sum of all samples
	double revPerMin;
	unsigned long lastPulse; // Time when magnet last passed coil 
	unsigned long time; // Time between 2 passes of magnet over coil
	unsigned long debounceTime; // Everyone knows what this is... like duh
	unsigned long now; // Current time recalculated everytime sample is called
	unsigned long pulseTime; // Time between consecutive threshold passings
	
public:
	rpm(int analogPin, unsigned long debounceTime);
	
	void sample(void);
	double getAverage(void);
	int getCounter(void);
};

#endif /* __rpm_h__ */