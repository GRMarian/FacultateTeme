#pragma once

#include<iostream>
#include<fstream>

namespace problema_1 {

	struct List {
		int numar;
		List* prev;
		List* next;
	};

	void cititreList(List*&, List*&);
	void afisareDusIntors(List*);
	void inserareInFata(List*&,int,int);
	void stergerePozitie(List*&, int);
}

namespace problema_2
{
	using namespace problema_1;
	List* interclasare(List*, List*);
	List* lipire(List*, List*);//doar caz  cap-cap
}

namespace problema_3
{
	struct List {
		int numar;
		List* next;
	};

	List* inserareInFata();
	void afisare(List*);
	void inversareAdr(List*&);
}