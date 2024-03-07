#pragma once
#include<string>
using std::string;

class Gadget
{
protected:
	string producator;
	double pret;

public:
	Gadget() :producator(""), pret(0.0){}
	Gadget(string s, double d) : producator(s), pret(d) {}
	~Gadget();
	void Afisare();
	void setPret(double d) { pret = d; }
};

