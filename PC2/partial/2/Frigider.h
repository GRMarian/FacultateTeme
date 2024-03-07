#pragma once
#include "Electrocasnic.h"
typedef unsigned int usig;
class Frigider : public Electrocasnic
{
private:
	usig volum;
public:
	Frigider() :volum(0), Electrocasnic(){}
	Frigider(string a, double p, usig u) :volum(u),Electrocasnic(a,p){}
	~Frigider();

	void Afisare();
	Frigider operator++(int a);
};

