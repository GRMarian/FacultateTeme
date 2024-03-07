#pragma once
#include "Jucarie.h"
#include "Roata.h"
#include <vector>
typedef unsigned int usig;
using std::vector;
class Masina :public Jucarie
{
private:
    vector<Roata> roti;
    usig numar_baterii;
public:
    Masina(string nume = "", double dbl = 0.0, usig u = 0):Jucarie(nume, dbl), numar_baterii(u){}
    Masina(Masina* a) :Jucarie(a->nume, a->dbl), numar_baterii(a->numar_baterii){this->roti = a->roti;}
    //merge
    //Masina(Masina& a):Jucarie(a.nume, a.dbl), numar_baterii(a.numar_baterii){this->roti = a.roti;}
    //nu merge
    //Masina(const Masina& a) :Jucarie(a.nume, a.dbl), numar_baterii(a.numar_baterii) { this->roti = a.roti; }
    //nu merge
    void setRoata(usig);
    ~Masina();
    void Afisare();

    bool operator==(Masina);
    bool operator>(Masina);
};

