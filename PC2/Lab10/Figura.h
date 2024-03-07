#pragma once
#include<string>
using std::string;

class Figura
{
private:
	string culoare;
public:
	~Figura();
	Figura(string culoare) :culoare(culoare){}
	Figura() :culoare(""){}

	virtual void Afisare();
	virtual double Perimetru();
};

