#include "Patrat.h"
#include <iostream>
Patrat::~Patrat()
{
}

void Patrat::Afisare()
{
    std::cout << "\n\n Patrat";
    Figura::Afisare();
    std::cout << "\n coordonate X0Y -> [" << this->X << "][" << this->Y << "]";
    std::cout << "\n perimetru -> "<<this->Perimetru();
}

double Patrat::Perimetru()
{
    return 4*this->lungime;
}
