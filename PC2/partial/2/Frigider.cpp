#include "Frigider.h"
#include <iostream>
using std::cout;
Frigider::~Frigider()
{
	cout << "\n Frigider destroyed ";
}

void Frigider::Afisare()
{
	Electrocasnic::Afisare();
	cout << "\n volum ->" << volum;
}

Frigider Frigider::operator++(int a)
{
	this->pret = this->pret + 100;
	return *this;
}

