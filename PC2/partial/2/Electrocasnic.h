#pragma once
#include <string>
using std::string;

class Electrocasnic
{
protected:
	string producator;
	double pret;
public:
	Electrocasnic() :producator(""), pret(0.0) {}
	Electrocasnic(string a, double p): producator(a), pret(p) {}
	~Electrocasnic();

	void Afisare();
	void setPret(double a) { this->pret = a; }
};

