#include <rpm.h>

rpm::rpm(int analogPin, unsigned long debounceTime)
	: analogPin(analogPin),
	  counter(0),
	  data(0),
	  sumSpeed(0),
	  revPerMin(0),
	  lastPulse(0),
	  time(0),
	  debounceTime(debounceTime),
	  now(0),
	  pulseTime(0)
{
}

void rpm::sample(void)
{		
	data = analogRead(analogPin);
	
	if(data < 100)
	{
		now = millis();
		pulseTime = now - lastPulse;
		if( pulseTime > debounceTime)
		{
			time = pulseTime;
			lastPulse = now;
			revPerMin = (1/((float)time))*60000;
			if(revPerMin > 1088.61) //corresponds to 85 mph using 2097mm wheel,
									//if magnet is not moving and lined up with coil
			{
				revPerMin = 0;
			}
			sumSpeed = revPerMin + sumSpeed;
			counter += 1;
		}
	}
}

float rpm::getAverage(void)
{
   float temp;
	temp = sumSpeed/(float)counter;
	sumSpeed = 0;
	counter = 0;
	return temp;
}

int rpm::getCounter(void)
{
	return counter;
}

	 
