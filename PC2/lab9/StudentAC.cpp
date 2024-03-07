#include "StudentAC.h"
#include <iostream>
using std::cout;
using std::endl;

StudentAC::StudentAC()
{
	std::cout << "constr. fara arg. StudentAC" << std::endl;
	m_ianStudiu = 0;
	m_inotaP2 = 0;
}
StudentAC::StudentAC(std::string cnp, std::string nume,
	std::string adresa, int anStudiu, int notaP2) :
	PersoanaAC(cnp, nume, adresa), m_ianStudiu(anStudiu),
	m_inotaP2(notaP2)
{
	std::cout << "constr. cu arg. StudentAC" << std::endl;
}
StudentAC::~StudentAC()
{
	std::cout << "destructor StudentAC" << std::endl;
}

void StudentAC::afisareProfil()
{
	PersoanaAC::afisareProfil();
	cout << "\n AnStudiu-> " << m_ianStudiu;
	cout << "\n Nota P2 -> " << m_inotaP2;
}

void StudentAC::inscriereAnStudiu(int anStudiuNou)
{
	this->m_ianStudiu = anStudiuNou;
}

bool StudentAC::operator>(StudentAC a)
{
	if (this->m_inotaP2 > a.m_inotaP2)
	{
		return true;
	}
	return false;
}

StudentAC StudentAC::notaMaiMare(StudentAC a)
{
	if (this->m_inotaP2 > a.m_inotaP2)
	{
		return *this;
	}
	return a;
}

void afisareProfil(StudentAC a)
{
	cout << "\n  CNP    -> " << a.m_sCnp;
	cout << "\n  Nume   -> " << a.m_sNume;
	cout << "\n  Adresa -> " << a.m_sAdresa;
	cout << "\n AnStudiu-> " << a.m_ianStudiu;
	cout << "\n Nota P2 -> " << a.m_inotaP2;
	std::cout << "\n";
}
