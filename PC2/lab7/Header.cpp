#include "Header.h"
#include<string>

int numarUpperCase(std::string sir)
{
	std::string::iterator iter;
	int sum = 0;
	for (iter = sir.begin(); iter != sir.end(); iter++)
	{
		if ((*iter >= 'A') && (*iter <='Z'))
		{
			sum = sum + 1;
		}
	}
	return sum;
}
int numarCifre(std::string sir)
{
	std::string::iterator iter;
	int sum = 0;
	for (iter = sir.begin(); iter != sir.end(); iter++)
	{
		if ((*iter >= '0') && (*iter <='9'))
		{
			sum = sum + 1;
		}
	}
	return sum;
}