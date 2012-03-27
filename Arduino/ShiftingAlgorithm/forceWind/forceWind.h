#ifndef __forceWind_h__
#define __forceWind_h__

class forceWind {
private:
	double frontalArea;
	double dragCoefficient;
	double airDensity;
	
public:
	forceWind();
	
	double fWind(double velocityMPS);
	~forceWind();
};

#endif /* __forceWind_h__ */