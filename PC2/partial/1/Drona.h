#pragma once
#include "Jucarie.h"
typedef unsigned int usig;
class Drona :
    public Jucarie
{
private:
    usig nrElice;

public:
    Drona(string s, double d, usig u)
        :Jucarie(s, d), nrElice(u){}
    void Afisare();
    bool operator>(Drona);
    bool operator<(Drona);
};

