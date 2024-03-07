#include "SmartWatch.h"
#include <iostream>

usig SmartWatch::contor = 0;

void SmartWatch::Afisare()
{
	Gadget::Afisare();
	std::cout << "\n autonomie -> ";
}

bool SmartWatch::operator<(SmartWatch a)
{
	if (this->pret < a.pret)
	{
		return true;
	}
	return false;
}
