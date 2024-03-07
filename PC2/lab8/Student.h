#pragma once
#include "Persoana.h"

class Student : public Persoana
{
private:
	int m_iAnStudiu;
	int m_iNotaP2;
public:
	Student(std::string, std::string, int, int);
	void inscriereAnStudiu(int);
	void schimbareNota(int);
	void afisareProfil();

	bool operator>(Student);
};

