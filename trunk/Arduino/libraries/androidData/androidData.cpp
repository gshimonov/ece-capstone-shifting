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

   // Serial.println("Inside androidData sample");
	if (acc.isConnected()) 
	{
		len = acc.read(buffer, RCV_BUFFER_BYTES, RCV_NAK_LIMIT); // read data into buffer variable
      // Serial.println("read finished");

		if (len == 12) 
		{
			counter += 1; // counter keeps track of number of samples

			//buffer[0:3] - pitch data
			data = deserializeFloat(&buffer[0]);
			sumData += data;
         
         /*
         Serial.println("Pitch bytes: ");
         Serial.println(buffer[0], HEX); 
         Serial.println(buffer[1], HEX);
         Serial.println(buffer[2], HEX);
         Serial.println(buffer[3], HEX);
         */

         /*
         Serial.println("Power bytes: ");
         Serial.println(buffer[8], HEX);
         Serial.println(buffer[9], HEX);
         */

			//buffer[4] - bike weight
			bikeWeight = (unsigned int)buffer[4];

			//buffer[5] - rider weight
			riderWeight = deserializeUInt(&buffer[5]);

			//buffer[6] - desired cadence
			desiredCadence = deserializeUInt(&buffer[7]);

			//buffer[7] - frontal area (range on Android is 0-100, but we want .4 to .6
			frontalArea = ((float)buffer[9])/500 + 0.4;

			//buffer[8] - power
			desiredPower = deserializeUInt(&buffer[10]);
         // Serial.println("Successfully received correct len packet from Android");
		}
		else if( len > 0 ) //if length is any other size other than 12, we have buffer mismatch
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

// Android sends big endian, reverse byte order to little endian
float androidData::deserializeFloat(char* buf)
{
	float tmp;
	float* fptr;
	char* ptr;
	fptr = &tmp;
	ptr = (char*)(fptr);
	ptr[0] = buf[3];
	ptr[1] = buf[2];
	ptr[2] = buf[1];
	ptr[3] = buf[0];
	return tmp;
}

// Android sends big endian, reverse byte order to little endian
int androidData::deserializeInt(char* buf)
{
	int tmp;
	int* iptr;
	char* ptr;
	iptr = &tmp;
	ptr = (char*)(iptr);
	ptr[0] = buf[1];
	ptr[1] = buf[0];
	return tmp;
}

// Android sends big endian, reverse byte order to little endian
unsigned int androidData::deserializeUInt(char* buf)
{
	unsigned int tmp;
	unsigned int* iptr;
	char* ptr;
	iptr = &tmp;
	ptr = (char*)(iptr);
	ptr[0] = buf[1];
	ptr[1] = buf[0];
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

unsigned int androidData::getDesiredPower()
{
	return desiredPower;
}
unsigned int androidData::getDesiredCadence()
{
	return desiredCadence;
}
unsigned int androidData::getBikeWeight()
{
	return bikeWeight;
}
unsigned int androidData::getRiderWeight()
{
	return riderWeight;
}
float androidData::getFrontalArea()
{
	return frontalArea;
}

