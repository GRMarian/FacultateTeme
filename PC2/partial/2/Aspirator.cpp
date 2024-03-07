#include "Aspirator.h"
#include <iostream>
using std::cout;

void Aspirator::Afisare()
{
	Electrocasnic::Afisare();
	cout << "\n volum ->" << this->volum;
}

bool Aspirator::criteriuVolum(Aspirator a, Aspirator b)
{
	if (a.volum > b.volum)
	{
		return true;
	}
	return false;
}

bool Aspirator::operator>(Aspirator a)
{
	if (this->pret > a.pret)
	{
		return true;
	}
	return false;
}

