#include "Masina.h"
#include<iostream>
using std::cout;
Masina::~Masina()
{
	cout << "\n Masina delete";
}

void Masina::Afisare()
{
	Jucarie::Afisare();
	cout << "\n numar beterii -> " << nrBterii;
}

bool Masina::operator==(Masina a)
{
	if (this->nrBterii == a.nrBterii)
	{
		return true;
	}
	return false;
}
