#include<iostream>
#include"STUDENT.h"

#define dimensiune_nume 30

void InitStudent(Student& Student)
{
	Student.nume = new char[dimensiune_nume];
	std::cout << "\n nume -> ";
	std::cin >> Student.nume;
	std::cout << " nota -> ";
	std::cin >> Student.nota;
}

void AfisStudent(Student Student)
{
	std::cout << "\n nume : " << Student.nume;
	std::cout << "\n nota : " << Student.nota;
}

void StergeStudent(Student& Student)
{
	delete[] Student.nume;
	Student.nume = NULL;
}