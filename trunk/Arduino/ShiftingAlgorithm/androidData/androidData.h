#ifndef __AndroidData_h__
#define __AndroidData_h__

#include "WProgram.h"

class androidData {
private:
	int bufferID;
	unsigned char buffer[2];
	int counter; // Keeps track of number of samples
	double data;
	double sumData; // Keeps track of sum of all samples
	
public:
	androidData(int bufferID);
	
	void sample(void);
	double getAverage(void);
	int getCounter(void);
};

#endif /* __AndroidData_h__ */