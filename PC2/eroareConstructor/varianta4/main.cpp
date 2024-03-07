#include<iostream>
#include"Masina.h"
#include<algorithm>


template<class T> bool maiMare(T a, T b)
{
	if (a > b)
	{
		return true;
	}
	return false;
}

int main()
{

	/*Jucarie* a = new Jucarie();
	Jucarie b("b", 3.2);
	Masina* c = new Masina();*/
	Masina d("d", 5.4, 20);

	/*a->Afisare();
	b.Afisare();
	c->Afisare();
	d.Afisare();

	if (!(*c == d))
	{
		std::cout << "\n\nMARGE\n\n";
	}*/

	Masina *e =new Masina("e",34.3,2);
	e->setRoata(7);//asta este cauza erori
	Masina f("f", 6.7, 50);
	Masina g("g", 3.4, 10);

	vector<Masina> masini;

	masini.push_back(d);
	masini.push_back(e);//aici are eroare
	//nu pate sa mute singur obiectul de clasa vector dintro parte in alta
	masini.push_back(f);
	masini.push_back(g);

	std::sort(masini.begin(), masini.end(), maiMare<Masina>);

	vector<Masina>::iterator iter = masini.begin();
	for (; iter < masini.end(); iter++)
	{
		iter->Afisare();
	}
	return 0;
}