#include <forceWind.h>

forceWind::forceWind(void)
	: frontalArea(0.4),
	  dragCoefficient(0.5),
	  airDensity(1.226)
{
}

double forceWind::fWind(double velocityMPS)
{
	double temp;
	temp = 0.5*frontalArea*dragCoefficient*airDensity*velocityMPS*velocityMPS;
	return temp;
}

forceWind::~forceWind(void)
{
}