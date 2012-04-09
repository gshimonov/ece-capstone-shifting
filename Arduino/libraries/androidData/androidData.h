#ifndef __AndroidData_h__
#define __AndroidData_h__

#include "WProgram.h"

#define RCV_BUFFER_BYTES   (64)
#define RCV_NAK_LIMIT      (1)

class androidData {
private:
	int bufferID;
	char buffer[RCV_BUFFER_BYTES];
	int counter; // Keeps track of number of samples
	float sumData; // Keeps track of sum of all samples

	unsigned int desiredPower;
	unsigned int desiredCadence;
	unsigned int bikeWeight;
	unsigned int riderWeight;
	float frontalArea;

public:
	androidData(int bufferID);

	void sample(void);
	float getAverage(void);
	int getCounter(void);
	float deserializeFloat(char* buf);
	int deserializeInt(char* buf);
   unsigned int deserializeUInt(char* buf);
	void serialize(char* buf, int inp);
	void serialize(char* buf, float inp);

	unsigned int getDesiredPower();
	unsigned int getDesiredCadence();
	unsigned int getBikeWeight();
	unsigned int getRiderWeight();
	float getFrontalArea();

};

#endif /* __AndroidData_h__ */
