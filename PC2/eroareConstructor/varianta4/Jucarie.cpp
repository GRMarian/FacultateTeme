#include "Jucarie.h"
#include<iostream>
Jucarie::~Jucarie()
{
	//std::cout<<"\njucarie deleted";
}

void Jucarie::Afisare()
{
	std::cout << "\n\nnume -> " << nume;
	std::cout << "\ndouble -> " << dbl;
}
