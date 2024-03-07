#include "Persoana.h"
#include <iostream>

Persoana::Persoana()
{
	m_sNume = "nume";
	m_sAdresa = "adresa";
}

Persoana::Persoana(std::string nume, std::string adresa)
{
	m_sNume = nume;
	m_sAdresa = adresa;
}
void Persoana::schimbareAdresa(std::string adresaNoua)
{
	this->m_sAdresa = adresaNoua;
}
void Persoana::afisareProfil()
{
	std::cout << "Nume: " << m_sNume << ", Adresa: " << m_sAdresa << std::endl;
}