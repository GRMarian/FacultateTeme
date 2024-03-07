#include<iostream>
#include<vector>
#include<algorithm>
#include"Triunghi.h"
#include"Dreptunghi.h"
#include"Cerc.h"

using std::vector;

int main()
{
	Figura* T1 = new Triunghi({ 1, 2 }, { 2 ,3 }, { 4 ,5 });
	Figura* T2 = new Triunghi({ 3, 3 }, { 10 ,10 }, { 1 ,1 });
	Figura* C1 = new Cerc(3, 2, 4);
	Figura* D1 = new Dreptunghi(2, 2, 4, 4);

	vector<Figura*> vec;
	
	vec.push_back(T1);
	vec.push_back(T2);
	vec.push_back(C1);
	vec.push_back(D1);

	vector<Figura*>::iterator iter;

	std::sort(vec.begin(), vec.end());

	for (iter = vec.begin(); iter < vec.end(); iter++)
	{
		(*iter)->afisare();
	}

	Figura* T3 = new Triunghi({1, 0 }, { 10, 0 }, {10 ,1 });
	Triunghi* t = dynamic_cast<Triunghi*>(T3);
	if (t != NULL)
	{
		std::cout << "\n\n semiperimetru " << t->semiPerimetru();
	}
	return 0;
}