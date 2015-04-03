// SF2565; Program Construction in C++ for Scientific Computing
// Jonathan Ridenour & Martin Björnmalm
// Project 3 ss

#include "Horzline.h"
#include "Vertline.h"
#include "Curveline.h"
#include "Domain.h"
#include <iostream>
#include <fstream>

using namespace std;

Domain::Domain(Vertline& L1_in, Horzline& L2_in, Vertline& L3_in, Curveline& L4_in){

	L1 = Vertline(L1_in);
	L2 = Horzline(L2_in);
	L3 = Vertline(L3_in);
	L4 = Curveline(L4_in);

	//vectors for holding boundary coordinates
	x_1 = new double [M+1];
	x_2 = new double [N+1];
	x_3 = new double [M+1];
	x_4 = new double [N+1];
	y_1 = new double [M+1];
	y_2 = new double [N+1];
	y_3 = new double [M+1];
	y_4 = new double [N+1];
};

void Domain::generate_grid(){

	//create uniform step size
	double hx = 1.0/N;
	double hy = 1.0/M;

	//use the x and y coordinate functions to generate boundary points
	for(int i = 0; i<N+1; i++){

		x_2[i] = L2.x(i*hx);
		y_2[i] = L2.y(i*hx);
		x_4[i] = L4.x(i*hx);
		y_4[i] = L4.y(i*hx);
	}

	for(int i = 0; i<M+1; i++){

		x_3[i] = L3.x(i*hy);
		x_1[i] = L1.x(i*hy);
		y_1[i] = L1.y(i*hy);
		y_3[i] = L3.y(i*hy);
	}

	//transfinite grid interpolation
	int counter = 0;

	for(int i = 0; i < N+1; i++){
		for (int j = 0; j < M+1; j++){
			x[i][j] = (1-i*1.0/N)*x_1[j] + i*1.0/N*x_3[j] + (1-j*1.0/M)*x_4[i] + j*1.0/M*x_2[i] - (1-i*1.0/N)*(1-j*1.0/M)*(-10) - i*1.0/N*(1-j*1.0/M)*(5) - (1-i*1.0/N)*j*1.0/M*(-10) - i*1.0/N*j*1.0/M*(5);
			y[i][j] = (1-i*1.0/N)*y_1[j] + i*1.0/N*y_3[j] + (1-j*1.0/M)*y_4[i] + j*1.0/M*y_2[i] - (1-i*1.0/N)*(1-j*1.0/M)*(0) - i*1.0/N*(1-j*1.0/M)*(0) - (1-i*1.0/N)*j*1.0/M*(3) - i*1.0/N*j*1.0/M*(3);
			counter++;
		}
	}
	//show the number of nodes:
	cout << "counter: " << counter << endl;
};


void Domain::print(){

	//write the matrix of x-coordinates to file:
	ofstream x_output;
	x_output.open("xfile.txt");

	for(int i = 0; i<N+1; i++){
		for(int j = 0; j<M+1; j++){
			x_output << x[i][j];
			x_output << "\t";
		}
		x_output << "\n";
	}
	x_output.close();
	ofstream y_output;

	//write the matrix of y-coordinates to file:
	y_output.open("yfile.txt");
	for(int i = 0; i<N+1; i++){
		for(int j = 0; j<M+1; j++){
			y_output << y[i][j];
			y_output << "\t";
		}
		y_output << "\n";
	}
	 y_output.close();

	//write the horizontal boundaries to file:
	ofstream rand_2_4;
	rand_2_4.open("rand_2_4.txt");

	for(int i = 0; i<N+1; i++){

		rand_2_4 << x_2[i];
		rand_2_4 << "\t";
		rand_2_4 << y_2[i];
		rand_2_4 << "\t";

		rand_2_4 << x_4[i];
		rand_2_4 << "\t";
		rand_2_4 << y_4[i];
		rand_2_4 << "\n";
	}
	rand_2_4.close();

	//write the vertical boundaries to file:
	ofstream rand_1_3;
	rand_1_3.open("rand_1_3.txt");

	for(int i = 0; i<M+1; i++){
		rand_1_3 << x_1[i];
		rand_1_3 << "\t";
		rand_1_3 << y_1[i];
		rand_1_3 << "\t";

		rand_1_3 << x_3[i];
		rand_1_3 << "\t";
		rand_1_3 << y_3[i];
		rand_1_3 << "\n";
	}
	rand_1_3.close();
};