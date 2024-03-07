#pragma once

#include<iostream>
#include<fstream>
#include<string>

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

namespace problema_6
{
	using std::string;
	struct Nr {
		int nr;
		Nr* prev;
		Nr* next;
	};
	int element(string& big_nr);
	void initializare(Nr*& cap,string big_nr);
	void addNewCap(Nr*& cap);
	void deleteCap(Nr*& cap);
	bool compBigNr(Nr* cap1, Nr* cap2);
	int adunare(Nr*& cap1, Nr*& cap2, Nr*& cap3);
	Nr* Suma2BigNr(Nr* cap1, Nr* cap2);
	void afisare(Nr* cap);
}

namespace problema_5
{
	struct Nr {
		int e;
		Nr* next;
	};
	Nr* citire();
	void afisare(Nr*);
	Nr* unire(Nr*, Nr*);
	Nr* inter(Nr*&, Nr*&);
}

