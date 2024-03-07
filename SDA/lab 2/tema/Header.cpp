#include <iostream>
#include "Header.h"

int problema_1(int* vector,int dimensiune_vector)
{
    int Suma_max=vector[0];
    int Suna_sectiune;
    for (int inceput_sectiune = 0; inceput_sectiune < dimensiune_vector; inceput_sectiune++)
    {
        Suna_sectiune = 0;
        for (int sfarsit_sectiune = inceput_sectiune; sfarsit_sectiune < dimensiune_vector;sfarsit_sectiune++) 
        {
            Suna_sectiune += vector[sfarsit_sectiune];
            if (Suma_max < Suna_sectiune)
            {
                Suma_max = Suna_sectiune;
            }
        }
    }
    return Suma_max;
}

int* problema_3(int** vector, int linie, int coloana, int x, int& count)
{
    int* coordonate = new int[2] {0};//+3 cred
    int l = 0, c = coloana-1;
    count += 6;
    if (x == vector[l][c])//+3
    {
        return coordonate;
    }
    for(l=0;l<linie;l++)// linie ori
    {
        count += 3;
        if (x < vector[l][c])//+3
        {
            break;
        }
    }
    count++;
    for (;c > 0;c--)// coloana ori 
    {
        count += 3;
        if (x > vector[l][c])//+3 
        {
            count += 2;
            c++;//+1
            l++;//+1
            continue;
        }
        count += 3;
        if (x == vector[l][c])//+3
        {
            break;
        }
    }
    coordonate[0] = l;//+2
    coordonate[1] = c;//+2
    count += 4;
    return coordonate;
}



void problema_2::afisareValoare(int* vector, int linie, int coloana, int dimensiune_linie)
{
    std::cout << vector[linie* dimensiune_linie +coloana];
}

void problema_2::afisareMatrice(int* vector, int dimensiune_linie, int dimensiune_coloana)
{
    std::cout << std::endl;
    for (int linie = 0; linie < dimensiune_linie;linie++)
    {
        for (int coloana = 0; coloana < dimensiune_coloana; coloana++)
        {
            std::cout << vector[linie* dimensiune_linie +coloana];
        }
        std::cout << std::endl;
    }
}

int* problema_2::valoareMax(int* vector, int dimensiune_linie, int dimensiune_coloana)
{
    int max = vector[0];
    int* coordonate_max = new int[2];
    for (int linie = 0; linie < dimensiune_linie;linie++)
    {
        for (int coloana = 0; coloana < dimensiune_coloana; coloana++)
        {
            if (max < vector[linie*dimensiune_linie+coloana])
            {
                max = vector[linie * dimensiune_linie + coloana];
                coordonate_max[0] = linie;
                coordonate_max[1] = coloana;
            }
        }
    }
    return coordonate_max;
}
