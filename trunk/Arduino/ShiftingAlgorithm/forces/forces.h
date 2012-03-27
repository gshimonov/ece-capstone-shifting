#ifndef __forces_h__
#define __forces_h__

class forces {
private:
	double weight;
	double rollingResistance;
	
	
public:
	forces(double weight);
	
	double fRollingResistance();
	double fSlope(double grade);
	~forces();
};

#endif /* __forces_h__ */