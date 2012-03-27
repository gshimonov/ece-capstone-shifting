#include <forces.h>

forces::forces(double weight)
	: weight(weight),
	  rollingResistance(0.006)
{
}

double forces::fRollingResistance(void)
{
	double temp;
	temp = weight*9.81*rollingResistance;
	return temp;
}

double forces::fSlope(double grade)
{
	double temp;
	temp = weight*9.81*grade;
	return temp;
}

forces::~forces(void)
{
}