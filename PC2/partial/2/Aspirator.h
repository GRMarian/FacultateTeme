#pragma once
#include"Electrocasnic.h"
typedef unsigned int usig;
class Aspirator : public Electrocasnic
{
private:
	usig volum;
public:
	Aspirator(usig v, string a, double p) :volum(v), Electrocasnic(a, p){}
	void Afisare();
	static bool criteriuVolum(Aspirator, Aspirator);
	bool operator>(Aspirator);
};
