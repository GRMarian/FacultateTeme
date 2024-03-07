#pragma once
#include "Figura.h"
class Cerc : public Figura
{
private:
	int x, y, r;
public:
	Cerc(int x, int y, int r);
	double arie();
	double perimetru();
	void afisare();
};

