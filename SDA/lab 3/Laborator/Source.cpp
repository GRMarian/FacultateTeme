#include<iostream>
#include<fstream>
#include"Header.h"

int main()
{
	Lista* a = citire_my_list();
	Lista* el = new Lista{ 4,NULL };
	afisare_my_list(a);
	if (cautare_lista(a, 2))
	{
		std::cout << "\n fond it !!";
	}
	inserare(a, 3, el);
	afisare_my_list(a);
	system("pause");
	return 0;
}