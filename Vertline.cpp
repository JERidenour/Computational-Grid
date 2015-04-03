// SF2565; Program Construction in C++ for Scientific Computing
// Jonathan Ridenour & Martin Björnmalm
// Project 3

#include "Curvebase.h"
#include "Vertline.h"

Vertline::Vertline(){};
Vertline::Vertline(double a_in, double b_in, double m_in){
	a = a_in;
	b = b_in;
	m = m_in;
	length = b_in-a_in;
};

double Vertline::xp(double p) {
	return m;
};

double Vertline::yp(double p) {
	return p;
};

double Vertline::dxp(double p) {return 0.0;};
double Vertline::dyp(double p) {return 1.0;};
double Vertline::func(double p) {return 1.0;};