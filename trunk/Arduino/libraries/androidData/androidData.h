#ifndef __AndroidData_h__
#define __AndroidData_h__

#include "WProgram.h"

#define RCV_BUFFER_BYTES   (64)
#define RCV_NAK_LIMIT      (1)

class androidData {
private:
	int bufferID;
	byte buffer[RCV_BUFFER_BYTES];
	int counter; // Keeps track of number of samples
	float sumData; // Keeps track of sum of all samples
	
public:
	androidData(int bufferID);
	
	void sample(void);
	float getAverage(void);
	int getCounter(void);
};

#endif /* __AndroidData_h__ */
