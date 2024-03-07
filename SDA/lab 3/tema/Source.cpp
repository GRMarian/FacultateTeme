#include<iostream>
#include"Header.h"

int main()
{
	{
		using namespace problema_1;
		//List* myList = subpunct_A();
		//subpunct_B(myList);
		//if (subpunct_C(myList, 2)){std::cout << "\n gasit ";}
		//subpunct_D(myList,3 , 100);
		//subpunct_B(myList);
		//subpunct_E(myList, 3);
		//subpunct_E(myList, 0);
		//subpunct_B(myList);
		//int k; std::cin >> k;
		//subpunct_F(myList, k);
		//subpunct_H(myList);
		//myList=subpunct_I(myList);
		//subpunct_B(myList);
		//subpunct_G(myList);
		//delete myList;
	}
	{
		using namespace problema_2;
		List* X = subpunct_A();
		List* Y = subpunct_A();
		//List* Z = lipire(X, Y);
		List* W = interclasare(X, Y);
		subpunct_B(X);
		subpunct_B(Y);
		//subpunct_B(Z);
		subpunct_B(W);
		delete X;
		delete Y;
		//delete Z;
		delete W;
	}
	/* {
		using namespace problema_3;

		Agenda* myAgenda = initAgenda();
		afisareAgenda(myAgenda);
		addElement(myAgenda, new Agenda{ "satan","07666",NULL });
		addElement(myAgenda, new Agenda{ "aatan","07324",NULL });
		addElement(myAgenda, new Agenda{ "batan","07111",NULL });
		afisareAgenda(myAgenda);
		Agenda satan = cautaNumar(myAgenda, "07666");
		Agenda aatan = cautaNumar(myAgenda, "07324");
		Agenda batan = cautaNumar(myAgenda, "07111");
		deleteElement(myAgenda, "satan");
		deleteElement(myAgenda, "aatan");
		deleteElement(myAgenda, "batan");
		afisareAgenda(myAgenda);
		std::cout << "\n nume : " << satan.nume << "   numar : " << satan.numar;
		std::cout << "\n nume : " << aatan.nume << "   numar : " << aatan.numar;
		std::cout << "\n nume : " << batan.nume << "   numar : " << batan.numar;
		//delete myAgenda;
	}*/

	return 0;
}