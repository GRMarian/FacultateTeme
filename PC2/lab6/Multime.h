#pragma once

template<typename T>
class Multime 
{
private:
	T vec[10];
	unsigned int dim;
public:
	Multime() :dim(0), vec{ 0 } {}
	Multime(unsigned int d, T* vector);
	~Multime();

	unsigned int getDim() { return this->dim; }
	T getElement(unsigned int i) { return this->vec[i]; }

	void afisare();
	Multime operator+(Multime);
	T operator!();

};