#include<iostream>
#include"Figura.h"
#include"Cerc.h"
#include"Patrat.h"
#include<vector>

using std::cout;
using std::vector;

int main()
{
	Patrat a("portocaliu", 5, 4, 1.0);
	Patrat d("verde", 6, 7, 7.0);
	Cerc b("albastru",0, 2, 12);
	Cerc c("negru", 3, 3, 2);

	vector<Figura*> vec;
	vector<Figura*>::iterator iter;

	vec.push_back(&a);
	vec.push_back(&b);
	vec.push_back(&c);
	vec.push_back(&d);

	for (iter=vec.begin(); iter<vec.end();iter++)
	{
		(*iter)->Afisare();
	}

	vector<Figura*>::iterator maxPerimetru = vec.begin();
	for (iter = vec.begin() + 1; iter < vec.end(); iter++)
	{
		if ((*iter)->Perimetru() > (*maxPerimetru)->Perimetru())
		{
			maxPerimetru = iter;
		}
	}

	cout << "\n Cel mai mare perimetru ->";
	(*maxPerimetru)->Perimetru();

	Patrat* patrat = new Patrat();
}