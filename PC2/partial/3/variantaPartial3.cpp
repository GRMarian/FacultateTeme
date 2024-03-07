
#include <iostream>
#include "Gadget.h"
#include "SmartPhone.h"
#include "SmartWatch.h"
#include<vector>
#include<algorithm>
using std::vector;
int main()
{
	Gadget a;
	Gadget b("b", 7.4);
	SmartPhone c;
	SmartPhone d("d", 12, 43);

	a.Afisare();
	b.Afisare();
	c.Afisare();
	d.Afisare();

	if (!(c == d))
	{
		std::cout << "\n\n merge \n\n";
	}

	a.setPret(46.579);
	a.Afisare();

	SmartWatch w1("1", 7, 6);
	SmartWatch w2("2", 1, 2);
	SmartWatch w3("3", 8, 5);
	SmartWatch w4("4", 3, 1);
	vector<SmartWatch> vec;
	 
	vec.push_back(w1);
	vec.push_back(w2);
	vec.push_back(w3);
	vec.push_back(w4);

	vector<SmartWatch>::iterator iter;
	
	for (iter = vec.begin(); iter < vec.end(); iter++)
	{
		iter->Afisare();
	}

	std::sort(vec.begin(), vec.end());

	for (iter = vec.begin(); iter < vec.end(); iter++)
	{
		iter->Afisare();
	}

	std::cout << "\n\n contor " << SmartWatch::contor << " sau " << w1.getContor() << "\n\n";
}
	

