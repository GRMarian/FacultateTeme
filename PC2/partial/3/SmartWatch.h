#pragma once
#include"Gadget.h"
typedef unsigned int usig;
class SmartWatch: public Gadget
{
private:
	usig autonomie;
public:
	static usig contor;
	SmartWatch(string s, double d, usig u)
		:Gadget(s, d), autonomie(u) {contor++;}
	void Afisare();
	usig getContor() { return contor; }
	bool operator<(SmartWatch);
};

