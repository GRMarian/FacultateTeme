#include "StudentMaster.h"
#include <iostream>

StudentMaster::StudentMaster() :m_sNumeDizertatie(string(10, '#'))
{
	std::cout << "constr. fara arg. StudentMaster" << std::endl;
}
StudentMaster::StudentMaster(string NumeDizertatie, string cnp, string nume, string adresa, int anStudiu, int notaP2)
	:StudentAC(cnp, nume, adresa, anStudiu, notaP2), m_sNumeDizertatie(NumeDizertatie) 
{
	std::cout << "constr. cu arg. StudentMaster" << std::endl;
}
StudentMaster::~StudentMaster()
{
	std::cout << "destructor StudentAC" << std::endl;
}

StudentAC StudentMaster::getStudent()
{
	StudentAC a = *this;
	return a;
}

void StudentMaster::afisareProfil()
{
	StudentAC::afisareProfil();
	std::cout << "\nDizeratie-> " << this->m_sNumeDizertatie;
}
