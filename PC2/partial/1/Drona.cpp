#include "Drona.h"
#include<iostream>
void Drona::Afisare()
{
	Jucarie::Afisare();
	std::cout << "\n numar elice -> " << nrElice;

}

bool Drona::operator>(Drona a)
{
	if (this->nrElice > a.nrElice)
	{
		return true;
	}
	return false;
}

bool Drona::operator<(Drona a)
{
	if (this->nrElice < a.nrElice)
	{
		return true;
	}
	return false;
}
