#include "Roata.h"
#include <iostream>

Roata::~Roata()
{
	//std::cout << "\nroata got deleted";
}

void Roata::Afisare()
{
	std::cout << "\n roata -> " << dimesiune_roata;
}
