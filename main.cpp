// SF2565; Program Construction in C++ for Scientific Computing
// Jonathan Ridenour & Martin Björnmalm
// Project 3

#include "Vertline.h"
#include "Horzline.h"
#include "Curveline.h"
#include "Domain.h"

int main(){
 	
	//left boundary
	double a_1 = 0.0;
	double b_1 = 3.0;
	double m_1 = -10.0;

	//upper boundary
	double a_2 = -10.0;
	double b_2 = 5.0;
	double m_2 = 3.0;

 	//right boundary
	double a_3 = 0.0;
	double b_3 = 3.0;
	double m_3 = 5.0;

 	//lower boundary 
	double a_4 = -10.0;
	double b_4 = 5.0;
	double m_4 = 10.0;

	//create the boundary curves
	Vertline L1 = Vertline(a_1, b_1, m_1);
	Horzline L2 = Horzline(a_2, b_2, m_2);
	Vertline L3 = Vertline(a_3, b_3, m_3);
	Curveline L4 = Curveline(a_4, b_4, m_4);

	//initialize a domain
	Domain D = Domain(L1, L2, L3, L4);

	//create grid points
	D.generate_grid();

	//print to file
	D.print();

	return 0;
}