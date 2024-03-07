#include<iostream>
#include"Header.h"

int main()
{
	/*{
	    // problema 1;
		using namespace problema_1;
		List* cap, * coada;
		cititreList(cap, coada);
		inserareInFata(cap, 100, 2);
		inserareInFata(coada, 100, 2);
		stergerePozitie(cap, 2);
		stergerePozitie(coada, 2);
		afisareDusIntors(cap);
		afisareDusIntors(coada);
		stergerePozitie(cap, 0);
		stergerePozitie(coada, 0);
		afisareDusIntors(cap);
		afisareDusIntors(coada);
		delete cap;
		delete coada;
	}*/
	/* {
		// problema 2;
		using namespace problema_2;
		List* cap1, * coada1;
		cititreList(cap1, coada1);
		List* cap2, * coada2;
		cititreList(cap2, coada2);
		afisareDusIntors(cap1);
		afisareDusIntors(cap2);
		/*
		List* Z1 = lipire(cap1, cap2);
		List* Z2 = lipire(cap1, coada2);
		List* Z3 = lipire(coada1, cap2);
		List* Z4 = lipire(coada1, coada2);
		std::cout << std::endl;
		afisareDusIntors(Z1);
		std::cout << std::endl;
		afisareDusIntors(Z2);
		std::cout << std::endl;
		afisareDusIntors(Z3);
		std::cout << std::endl;
		afisareDusIntors(Z4);
		std::cout << std::endl;
		afisareDusIntors(cap1);
		afisareDusIntors(cap2);


		List* W = interclasare(cap1, cap2);
		afisareDusIntors(W);


		delete cap1;
		delete cap2;
		delete coada1;
		delete coada2;
		delete W;
		//delete Z1;
		//delete Z2;
		//delete Z3;
		//delete Z4;
	}*/
	{
		using namespace problema_3;

		List* A = inserareInFata();
		afisare(A);
		delete A;
	}
}