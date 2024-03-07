
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "Header.h"
#include "StudentAC.h"

using std::cout;
using std::cin;

int main()
{
    /*
    std::string sir;
    std::cout << "sir -> ";
    std::cin >> sir;
    std::cout << numarUpperCase(sir) << std::endl << numarCifre(sir);
    */
    /*
    std::vector<StudentAC> v;
    string nume;
    int nota;
    for (int i = 0; i < 3; i++) {
        cout << " nume : ";
        cin >> nume;
        cout << " nota : ";
        cin >> nota;
        StudentAC*x = new StudentAC(nume, nota);
        v.push_back(*x);
        delete x;
    }
    cout << "\n\n";
    afisare(v);
    */
    
    
    StudentAC* a = new StudentAC[3];
    string nume;
    int nota;
    int dim;
    cout << "dim -> ";
    cin >> dim;
    for (int i = 0; i < dim; i++) 
    {
        cout << " nume : ";
        cin >> nume;
        cout << " nota : ";
        cin >> nota;
        a[i] = StudentAC(nume, nota);
    }
    std::vector<StudentAC> v;
    v = conversieVector(a,dim);
    for (int i = 0; i < 3; i++) {
        v[i].afisare();
    }
    std::sort( v.begin(), v.end());
    cout << std::endl;
    for (int i = 0; i < 3; i++) {
        v[i].afisare();
    }
    delete[] a;
}

