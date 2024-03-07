#include "Cerc.h"
#include <iostream>
Cerc::Cerc(int a, int b, int raza)
{
	x = a;
	y = b;
	r = raza;
}
double Cerc::arie()
{
	return 3.14 * r * r;
}
double Cerc::perimetru()
{
	return 2 * 3.1415 * r;
}
void Cerc::afisare()
{
	std::cout << "Cerc cu coordonatele (" << x << "," << y << "),"
		<<"\nraza "<< r 
		<<"\naria " << arie()
		<<"\nperimetru " << perimetru()
		<< std::endl;
}