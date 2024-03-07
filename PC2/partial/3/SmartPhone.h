#pragma once
#include"Gadget.h"
typedef unsigned int usig;
class SmartPhone:public Gadget
{
private:
	usig diagonala;
public:
	SmartPhone() :Gadget(), diagonala(0){}
	SmartPhone(string s, double d, usig u)
		:Gadget(s, d), diagonala(u){}
	~SmartPhone();
	void Afisare();
	bool operator==(SmartPhone);
};

