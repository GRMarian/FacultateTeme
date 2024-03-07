#include<iostream>
#include"GRUPA.h"

void InitGrupa(Grupa& Grupa)
{
	std::cout << "\n id grupa -> ";
	std::cin >> Grupa.id;
	std::cout << " dimensiune Grupa -> ";
	std::cin >> Grupa.nr;
	Grupa.tab = new Student[Grupa.nr];
	for (int Student_nr = 0;Student_nr < Grupa.nr; Student_nr++)
	{
		InitStudent(Grupa.tab[Student_nr]);
	}
}

void AfisGrupa(Grupa Grupa)
{
	std::cout << "\n id: " << Grupa.id;
	for (int Student_nr = 0;Student_nr < Grupa.nr; Student_nr++)
	{
		AfisStudent(Grupa.tab[Student_nr]);
	}
}

void StergeGrupa(Grupa& Grupa)
{
	for (int Student_nr = 0;Student_nr < Grupa.nr; Student_nr++)
	{
		StergeStudent(Grupa.tab[Student_nr]);
	}
	delete[] Grupa.tab;
	Grupa.tab = NULL;
}

void CautaStudent( char nume[], Grupa Grupa)
{
	for (int Student = 0;Student < Grupa.nr;Student++)
	{
		if (strcmp(Grupa.tab[Student].nume,nume)==0)
		{
			AfisStudent(Grupa.tab[Student]);
			return;
		}
	}
	std::cout << "\n Nu sa gasit nici un student pe nume : " << nume;
}

void MaxMinNota(Grupa Grupa)
{
	int notaMax = Grupa.tab[0].nota;
	int notaMin = notaMax;
	for (int Student = 1;Student < Grupa.nr;Student++)
	{
		if (notaMax < Grupa.tab[Student].nota)
		{
			notaMax = Grupa.tab[Student].nota;
			continue;
		}
		if (notaMin > Grupa.tab[Student].nota)
		{
			notaMin = Grupa.tab[Student].nota;
		}
	}
	std::cout << "\n nota minima : " << notaMin;
	std::cout << "\n nota maxima : " << notaMax;

}
