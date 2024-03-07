#pragma once
#include "Figura.h"
class Cerc : public Figura
{
private:
	int X;
	int Y;
	int razaCerc;
		
public:
	~Cerc();
	Cerc(string culoare,int x, int y, int lungime) :Figura(culoare),X(x), Y(y), razaCerc(lungime){}

	void Afisare();
	double Perimetru();
};

