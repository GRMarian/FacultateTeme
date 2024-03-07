#include "Cerc.h"
#include <iostream>

Cerc::~Cerc()
{
}

void Cerc::Afisare()
{
	std::cout << "\n\n CERC";
	Figura::Afisare();
	std::cout << "\n coordonate X0Y -> [" << this->X << "][" << this->Y << "]";
	std::cout << "\n perimetru -> "<<this->Perimetru();
}

double Cerc::Perimetru()
{
	return 2.0*3.14*this->razaCerc;
}
