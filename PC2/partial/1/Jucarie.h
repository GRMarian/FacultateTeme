#pragma once
#include<string>
using std::string;

class Jucarie
{
protected:

	string culoare;
	double pret;

public:
	Jucarie():culoare(""),pret(0.0){}
	Jucarie(string s,double d):culoare(s),pret(d){}
	~Jucarie();
	void Afisare();
	void setCuloare(string s) { culoare = s; }
};

