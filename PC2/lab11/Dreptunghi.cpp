#include "Dreptunghi.h"
#include <iostream>
Dreptunghi::Dreptunghi(int a1, int b1, int a2, int b2)
{
	x1 = a1;
	y1 = b1;
	x2 = a2;
	y2 = b2;
}
double Dreptunghi::arie()
{
	return (x2 - x1) * (y2 - y1);
}
double Dreptunghi::perimetru()
{
	double rez= (abs(x2 - x1) + abs(y2 - y1)) / 2.0;
	return rez;
}
void Dreptunghi::afisare() {
	std::cout << "Dreptunghi cu coordonatele (" 
		<< x1 << "," << y1<< ")-(" 
		<< x2 << "," << y2 << "),"
		<<"\naria " << arie() 
		<<"\nperimetru "<< perimetru()
		<< std::endl;
}