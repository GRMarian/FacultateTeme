#include "Profesor.h"
#include<algorithm>

Profesor::Profesor(std::vector<Student> b, std::string a, Persoana c) 
:m_studenti(b), m_sGradDidactic(a), Persoana(c){}
void Profesor::acordaNota(int iter, int Nota)
{
	this->m_studenti[iter].schimbareNota(Nota);
}
void Profesor::afisareStudenti()
{
	std::vector<Student>::iterator iter;
	iter = this->m_studenti.begin();
	for (; iter < this->m_studenti.end(); iter++)
	{
		iter->afisareProfil();
	}
}
void Profesor::sortDescrescator()
{
	std::sort(this->m_studenti.begin(), this->m_studenti.end(), cmp );
}
bool cmp(Student a, Student b)
{
	return a > b;
}