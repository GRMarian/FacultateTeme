#include "Complex.h"
#include <iostream>

void Complex::afisare()
{
	std::cout << this->getReal() << "+" << this->getImag() << "i" << std::endl;
}

Complex Complex::operator+(Complex a)
{
	int r1 = this->getReal();
	int i1 = this->getImag();
	
	return Complex(r1 + a.getReal(), i1 + a.getImag());
}
