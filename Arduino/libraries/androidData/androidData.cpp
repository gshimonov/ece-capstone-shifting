#include <Max3421e.h>
#include <Usb.h>
#include <AndroidAccessory.h>
#include <androidData.h>

extern AndroidAccessory acc;

androidData::androidData(int bufferID) 
	: bufferID(bufferID), 
	  counter(0),
	  sumData(0)
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
      Serial.println("Bytes read, len = ");
      Serial.println(len);
      Serial.println("Values = ");
      for( idx=0; idx < len; idx++ )
      {
         print1 = (int)buffer[idx];
         Serial.println(print1);
      }

      if (len >= 2) 
		{
         for( idx=1; idx < len; idx = idx + 2 )
         {
			   counter += 1; // counter keeps track of number of samples
			   data = float(buffer[idx]);
			   if (buffer[idx - 1] == (byte)200) // corresponds to a positive value
			   { 
				   sumData = sumData + data;
			   }
			   else if (buffer[idx - 1] == (byte)255) // corresponds to a negative value
			   { 
				   sumData = sumData - data;
			   }
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

float androidData::getAverage(void)
{
   float temp;
   if( counter > 0 )
   {
	   temp = sumData/float(counter);
   } else {
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

	 
