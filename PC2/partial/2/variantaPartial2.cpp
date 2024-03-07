
#include <iostream>
#include "Electrocasnic.h"
#include "Frigider.h"
#include "Aspirator.h"
#include <vector>
#include <algorithm>

using std::vector;

template<class T> bool maiMarePret(T a, T b)
{
    if (a > b)
    {
        return true;
    }
    return false;
}

int main()
{
    Electrocasnic a;
    Electrocasnic b("hey", 5.6);
    Frigider c;
    Frigider d("wow", 1.3f, 3);

    a.Afisare();
    b.Afisare();
    c.Afisare();
    d.Afisare();

    c++;

    c.Afisare();

    c.setPret(200);

    c.Afisare();

    vector<Aspirator> vec;

    Aspirator e(4, "e", 4);
    Aspirator f(1, "f", 0);
    Aspirator g(9, "g", 2);
    Aspirator h(7, "h", 7);

    vec.push_back(e);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(h);

    vector<Aspirator>::iterator iter = vec.begin();
    for (; iter < vec.end(); iter++) {
        iter->Afisare();
    }

    std::sort(vec.begin(), vec.end(), Aspirator::criteriuVolum);

    vector<Aspirator>::iterator max = vec.begin();
    for (iter = vec.begin(); iter < vec.end(); iter++) {
        iter->Afisare();
        if (*iter > *max)
        {
            max = iter;
        }
    }

    std::cout << "\n\n cel mai mare Aspirator\n";
    max->Afisare();
}

