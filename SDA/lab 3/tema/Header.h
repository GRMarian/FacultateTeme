#pragma once
#include <string>
#include <fstream>
namespace problema_1
{
	struct List
	{
		int element;
		List* legatura;
	};
	List* subpunct_A();
	void  subpunct_B(List*);
	bool  subpunct_C(List*,int);
	void  subpunct_D(List*&,int,int);
	void  subpunct_E(List*&,int);
	void  subpunct_F(List*,int&);
	void  subpunct_G(List*);
	void  subpunct_H(List*);
	List*  subpunct_I(List*);
}

namespace problema_2
{;
	using namespace problema_1;
	List* interclasare(List*, List*);
	List* lipire(List*, List*);
}

namespace problema_3 {

	using std::string;

	struct Agenda {
		string nume;
		string numar;
		Agenda* next;
	};

	Agenda* initAgenda();
	void addElement(Agenda*&,Agenda*);
	void deleteElement(Agenda*&, string);
	Agenda cautaNumar(Agenda*, string);
	void afisareAgenda(Agenda*);
}