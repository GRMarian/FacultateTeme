#pragma once
#include<string>
#include<vector>

using std::string;

class StudentAC
{
	string nume;
	int nota;
public:

	StudentAC() :nume(" "), nota(0) {};
	StudentAC(string nume, int nota) :nume(nume), nota(nota) {};
	void afisare();
	void modificareNota(int nouaNota);
	bool operator<(StudentAC);
};

void afisare(std::vector<StudentAC>);
std::vector<StudentAC> conversieVector(StudentAC*,int);