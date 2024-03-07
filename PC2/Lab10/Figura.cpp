#include "Figura.h"
#include <iostream>
Figura::~Figura()
{
}

void Figura::Afisare()
{
	std::cout << " \n culoare -> " << culoare;
}

double Figura::Perimetru()
{
	return 0.0;
}
