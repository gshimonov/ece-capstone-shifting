#include <Max3421e.h>
#include <Usb.h>
#include <AndroidAccessory.h>
#include <androidData.h>

extern AndroidAccessory acc;

androidData::androidData(int bufferID) 
	: bufferID(bufferID), 
	  counter(0),
	  data(0),
	  sumData(0)
{
}

// ADD HANDLING FOR WHEN ANDROID IS NOT CONNECTED
void androidData::sample(void)
{		
	if (acc.isConnected()) 
	{
        int len = acc.read(buffer, sizeof(buffer), 10); // read data into buffer variable
        if (len > 0) 
		{
			counter += 1; // counter keeps track of number of samples
			data = buffer[1];
			if (buffer[0] == 200) // corresponds to a positive value
			{ 
				sumData = sumData + data;
			}
			else if (buffer[0] == 255) // corresponds to a negative value
			{ 
				sumData = sumData - data;
			}
		//return true;
		}
		// Handling for when android is not connected
		/*else 
		{
			return false;
		}*/
	}
}

double androidData::getAverage(void)
{
    double temp;
	temp = sumData/(double)counter;
	sumData = 0;
	counter = 0;
	return temp;
}

int androidData::getCounter(void)
{
	return counter;
}

	 