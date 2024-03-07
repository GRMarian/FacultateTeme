#include "Student.h"
#include <iostream>

Student::Student(std::string nume, std::string adresa, int anStudiu, int notaP2)
:Persoana(nume, adresa), m_iAnStudiu(anStudiu), m_iNotaP2(notaP2) {}
void Student::inscriereAnStudiu(int anStudiuNou)
{
	this->m_iAnStudiu = anStudiuNou;
}
void Student::schimbareNota(int notaP2Nou)
{
	this->m_iNotaP2 = notaP2Nou;
}
void Student::afisareProfil()
{
	Persoana::afisareProfil();
	std::cout << "An studiu: " << m_iAnStudiu << ", Nota P2: " << m_iNotaP2 << std::endl;
}
bool Student::operator>(Student a)
{
	if (this->m_iNotaP2 > a.m_iNotaP2)
	{
		return true;
	}
	return false;
}
