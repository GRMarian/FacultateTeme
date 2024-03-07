#include<iostream>
#include"Header.h"
#include<random>

//#define Dimensiune_Vector  400

int main()
{
	for (int i = 1; i <= 20; i++)
	{
		int Dimensiune_Vector = 500 * i;
		int*vector = new int[Dimensiune_Vector];

		std::random_device random_device;
		std::mt19937 generatie(random_device());
		std::uniform_int_distribution<> distributie(1, 10 * Dimensiune_Vector);

		for (int iter = 0; iter < Dimensiune_Vector; iter++)
		{
			vector[iter] = distributie(generatie);
		}

		//std::cout << "\n conter : " << InsertionSort(vector, Dimensiune_Vector);
		selSort(vector, Dimensiune_Vector);
		delete[]vector;
	}
}
