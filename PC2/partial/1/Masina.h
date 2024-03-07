#pragma once
#include "Jucarie.h"


typedef unsigned int usig;
class Masina : public Jucarie
{
private:
    usig nrBterii;

public:
    Masina() :nrBterii(0), Jucarie(){}
    Masina(string s, double d, usig u)
        :Jucarie(s, d), nrBterii(u){}
    ~Masina();
    void Afisare();
    bool operator==(Masina);

};

