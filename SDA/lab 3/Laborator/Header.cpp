#include<iostream>
#include "Header.h"

Lista* citire_my_list()
{
	int element;
	Lista *myLista = NULL;
	std::cin >> element;
	while (element!=0)
	{
		Lista* New = new Lista;
		New->legatura = myLista;
		myLista = New;
		New->element = element;
		std::cin >> element;
	}
	return myLista;
}

void afisare_my_list(Lista* myList)
{
	std::cout << std::endl;
	while (myList != NULL)
	{
			std::cout << myList->element << " ";
			myList = myList->legatura;
	}
}

bool cautare_lista(Lista* myLista,int element)
{

	while (myLista != NULL)
	{
		if (element == myLista->element)
		{
			return true;
		}
		myLista = myLista->legatura;
	}
	return false;
}

void inserare(Lista *& myLista, int pozitie, Lista* newLista)
{
	Lista * MyLista = myLista;
	while (pozitie>=1)
	{
		pozitie--;
		MyLista = MyLista->legatura;
	}
	newLista->legatura = MyLista->legatura;
	MyLista->legatura = newLista->legatura;
}

