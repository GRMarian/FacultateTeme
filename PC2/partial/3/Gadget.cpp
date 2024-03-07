#include "Gadget.h"
#include<iostream>
using std::cout;
Gadget::~Gadget()
{
	cout << "\n Gadget deleted ";
}

void Gadget::Afisare()
{
	cout << "\n\n producator -> " << producator;
	cout << "\n pret -> " << pret;
}

