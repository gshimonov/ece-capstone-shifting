#include <Max3421e.h>
#include <Usb.h>
#include <AndroidAccessory.h>
#include <androidData.h>

extern AndroidAccessory acc;

androidData::androidData(int bufferID) 
: bufferID(bufferID), 
  counter(0),
  sumData(0),
  desiredPower(150), //Watts
  desiredCadence(60), //rpm
  bikeWeight(8), //kg
  riderWeight(70), //kg
  frontalArea(.5)
{
}

// ADD HANDLING FOR WHEN ANDROID IS NOT CONNECTED
void androidData::sample(void)
{
	int len, idx;
	int print1;
	float data;

	if (acc.isConnected()) 
	{
		len = acc.read(buffer, RCV_BUFFER_BYTES, RCV_NAK_LIMIT); // read data into buffer variable

		if (len == 10) 
		{
			counter += 1; // counter keeps track of number of samples

			//buffer[0:3] - pitch data
			data = deserializeFloat(&buffer[0]);
			sumData += data;

			//buffer[4] - bike weight
			bikeWeight = (int)buffer[4];

			//buffer[5] - rider weight
			riderWeight = (int)buffer[5];

			//buffer[6] - desired cadence
			desiredCadence = (int)buffer[6];

			//buffer[7] - frontal area (range on Android is 0-100, but we want .4 to .6
			frontalArea = ((float)buffer[7])/500 + 0.4;

			//buffer[8] - power
			desiredPower = deserializeInt(&buffer[8]);
		}
		else if(len == -1) //read function returns -1 if nak limit is reached
		{
			Serial.println("nak on Android to Arduino USB connection");
		}
		else //if length is any other size other than 11, we have buffer mismatch
		{
			Serial.println("Android is sending a buffer of incorrect length");
		}

	}
}

float androidData::getAverage(void)
{
	float temp;
	if( counter > 0 )
	{
		temp = sumData/float(counter);
	} 
	else 
	{
		Serial.println("No pitch samples");
		temp = 0; // return 0 if no samples
	}
	sumData = 0;
	counter = 0;
	return temp;
}

int androidData::getCounter(void)
{
	return counter;
}

float androidData::deserializeFloat(char* buf)
{
	float tmp;
	float* fptr;
	char* ptr;
	fptr = &tmp;
	ptr = (char*)(fptr);
	ptr[0] = buf[0];
	ptr[1] = buf[1];
	ptr[2] = buf[2];
	ptr[3] = buf[3];
	return tmp;
}

int androidData::deserializeInt(char* buf)
{
	int tmp;
	int* iptr;
	char* ptr;
	iptr = &tmp;
	ptr = (char*)(iptr);
	ptr[0] = buf[0];
	ptr[1] = buf[1];
	return tmp;
}

void androidData::serialize(char* buf, int inp)
{
	int tmp;
	int* iptr;
	char* ptr;

	tmp = inp;
	iptr = &tmp;
	ptr = (char*)iptr;
	buf[0] = ptr[0];
	buf[1] = ptr[1];
}

void androidData::serialize(char* buf, float inp)
{
	float tmp;
	float* fptr;
	char* ptr;

	tmp = inp;
	fptr = &tmp;
	ptr = (char*)ptr;
	buf[0] = ptr[0];
	buf[1] = ptr[1];
	buf[2] = ptr[2];
	buf[3] = ptr[3];
}

int androidData::getDesiredPower()
{
	return desiredPower;
}
int androidData::getDesiredCadence()
{
	return desiredCadence;
}
int androidData::getBikeWeight()
{
	return bikeWeight;
}
int androidData::getRiderWeight()
{
	return riderWeight;
}
float androidData::getFrontalArea()
{
	return frontalArea;
}

