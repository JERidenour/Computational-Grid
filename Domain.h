// SF2565; Program Construction in C++ for Scientific Computing
// Jonathan Ridenour & Martin Björnmalm
// Project 3

#ifndef DOMAIN
#define DOMAIN

class Domain{

public:

	Domain(Vertline& L1, Horzline& L2, Vertline& L3, Curveline& L4);
	void generate_grid();
	void print();

	//number of points in x direction
	const static int N = 50;
	//number of points in y direction
	const static int M = 20;
	Vertline L1,L3;
	Horzline L2;
	Curveline L4;
	double * x_1, * x_2, * x_3, * x_4, * y_1, * y_2, * y_3, * y_4;
	double x[N+1][M+1], y[N+1][M+1];

};

#endif