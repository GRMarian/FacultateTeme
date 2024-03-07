#pragma once
#include<iostream>
typedef unsigned int usig;
class Roata
{
private:
	usig dimesiune_roata;
public:
	Roata(usig x) :dimesiune_roata(x){}
	~Roata();
	void Afisare();
	void setRoata(usig x) { dimesiune_roata = x; }
};

