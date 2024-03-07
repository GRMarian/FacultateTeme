#pragma once
#include<string>

class Persoana
{
protected:
	std::string m_sNume;
	std::string m_sAdresa;
public:
	Persoana();
	Persoana(std::string, std::string);
	void schimbareAdresa(std::string);
	void afisareProfil();
};

