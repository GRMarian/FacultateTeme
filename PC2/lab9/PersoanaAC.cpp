#include "PersoanaAC.h"
#include <iostream>
using std::cout;

PersoanaAC::PersoanaAC()
{
	std::cout << "\nconstr. fara arg. PersoanaAC" << std::endl;
	m_sCnp = std::string(13, '0');
	m_sNume = "";
	m_sAdresa = "";
}
PersoanaAC::PersoanaAC(std::string cnp, std::string nume,
	std::string adresa)
{
	std::cout << "\nconstr. cu arg. PersoanaAC" << std::endl;
	m_sCnp = cnp;
	m_sNume = nume;
	m_sAdresa = adresa;
}
PersoanaAC::~PersoanaAC()
{
	std::cout << "destructor PersoanaAC" << std::endl;
}

void PersoanaAC::afisareProfil()
{
	cout << "\n  CNP    -> " << m_sCnp;
	cout << "\n  Nume   -> " << m_sNume;
	cout << "\n  Adresa -> " << m_sAdresa;
}

void PersoanaAC::schimbareAdresa(std::string adresaNoua)
{
	this->m_sAdresa = adresaNoua;
}
