#include "Triunghi.h"
#include <iostream>
#include <math.h>
double Triunghi::distantaDintre(punct A, punct B)
{
    double rezultat;
    rezultat = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
    return rezultat;
}
double Triunghi::semiPerimetru()
{
    double rezultat = 0;
    rezultat += this->distantaDintre(P[0], P[1]);
    rezultat += this->distantaDintre(P[1], P[2]);
    rezultat += this->distantaDintre(P[2], P[0]);
    return rezultat / 2;
}

double Triunghi::perimetru()
{
    return this->semiPerimetru() * 2;
}

double Triunghi::arie()
{
    punct mijloc{ (P[0].x + P[1].x) / 2 , (P[0].y + P[1].y) / 2 };
    double inaltime = distantaDintre(P[2], mijloc);
    double baza = distantaDintre(P[0], P[1]);
    return (inaltime * baza) / 2;

    /*double p = semiPerimetru();
    double a = this->distantaDintre(P[0], P[1]);
    double b = this->distantaDintre(P[1], P[2]);
    double c = this->distantaDintre(P[2], P[0]);
    return  sqrt(p * (p - a) * (p - b) * (p - c));*/
}
void Triunghi::afisare()
{
    std::cout << "Triunghi cu coordonatele ("
        << P[0].x << "," << P[0].y << ")-("
        << P[1].x << "," << P[1].y << ")-("
        << P[2].x << "," << P[2].y << "),"
        << "\naria " << arie()
        << "\nperimetru " << perimetru()
        << std::endl;
}

