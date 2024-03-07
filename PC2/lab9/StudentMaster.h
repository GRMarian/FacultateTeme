#pragma once
#include "StudentAC.h"
using std::string;

class StudentMaster : public StudentAC
{
private:
	std::string m_sNumeDizertatie;
public:
	StudentMaster();
	StudentMaster(string NumeDizertatie, string cnp, string nume, string adresa, int anStudiu, int notaP2);
	~StudentMaster();

	StudentAC getStudent();
	void afisareProfil();
};

