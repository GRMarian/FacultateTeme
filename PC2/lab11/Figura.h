#pragma once
class Figura
{
public:
	virtual ~Figura() {}
	virtual double arie() = 0;
	virtual double perimetru() = 0;
	virtual void afisare() = 0;

	bool operator<(Figura*);
};

