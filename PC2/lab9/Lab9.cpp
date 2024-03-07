
#include <iostream>
#include <string>

#include "StudentAC.h"
#include "PersoanaAC.h"
#include "StudentMaster.h"
#include "Profesor.h"
#include "Angajat.h"
#include "Persoana.h"
#include "vector"

void meniu_1();
void meniu_2();
void meniu_3();
void meniu_4();
void meniu_string();

int main()
{
    int n;
    do
    {
        std::cout << "\nn = ";
        std::cin >> n;
        system("cls");
        switch (n) {
        case 1:meniu_1(); break;
        case 2:meniu_2(); break;
        case 3:meniu_3(); break;
        case 4:meniu_4(); break;
        default: meniu_string(); break;
        }
    } while (n != 0);
}

void meniu_1() {
    std::cout << "\n---------------------------";
    PersoanaAC p1("1234567890123", "Ana", "Iasi");
    p1.afisareProfil();
    std::cout << "\n---------------------------";
    StudentAC s2;
    s2.afisareProfil();
    std::cout << "\n---------------------------";
    StudentAC s1("1234567890122", "Ion", "Vaslui", 2, 10);
    s1.schimbareAdresa("Bucuresti");
    s1.inscriereAnStudiu(3);
    s1.afisareProfil();
    std::cout << "\n---------------------------\n";
    std::cout << std::endl;
}

void meniu_2() 
{
    Profesor p1("Ion", 23, 100.08, 1);
    std::cout << "\n varsta  : " << p1.getVarsta();
    std::cout << "\n salariu : " << p1.getSalariu();
    std::cout << "\n grad    : " << p1.getGradDidactic();
}

void meniu_3()
{
    StudentAC s1("1234567890122", "Ion", "Vaslui", 2, 10);
    afisareProfil(s1);
    std::cout << std::endl;
}
void meniu_4()
{
    StudentMaster m1("diz1", "1234567890122", "Ion", "Vaslui", 2, 1);
    StudentMaster m2("diz2", "7777777777777", "Mirel", "Constanta", 3, 3);
    StudentMaster m3("diz3", "1231231321321", "Mihai", "Brasov", 1, 7);
    StudentMaster m4("diz4", "4444444444444", "Marian", "iasi", 3, 6);
    StudentMaster m5("diz5", "1574477766000", "Mincu", "Bucuresti", 2, 2);
    std::vector<StudentMaster> vSM;
    vSM.push_back(m1);
    vSM.push_back(m2);
    vSM.push_back(m3);
    vSM.push_back(m4);
    vSM.push_back(m5);
    std::vector<StudentMaster>::iterator i;
    std::cout << "\n---------------------------";
    for (i = vSM.begin(); i < vSM.end(); i++)
    {
        i->afisareProfil();
        std::cout << "\n---------------------------";
    }
    std::cout << std::endl;
    std::vector<StudentMaster>::iterator rez = vSM.begin();
    for (i = vSM.begin() + 1; i < vSM.end(); i++)
    {
        StudentAC aux_rez = *rez;
        StudentAC aux_i = *i;
        if (aux_i > aux_rez)
        {
            rez = i;
        }
    }
    std::cout << "\n---------------------------";
    std::cout << "\n--------REZULTAT-----------";
    std::cout << "\n---------------------------";
    rez->afisareProfil();
    std::cout << "\n---------------------------\n";
    std::cout << std::endl;
}

void meniu_string()
{
    std::string s1("Ana are mere");

    std::string s2(s1);
    std::string s3(s1, 8, 4);
    std::string s4("Sir");
    std::string s5("Sir de 10 caracter", 10);
    std::string s6(10, 'K');
    std::string s7(s1.begin(), s1.begin() + 7);

    std::cout << "\ns2: " << s2;
    std::cout << "\ns3: " << s3;
    std::cout << "\ns4: " << s4;
    std::cout << "\ns5: " << s5;
    std::cout << "\ns6: " << s6;
    std::cout << "\ns7: " << s7;

}

