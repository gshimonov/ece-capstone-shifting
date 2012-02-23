#include <rpm.h>

rpm::rpm(int analogPin, unsigned long debounceTime)
	: analogPin(analogPin),
	  counter(0),
	  data(0),
	  sumSpeed(0),
	  kph(0),
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
			kph = (2097/(double)time)*3.6;
			if(kph > 136.97424) //max speed 85 mph
			{
				kph = 0;
			}
			/*if(time < 55) //~55ms corresponds to ~85 mph
			{
				time = 1000000000; //time is inverse of speed, not moving -> time between rotation is infinite
			}*/
			sumSpeed = kph + sumSpeed;
			counter += 1;
		}
	}
}

double rpm::getAverage(void)
{
    double temp;
	temp = sumSpeed/(double)counter;
	sumSpeed = 0;
	counter = 0;
	return temp;
}

int rpm::getCounter(void)
{
	return counter;
}

	 