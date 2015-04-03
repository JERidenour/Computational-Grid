// SF2565; Program Construction in C++ for Scientific Computing
// Jonathan Ridenour & Martin Björnmalm
// Project 3

#ifndef HORZLINE
#define HORZLINE

#include "Curvebase.h"

class Horzline : public Curvebase{

friend class Domain;

public:

	Horzline();
    Horzline(double a_in, double b_in, double m_in);

    double xp(double p);
    double yp(double p);
    double dxp(double p);
    double dyp(double p);
    double func(double p);

};

#endif