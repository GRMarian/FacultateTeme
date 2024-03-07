#include <iostream>
#include "Header.h"
using namespace problema_1;
List* problema_1::subpunct_A()
{
	int element;
	List* myList = NULL;
	std::cin >> element;
	while (element != 0)
	{
		List* New = new List;
		New->legatura = myList;
		myList = New;
		New->element = element;
		std::cin >> element;
	}
	return myList;
}

void problema_1::subpunct_B(List* myList)
{
	std::cout << std::endl;
	while (myList != NULL)
	{
		std::cout << myList->element << " ";
		myList = myList->legatura;
	}
}

bool problema_1::subpunct_C(List* myList, int element)
{
	while (myList != NULL)
	{
		if (element == myList->element)
		{
			return true;
		}
		myList = myList->legatura;
	}
	return false;
}

void problema_1::subpunct_D(List*& myList, int pozitie, int newElement)
{
	List* newElementList = new List{};
	newElementList->element = newElement;

	if (pozitie == 0)
	{
		newElementList->legatura = myList;
		myList = newElementList;
		return;
	}

	List* searchList = myList;
	while (pozitie > 1 && searchList->legatura != NULL)
	{
		pozitie--;
		searchList = searchList->legatura;
	}
	newElementList->legatura = searchList->legatura;
	searchList->legatura = newElementList;
}

void problema_1::subpunct_E(List*& myList, int pozitie)
{
	if (pozitie == 0)
	{
		List* toDelete = myList;
		myList = myList->legatura;
		delete toDelete;
		return;
	}
	List* searchList = myList;
	while (pozitie > 1 && searchList->legatura != NULL)
	{
		pozitie--;
		searchList = searchList->legatura;
	}
	if (searchList->legatura != NULL)
	{
		List* toDelete = searchList->legatura;
		searchList->legatura = searchList->legatura->legatura;
		delete toDelete;
	}
}

void subpunct_F_recursiv(List* myList, int& pozitie)
{
	if (myList->legatura != NULL)
	{
		myList = myList->legatura;
		subpunct_F_recursiv(myList, pozitie);
		if (myList->legatura == NULL)
		{
			return;
		}
	}
	if (pozitie == 0)
	{
		std::cout << std::endl << myList->element;
		pozitie--;
	}
	pozitie--;
}

void problema_1::subpunct_F(List* myList, int& pozitie)
{
	subpunct_F_recursiv(myList, pozitie);
	if (pozitie == 0)
	{
		std::cout << myList->element;
		return;
	}
	if(pozitie>0)
	{
		std::cout << " nu a fost gasit ";
	}
}


void  problema_1::subpunct_G(List*myList)
{
	int n = 0;
	List* uzeList = myList;
	std::cout << std::endl;
	while (uzeList != NULL)
	{
		std::cout << uzeList->element << " ";
		uzeList = uzeList->legatura;
		n++;
	}
	int i = n;
	while (n > 0)
	{
		uzeList = myList;
		while (i > 1)
		{
			uzeList = uzeList->legatura;
			i--;
		}
		std::cout << uzeList->element << " ";
		n--;
		i = n;
	}
}

void problema_1::subpunct_H(List* myList)
{
	if (myList == NULL)
	{
		return;
	}
	List* mijlocList = myList;
	while (myList != NULL)
	{	
		myList = myList->legatura;
			
		if (myList != NULL)
		{
			myList = myList->legatura;

			if (myList != NULL)
			{
				mijlocList = mijlocList->legatura;
			}
		}
	}
	std::cout << std::endl << mijlocList->element;
}

List* problema_1::subpunct_I(List* myList)
{
	if (myList == NULL || myList->legatura == NULL) {
		return myList;
	}
	List* back = NULL;
	List* front = NULL;
	while (myList != NULL) {
		front = myList->legatura;
		myList->legatura = back;
		back = myList;
		myList = front;
	}
	return back;
}

problema_2::List* problema_2::interclasare(List* X, List* Y)
{
	if (X == NULL)
	{
		return Y;
	}
	if(Y == NULL)
	{ 
		return X;
	}
	List* Z = new List;
	List* Z_f = Z;
	while (!(X == NULL && Y == NULL))
	{
		if (X != NULL)
		{
			Z_f->legatura = new List{ X->element,NULL };
			Z_f = Z_f->legatura;
			X = X->legatura;
		}
		if (Y != NULL)
		{
			Z_f->legatura = new List { Y->element,NULL };
			Z_f = Z_f->legatura;
			Y = Y->legatura;
		}
	}
	//Z_f = NULL;
	return Z->legatura;
}

problema_2::List* problema_2::lipire(List* X, List* Y)
{
	if (X == NULL)
	{
		return Y;
	}
	List* iter = X;
	while (iter->legatura != NULL)
	{
		iter = iter->legatura;
	}
	iter->legatura = Y;
	return X;
}

problema_3::Agenda* problema_3::initAgenda()
{
	std::fstream F("in.txt");
	Agenda* myAgenda = NULL;
	string nume, telefon;
	while (F >> nume && F >> telefon)
	{
		Agenda* newElement = new Agenda{ nume,telefon, myAgenda };
		myAgenda = newElement;
	}
	return myAgenda;
}

void problema_3::addElement(Agenda*& myAgenda_, Agenda* Persoana)
{
	if (myAgenda_->nume >= Persoana->nume)
	{
		Persoana->next = myAgenda_;
		myAgenda_ = Persoana;
		return;
	}
	Agenda* myAgenda = myAgenda_;
	while (myAgenda->next != NULL)
	{
		if (myAgenda->next->nume > Persoana->nume)
		{
			Persoana->next = myAgenda->next;
			myAgenda->next = Persoana;
			return;
		}
		myAgenda = myAgenda->next;
	}
	Persoana->next = NULL;
	myAgenda->next = Persoana;
}

void problema_3::deleteElement(Agenda*& myAgenda_, string nume)
{
	if (myAgenda_ == NULL)
	{
		return;
	}
	Agenda* myAgenda = myAgenda_;
	if (myAgenda->nume == nume)
	{
		myAgenda_ = myAgenda_->next;
		delete myAgenda;
		return;
	}
	Agenda* curent = myAgenda->next;
	while (curent != NULL)
	{
		if (curent->nume == nume)
		{
			myAgenda->next = curent->next;
			delete curent;
			break;
		}
		myAgenda = myAgenda->next;
		curent = curent->next;
	}
}

problema_3::Agenda problema_3::cautaNumar(Agenda* myAgenda, string numar)
{
	if (myAgenda == NULL)
	{
		return Agenda{ "","",NULL };
	}
	if (myAgenda->numar == numar)
	{
		return Agenda{ myAgenda->nume,myAgenda->numar,NULL };
	}
	while (myAgenda != NULL)
	{
		if (myAgenda->numar == numar)
		{
			return Agenda{ myAgenda->nume,myAgenda->numar,NULL };
		}
		myAgenda = myAgenda->next;
	}
}
void problema_3::afisareAgenda(Agenda* myAgenda)
{
	std::cout << std::endl;
	while (myAgenda != NULL)
	{
		std::cout << myAgenda->nume << " " << myAgenda->numar << std::endl;
		myAgenda = myAgenda->next;
	}
}

