
#include <iostream>
#include <fstream>
#include <random>
#include "Header.h"
#include "mult_scris.h"

int main()
{
	std::ifstream intrare_txt("vector.txt");
	std::ofstream iesire_txt("afisare.txt");

	// primul exercitiu //
	/* 
	int valoare;
	int iter_dimensiune_vector = 0;

	int max = 10;
	int* vector = new int[max];

	while(iter_dimensiune_vector<max)
	{
		intrare_txt >> vector[iter_dimensiune_vector];
		iter_dimensiune_vector++;
	}
	std::cout << problema_1(vector, iter_dimensiune_vector);
	*/

	// al doilea exercitiu
	/*
	int linie, coloana;
	intrare_txt >> linie;
	intrare_txt >> coloana;
	int* vector = new int[linie * coloana];

	for (int i = 0;i < linie;i++)
		for (int j = 0;j < coloana;j++)
			intrare_txt >> vector[linie*i+j];

	problema_2::afisareMatrice(vector, linie, coloana);
	problema_2::afisareValoare(vector, 2, 2,linie);
	int* coordonate = problema_2::valoareMax(vector, linie, coloana);
	std::cout << std::endl << coordonate[0] << " " << coordonate[1];
	delete[] coordonate;
	delete[] vector;
	*/

	/*
	int linie, coloana;
	intrare_txt >> linie;
	intrare_txt >> coloana;
	int** vector = new int*[linie];

	for (int i = 0;i < linie;i++)
		vector[i] = new int[coloana];

	for (int i = 0;i < linie;i++)
		for (int j = 0;j < coloana;j++)
			intrare_txt >> vector[i][j];
	int count = 0;
	int* coordonate = problema_3(vector, linie, coloana, 2 ,count);

	std::cout << std::endl << coordonate[0] << " " << coordonate[1];
	std::cout << std::endl << " nr count --> " << count;
	for (int i = 0;i < linie;i++)
		delete[] vector[i];
	delete[] vector;
	*/

	for (int i = 1; i <= 20; i++)
	{
		int Dimensiune_Vector = 1000 * i;
		int* vector = new int[Dimensiune_Vector];

		std::random_device random_device;
		std::mt19937 generatie(random_device());
		std::uniform_int_distribution<> distributie(1, 10 * Dimensiune_Vector);

		for (int iter = 0; iter < Dimensiune_Vector; iter++)
		{
			vector[iter] = distributie(generatie);
		}

		my_mult_scris::InsertionSort_timp(vector, Dimensiune_Vector);

		delete[]vector;
	}

	intrare_txt.close();
	iesire_txt.close();
}

