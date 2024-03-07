#pragma once
#include "PersoanaAC.h"
class StudentAC : public PersoanaAC
{
private:
	int m_ianStudiu;
	int m_inotaP2;
public:
	StudentAC();
	StudentAC(std::string cnp, std::string nume, std::string adresa, int anStudiu, int notaP2);
	~StudentAC();
	friend void afisareProfil(StudentAC);
	void afisareProfil();
	void inscriereAnStudiu(int anStudiuNou);
	StudentAC notaMaiMare(StudentAC);
	bool operator>(StudentAC);
};

