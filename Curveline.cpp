// SF2565; Program Construction in C++ for Scientific Computing
// Jonathan Ridenour & Martin Björnmalm
// Project 3

#include "Curvebase.h"
#include "Curveline.h"
#include <cmath>

Curveline::Curveline(){};
Curveline::Curveline(double a_in, double b_in, double m_in){
	a = a_in;
	b = b_in;
	m = m_in;
	length = integrate(a, b);
};

//x coordinate parameterization 
double Curveline::xp(double p) {
	return p;
};

//y coordinate parameterization 
double Curveline::yp(double p) {
	if(p < -3){
		return 0.5*1/(1+exp(-3*(p+6)));
	}else{
		return 0.5*1/(1+exp(3*(p)));
	}
};

//p-derivative of x parameterization 
double Curveline::dxp(double p) {
	return 1 ;
};

//p-derivative of y parameterization 
double Curveline::dyp(double p) {
	if(p < -3){
		return 3.0/2*exp(-3*(p)-18.0)/((1+exp(-3*(p)-18))*(1+exp(-3*(p)-18)));
	}else{
		return -3.0/2*exp(3*(p))/((1+exp(3*(p)))*(1+exp(3*(p))));
	}
};

//function we wish to integrate when generating the arc length
double Curveline::func(double p){
	return sqrt(dyp(p)*dyp(p)+dxp(p)*dxp(p));
};