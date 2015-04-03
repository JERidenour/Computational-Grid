// SF2565; Program Construction in C++ for Scientific Computing
// Jonathan Ridenour & Martin Björnmalm
// Project 3

#ifndef CURVEBASE
#define CURVEBASE

class Curvebase{

friend int main();

protected:
    //starting point
    double a;
    //ending point
    double b;
    //displacement from origo
    double m;
    //arc length
    double length;

    virtual double xp(double p)=0;
    virtual double yp(double p)=0;
    virtual double dxp(double p)=0;
    virtual double dyp(double p)=0;
    virtual double func(double)=0;

public:
    Curvebase();
    Curvebase(const Curvebase& C);
    ~Curvebase();
    double x(double s);
    double y(double s);
    double integrate(double a, double b);
    double I(double, double); 
    double II(double, double);
};

#endif