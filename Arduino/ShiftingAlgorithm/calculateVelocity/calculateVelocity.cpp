#include <calculateVelocity>

calculateVelocity::calculateVelocity(void)
	: power(power),
	  frontalArea(frontalArea),
	  windConstatns(0.3165), //0.5*Cw*Rho = 0.3165
	  fS(fS),
	  fR(fR)
{
}

double calculateVelocity::getVelocity(double power, double frontalArea, double windConstants, double fS, double fR)
{
	double tempPower;
	double tempVelocity;
	double fW; //force of wind
	for (velocity = 1; velocity <= 20; velocity++) {
		fW = frontalArea*windConstants*velocity*velocity; // 0.5*A*Cw*Rho*V^2
		tempPower = velocity*(fW+fR+fS);
		if (abs(power-tempPower) <= 10) {
			return tempVelocity;
		}
	}
}