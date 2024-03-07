#include "Masina.h"
#include <iostream>

void Masina::setRoata(usig x)
{
	for (int i=0; i< 4; i++)
	{
		roti.push_back(Roata(x));
	}
}
Masina::~Masina()
{
	//std::cout << "\nMasina got deleted";
}
void Masina::Afisare()
{
	Jucarie::Afisare();
	std::cout << "\nnr baterii -> " << numar_baterii;
	vector<Roata>::iterator iter = roti.begin();
	for (; iter < roti.end(); iter++)
	{
		iter->Afisare();
	}
}

bool Masina::operator==(Masina M) 
{
	if (this->nume == M.nume)
	{
		return true;
	}
	return false;
}

bool Masina::operator>(Masina a)
{
	if (this->numar_baterii > a.numar_baterii)
	{
		return true;
	}
	return false;
}
