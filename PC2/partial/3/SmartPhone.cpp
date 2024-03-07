#include "SmartPhone.h"
#include<iostream>
using std::cout;
SmartPhone::~SmartPhone()
{
	cout << "\n Smartphone deleted";
}

void SmartPhone::Afisare()
{
	Gadget::Afisare();
	cout << "\n diagonale -> " << diagonala;
}

bool SmartPhone::operator==(SmartPhone a)
{
	if (this->diagonala == a.diagonala)
	{
		return true;
	}
	return false;
}
