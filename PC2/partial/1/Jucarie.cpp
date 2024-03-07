#include "Jucarie.h"
#include <iostream>
using std::cout;
Jucarie::~Jucarie()
{
	cout << "\njucarie delet";
}

void Jucarie::Afisare()
{
	cout << "\n\n culoare -> " << culoare;
	cout << "\n pret fara TVA -> " << pret;
}

