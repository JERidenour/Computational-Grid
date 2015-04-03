// SF2565; Program Construction in C++ for Scientific Computing
// Jonathan Ridenour & Martin Björnmalm
// Project 3

#include "Curvebase.h"
#include "Horzline.h"

Horzline::Horzline(){};
Horzline::Horzline(double a_in, double b_in, double m_in){
	a = a_in;
	b = b_in;
	m = m_in;
	length = b_in-a_in;
};

double Horzline::xp(double p) {
	return p;
};

double Horzline::yp(double p) {
	return m;
};

double Horzline::dxp(double p) {return 1.0;};
double Horzline::dyp(double p) {return 0.0;};
double Horzline::func(double p) {return 1.0;};