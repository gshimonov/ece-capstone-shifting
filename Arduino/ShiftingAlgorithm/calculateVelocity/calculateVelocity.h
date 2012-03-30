#ifndef __calculateVelocity_h__
#define __calculateVelocity_h__

class calculateVelocity {
private:
	double power;
	double frontalArea;
	double windConstants;
	double fS;
	double fR;
	
public:
	calculateVelocity(void);
	
	double getVelocity(double power, double frontalArea, double windConstants, double fS, double fR);
};

#endif /* __calculateVelocity__ */