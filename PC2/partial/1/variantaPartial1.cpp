
#include <iostream>
#include "Jucarie.h"
#include "Masina.h"
#include "Drona.h"
#include<vector>
#include<algorithm>
using std::vector;

template<class T> bool maiMare(T, T);

int main()
{
    Jucarie a;
    Jucarie b("b", 4);
    Masina c;
    Masina d("d", 3,4);
    
    a.Afisare();
    b.Afisare();
    c.Afisare();
    d.Afisare();

    if (!(c == d))
    {
        std::cout << "\n\n merge \n\n";
    }
    c.setCuloare("cul");
    c.Afisare();

    Drona d1("1", 6, 3);
    Drona d2("2", 0, 7);
    Drona d3("3", 3, 0);
    Drona d4("4", 8, 1);

    vector<Drona> vec;

    vec.push_back(d1);
    vec.push_back(d2);
    vec.push_back(d3);
    vec.push_back(d4);

    vector<Drona>::iterator iter = vec.begin();
    vector<Drona>::iterator max = vec.begin();
    for (; iter < vec.end(); iter++)
    {
        iter->Afisare();
    }

    std::sort(vec.begin(), vec.end(), maiMare<Drona>);

    for (iter = vec.begin(); iter < vec.end(); iter++)
    {
        iter->Afisare();
    }

    if (maiMare(d1,d2))
    {
        std::cout << "\n\n merge \n\n";
    }
    else
    {
        std::cout << "\n\n nu merge \n\n";
    }
    
}

template<class T> bool maiMare(T a, T b)
{
    if (a > b)
    {
        return true;
    }
    return false;
}
