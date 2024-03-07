#include<iostream>
#include"Persoana.h"
#include"Profesor.h"
#include"Student.h"

int main()
{
	Persoana p1("Ion", "str. Libertatii");
	//Persoana p2("Andrei", "str. Calea Victoriei");
	Student s1("Mihai", "str. Cuza Voda", 2, 5);
	Student s2("Petru", "str. Stefan cel mare", 2, 3);
	Student s3("Mirel", "str. Stefan cel mare", 2, 1);
	Student s4("Alex", "str. Stefan cel mare", 2, 7);
	/*p1.afisareProfil();
	p2.afisareProfil();
	s1.afisareProfil();
	s2.afisareProfil();*/

	std::vector<Student> S;
	S.push_back(s1);
	S.push_back(s2);
	S.push_back(s3);
	S.push_back(s4);

	Profesor p(S, "C++", p1);
	p.afisareStudenti();
	p.sortDescrescator();
	std::cout << std::endl;
	p.afisareStudenti();
	
	return 0;
}