#include<iostream>
#include "Complex.h"

#include "Multime.h"
#include "Multime.cpp"

#include "Header.h"
#include "Header.cpp"

/*
int main() {
	
	Complex a(2, 3);
	Complex b(4, 5);
	Complex  c =Aduna(a,b);
	c.afisare();
	return 0;
}
*/

int main() {

	Complex f(2, 3);
	Complex e(4, 5);
	Complex  d = Aduna(f, e);
	d.afisare();

	int t[] = { 1,2,3 };
	Multime<int> a(3,t);
	int g[] = { 2,1,3};
	Multime<int> b(3, g);
	a.afisare();
	b.afisare();
	Multime<int> c = Aduna(a, b);
	c.afisare();
	std::cout << c.operator!() << std::endl;

	int* k = new int[3];
	for (int i = 0; i < 3; i++) {
		std::cin>> k[i];
	}

	sort(3, k);

	for (int i = 0; i < 3; i++) {
		std::cout << k[i] << " ";
	}
	std::cout << std::endl;
	delete[] k;

	return 0;
}