#pragma once
#include "Persoana.h"
#include "Student.h"
#include <vector>

class Profesor : public Persoana
{
private:
	std::string m_sGradDidactic;
	std::vector<Student> m_studenti;
public:
	Profesor(std::vector<Student>,std::string,Persoana);
	void acordaNota(int, int);
	void afisareStudenti();
	void sortDescrescator();
};

bool cmp(Student a, Student b);