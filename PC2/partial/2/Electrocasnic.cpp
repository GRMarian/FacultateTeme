#include "Electrocasnic.h"
#include<iostream>
using std::cout;

Electrocasnic::~Electrocasnic()
{
	cout << "\n Electronic destroyed";
}

void Electrocasnic::Afisare()
{
	cout << "\n\n producatro->" << this->producator;
	cout << "\n pret fara TVA ->" << this->pret;

}
