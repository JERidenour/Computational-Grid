// SF2565; Program Construction in C++ for Scientific Computing
// Jonathan Ridenour & Martin Björnmalm
// Project 3

#include "Curvebase.h"
#include <cmath>
#include <list>
#include <iostream>

using namespace std;

//constructor
Curvebase::Curvebase(){};   //constructor

//copy constructor
Curvebase::Curvebase(const Curvebase& C){
    a = C.a;
    b = C.b;
    m = C.m;
    length = C.length;
};

//destructor
Curvebase::~Curvebase(){};

//create x coordinates based on arc length
double Curvebase::x(double s){

    //initial guess
    double p = 0.5;
    double err, tol=1e-6, p1;
    int it, maxit=100;
    it=0;
    err = tol+1;
    //newtons method
    while( err > tol && it < maxit){
        p1 = p - (integrate(a, p) - s*length)/func(p);
        err = fabs(p1-p); p = p1; it++;
    }
    if(it == maxit){
        cout << "maxit reached for x" << endl;
    }
    return xp(p1);
};

//create y coordinates based on arc length
double Curvebase::y(double s){
    //initial guess
    double p = 0.5;
    double err, tol=1e-6, p1;
    int it, maxit=100;
    it=0;
    err = tol+1;
    //newtons method
    while( err > tol && it < maxit){
        p1 = p - (integrate(a, p) - s*length)/func(p);
        err = fabs(p1-p); p = p1; it++;
    }
    if(it == maxit){
        cout << "maxit reached for y" << endl;
    }
    return yp(p1);
};

//integrate the member function "func" from ain to bin
double Curvebase::integrate(double a_in, double b_in){
    
    double lbound;
    double hbound;
    double I1;
    double I2;
    double a = a_in;
    double b = b_in;
    double err = 1e-5;
    double I_value = 0;
    list<double> list;
    list.push_front(a);
    list.push_back(b);

    while(list.size() > 1){

        lbound=list.front();
        list.pop_front();
        hbound=list.front();
        I1=I(lbound,hbound);
        I2=II(lbound,hbound);

        // check if value of error is acceptable
        if (15*abs(I1-I2) < err) {
            I_value += I2;
        }
        // if not then add midpoint to list of domains to be integrated over
        else{
            list.push_front((lbound+hbound)/2);
            list.push_front(lbound);               
        }
    }
    return I_value;
};

//help function for integrate()
double Curvebase::I(double a, double b){
    double I1;
    I1=((b-a)/6)*(func(a)+4*func((a+b)/2)+func(b));
    return I1;
}

//help function for integrate()
double Curvebase::II(double a, double b){
    double I2;
    I2=I(a,(a+b)/2)+I((a+b)/2, b);
    return I2;
}