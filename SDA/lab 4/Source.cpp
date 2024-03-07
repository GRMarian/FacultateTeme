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
	/* {
		using namespace problema_3;

		List* A = inserareInFata();
		afisare(A);
		delete A;
	}*/
	/*{
		using namespace problema_6;
		
		string a= "999999999999";
		string b = "999999999999";
		//std::cin >> a;
		//std::cin >> b;
		Nr* x = nullptr;
		Nr* k = nullptr;
		
		initializare(x, a);
		initializare(k, b);
		afisare(x);
		afisare(k);
		//bool y = compBigNr(x, k);
		//std::cout << std::endl<<y;

		//deleteCap(k);
		//deleteCap(k);
		//deleteCap(k);
		//deleteCap(k);
		//afisare(k);

		Nr* sum = Suma2BigNr(x, k);
		afisare(sum);
	}*/

	{
			using namespace problema_5;

			Nr* a = citire();
			Nr* b = citire();
			//Nr* c = unire(a, b);
			Nr* d = inter(a, b);
			afisare(a);
			afisare(b);
			//afisare(c);
			std::cout << std::endl;
			afisare(d);
	}
}