#pragma once
#include"Roata.h"
class Class
{
private:
	Roata* a;
private:
	Class(unsigned int x)
	{
		this->a = new Roata(x);
	}
	void afisare()
	{
		a->Afisare();
	}
	~Class()
	{
		delete a;
	}
};

