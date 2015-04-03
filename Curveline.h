// SF2565; Program Construction in C++ for Scientific Computing
// Jonathan Ridenour & Martin Björnmalm
// Project 3

#ifndef CURVELINE
#define CURVELINE

class Curveline : public Curvebase{

friend class Domain;

public:

	Curveline();
    Curveline(double a_in, double b_in, double m_in);

    double xp(double p);
    double yp(double p);
    double dxp(double p);
    double dyp(double p);
    double func(double p);
};

#endif