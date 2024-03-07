#include "Multime.h"
#include <iostream>

template<typename T>
inline Multime<T>::Multime(unsigned int d, T* vector)
{
	this->dim = d;
	for (unsigned int i = 0; i < d; i++) {
		this->vec[i] = vector[i];
	}
}

template<typename T>
Multime<T>::~Multime()
{
	std::cout << "Multime left the chat\n";
}

template<typename T>
void Multime<T>::afisare()
{
	unsigned int d = this->dim;
	for (unsigned int i = 0; i < d; i++) {
		std::cout << this->vec[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
inline Multime<T> Multime<T>::operator+(Multime a)
{
	unsigned int max;
	T vec[10];
	if (this->dim > a.getDim()) {
		max = a.getDim();
	}
	else
	{
		max = this->dim;
	}
	for (unsigned int i = 0; i < max; i++) {
		vec[i] = this->vec[i] + a.getElement(i);
	}
	return Multime(max,vec);
}

template<typename T>
T Multime<T>::operator!()
{
	T max = this->getElement(0);
	for (unsigned int i = 1; i < this->dim; i++) {
		if (max < this->vec[i]) {
			max = this->vec[i];
		}
	}
	return max;
}
