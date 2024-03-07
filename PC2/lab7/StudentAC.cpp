#include "StudentAC.h"
#include <iostream>
#include <string>
#include <vector>
using std::string;

void StudentAC::afisare()
{
	string sir = this->nume;
	string::iterator iter = sir.begin();
	std::cout << "\nnume : ";
	for (; iter != sir.end(); iter++)
	{
		std::cout << *iter;
	}
	std::cout << "\nnota : " << this->nota;
}

void StudentAC::modificareNota(int nouaNota)
{
	this->nota = nouaNota;
}

bool StudentAC::operator<(StudentAC a)
{
	if (this->nota < a.nota)
	{
		return true;
	}
	return false;
}

void afisare(std::vector<StudentAC> v)
{
	std::vector<StudentAC>::iterator iter = v.begin();
	for (; iter != v.end(); iter++)
	{
		iter->afisare();
	}
}
std::vector<StudentAC> conversieVector(StudentAC* a,int size) 
{
	std::vector <StudentAC> v;
	int i = 0;
	for (; i < size; i++)
	{
		v.push_back(*(a + i));
	}
	return v;
}
