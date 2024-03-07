#pragma once
#include "Figura.h"
class Triunghi : public Figura
{
private:
	struct punct{
		int x;
		int y;
	}P[3];
	double distantaDintre(punct, punct);
public:
	Triunghi(punct a, punct b, punct c)
		:P{ a, b, c}{}
	double semiPerimetru();
	double perimetru();
	double arie();
	void afisare();
};
