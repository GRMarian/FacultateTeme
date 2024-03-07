#pragma once
#include "Figura.h"
class Patrat : public Figura
{
private:
	int X;
	int Y;
	double lungime;
public:
	~Patrat();
	Patrat() :X(0), Y(0), lungime(0){}
	Patrat(string culoare, int X, int Y, double lungimeLatura) :Figura(culoare), X(X), Y(Y), lungime(lungimeLatura) {}

	void Afisare();
	double Perimetru();
};

