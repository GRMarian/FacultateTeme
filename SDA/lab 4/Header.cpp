#include "Header.h"

void problema_1::cititreList(List*& First, List*& Last)
{
    std::ifstream file("in.txt");
    int numar;
    List* newElement;
    if (file >> numar)
    {
        Last = new List{ numar,NULL,NULL };
        First = Last;
    }
    while (file >> numar)
    {
        newElement = new List{ numar, NULL , First };
        
        First->prev = newElement;
        First = newElement;
    }
    file.close();
}

void problema_1::afisareDusIntors(List* myList)
{
    if (myList == NULL)
    {
        return;
    }
    std::cout << std::endl;
    if (myList->prev == NULL)
    {
        while (myList != NULL)
        {
            std::cout << myList->numar << " ";
            myList = myList->next;
        }
    }
    while (myList != NULL)
    {
        std::cout << myList->numar << " ";
        myList = myList->prev;
    }
}

void problema_1::inserareInFata(List*& myList_,int numar,int pozitie)
{
    if (myList_ == NULL)
    {
        myList_ = new List{ numar,NULL,NULL };
    }
    List* myList = myList_;
    if (myList->prev == NULL)
    {
        while (myList != NULL)
        {
            myList = myList->next;
            pozitie--;
            if (pozitie == 0)
            {
                List* newElement = new List{ numar, myList->prev , myList };
                myList->prev->next = newElement;
                myList->prev = newElement;
                return;
            }
        }
        return;
    }
    while (myList != NULL)
    {
   
        myList = myList->prev;
        pozitie--;
        if (pozitie == 0)
        {
            List* newElement = new List{ numar, myList , myList->next };
            myList->next->prev = newElement;
            myList->next = newElement;
            return;
        }
    }
    /*************************************************\
    |*  Note: daca numeri de la 1 la if-uri pui == 1 *|
    \*************************************************/
}

void problema_1::stergerePozitie(List*& myList_, int pozitie)
{
    List* myList = myList_;
    if (pozitie == 0)
    {
        if (myList->prev == NULL)
        {
            myList_ = myList_->next;
            myList_->prev = NULL;
            delete myList;
            return;
        }
        if (myList->next == NULL)
        {
            myList_ = myList_->prev;
            myList_->next = NULL;
            delete myList;
            return;
        }
        return;
    }
    if (myList->prev == NULL)
    {
        while (myList->next != NULL && pozitie!=0)
        {
            myList = myList->next;
            pozitie--;

        }
    }
    else
    {
        while (myList->prev != NULL && pozitie != 0)
        {

            myList = myList->prev;
            pozitie--;
        }
    }
    if (pozitie == 0)
    {
        List* ToDelete = myList;
        myList->prev->next = myList->next;
        myList->next->prev = myList->prev;
        myList = myList->next;
        delete ToDelete;
        return;
    }
}

/*problema_2::List* problema_2::interclasare(List* X, List* Y)
{
    if (X == NULL)
    {
        return Y;
    }
    if (Y == NULL)
    {
        return X;
    }
    List* Z = new List;
    List* Z_f = Z;
    while (!(X == NULL && Y == NULL))
    {
        if (X != NULL)
        {
            Z_f->legatura = new List{ X->element,NULL };
            Z_f = Z_f->legatura;
            X = X->legatura;
        }
        if (Y != NULL)
        {
            Z_f->legatura = new List{ Y->element,NULL };
            Z_f = Z_f->legatura;
            Y = Y->legatura;
        }
    }
    //Z_f = NULL;
    return Z->legatura;
}*/

void lipire_dus(problema_2::List*& myList, problema_2::List* list )
{
    while (list != NULL)
    {
        myList->next = new problema_2::List{ list->numar,myList,NULL };
        myList = myList->next;
        list = list->next;
    }
}
void lipire_intors(problema_2::List*& myList, problema_2::List* list)
{
    while (list != NULL)
    {
        myList->prev = new problema_2::List{ list->numar,NULL ,myList };
        myList = myList->prev;
        list = list->prev;
    }
}
void lipire_intors_dus(problema_2::List*& myList, problema_2::List* list)
{
    while (list != NULL)
    {
        myList->next = new problema_2::List{ list->numar,myList ,NULL };
        myList = myList->next;
        list = list->prev;
    }
}
void lipire_dus_intors(problema_2::List*& myList, problema_2::List* list)
{
    while (list != NULL)
    {
        myList->prev = new problema_2::List{ list->numar,NULL,myList };
        myList = myList->prev;
        list = list->next;
    }
}

problema_2::List* problema_2::lipire(List* X, List* Y)
{
    List* myList = NULL;
    List* iter;
    if (X->next == 0)
    {
        myList= new problema_2::List{ X->numar,NULL ,myList };
        X = X->prev;
        iter = myList;
        lipire_intors(iter, X);
        if (Y->next == 0)
        {
            lipire_intors(iter, Y);
        }
        else
        {
            lipire_dus_intors(iter, Y);
        }
        return myList;
    }
    else
    {
        myList= new problema_2::List{ X->numar,myList,NULL };
        X = X->next;
        iter = myList;
        lipire_dus(iter, X);
        if (Y->next == 0)
        {
            lipire_intors_dus(iter, Y);
        }
        else
        {
            lipire_dus(iter, Y);
        }
        return myList;
    }
    return NULL;
}


problema_2::List* problema_2::interclasare(List* X, List* Y)
{
    if (X == NULL)
    {
        return Y;
    }
    if (Y == NULL)
    {
        return X;
    }
    List* Z = new List;
    List* Z_f = Z;
    while (!(X == NULL && Y == NULL))
    {
        if (X != NULL)
        {
            Z_f->next = new List{ X->numar,Z_f,NULL };
            Z_f = Z_f->next;
            X = X->next;
        }
        if (Y != NULL)
        {
            Z_f->next = new List{ Y->numar,Z_f,NULL };
            Z_f = Z_f->next;
            Y = Y->next;
        }
    }
    Z->next->prev = NULL;
    return Z->next;
}

problema_3::List* problema_3::inserareInFata()
{
    int element;
    std::ifstream file("in.txt");
    List* myList = NULL;
    if (file >> element)
    {
        myList = new List{ element,NULL };
        myList->next = myList;
    }
    while (file >> element)
    {
        List* New = new List{ element,myList };
        myList = New;
    }
    file.close();
    return myList;
}

void problema_3::afisare(List* myList)
{
    List* stop = myList->next;
    std::cout << std::endl;
    if (myList != NULL)
    {
        do {
            std::cout << myList->numar << " ";
            myList = myList->next;
        } while (stop != myList->next);
    }
}


void problema_3::inversareAdr(List*& myList)
{
    if (myList == NULL)
    {
        return;
    }
    List* FIRST = myList;
    List* LAST = myList->next;
    List* intermediar;
    do
    {
        intermediar = LAST->next;
        LAST->next = FIRST;
        FIRST = LAST;
        LAST = intermediar;
    } while (FIRST != myList);
    myList = myList->next;
}

int problema_6::element(string& big_nr)
{
    int smal_nr = 0;
    int dim =(int)big_nr.length();
    for (int iter = 0; iter < 3;iter++)
    {
        smal_nr += (int)((big_nr[dim-iter-1] - '0') * std::pow(10,iter));
        big_nr.pop_back();
        if (big_nr.empty())
        {
            break;
        }
    }
    return smal_nr;
}

void problema_6::initializare(Nr*& cap, string big_nr)
{
    cap = new Nr{ element(big_nr),NULL,NULL };
    if (big_nr.empty())
    {
        cap->next = cap;
        cap->prev = cap;
        return;
    }
    Nr* oldCap = new Nr{ element(big_nr),cap,cap };
    cap->next = oldCap;
    cap->prev = oldCap;
    while (!big_nr.empty())
    {
        addNewCap(oldCap);
        oldCap->nr = element(big_nr);
    }
    cap = cap->next;
}

void problema_6::addNewCap(Nr*& cap)
{
    Nr* capNou = new Nr{ 0, cap->prev, cap };
    cap->prev->next = capNou;
    cap->prev = capNou;
    cap = capNou;
}

void problema_6::deleteCap(Nr*& cap)
{
    cap->next->prev = cap->prev;
    cap->prev->next = cap->next;
    Nr* mem = cap->next;
    delete cap;
    cap = mem;
}

bool problema_6::compBigNr(Nr* cap1, Nr* cap2)
{
    Nr* iter1 = cap1->prev;
    Nr* iter2 = cap2->prev;
    while (iter1 != cap1 && iter2 != cap2)
    {
        if (iter1->nr > iter2->nr)
        {
            return true;
        }
        if (iter1->nr < iter2->nr)
        {
            return false;
        }
        iter1 = iter1->prev;
        iter2 = iter2->prev;
    }
    if (iter1 != cap1)
    {
        return true;
    }
        return false;
}

int problema_6::adunare(Nr*& cap1, Nr*& cap2, Nr*& cap3)
{
    if (cap1 != nullptr)
    {
        cap3->nr += cap1->nr;
        cap1 = cap1->prev;
    }
    if (cap2 != nullptr)
    {
        cap3->nr += cap2->nr;
        cap2 = cap2->prev;
    }
    int carry = cap3->nr / 1000;
    cap3->nr = cap3->nr % 1000;
    return carry;
}

problema_6::Nr* problema_6::Suma2BigNr(Nr* cap1, Nr* cap2)
{
    Nr* cap = new Nr{ 0,NULL,NULL };
    Nr* iter1 = cap1;
    Nr* iter2 = cap2;
    int carry_vechi = adunare(iter1,iter2,cap);
    Nr* capNou = new Nr{ carry_vechi, cap, cap };
    int carry_nou = adunare(iter1, iter2, capNou);
    cap->next = capNou;
    cap->prev = capNou;
    cap = capNou;
    do{
        capNou = new Nr{ carry_vechi, cap->prev, cap };
        carry_nou = adunare(iter1, iter2, capNou);
        cap->prev->next = capNou;
        cap->prev = capNou;;
        carry_vechi = carry_nou;
        cap = capNou;
        if (iter1 == cap1)
        {
            iter1 = nullptr;
        }
        if (iter2 == cap2)
        {
            iter2 = nullptr;
        }
    } while(iter1 != NULL && iter2 != NULL);
    if (carry_vechi)
    {
        capNou = new Nr{ carry_vechi, cap->prev, cap };
        cap->prev->next = capNou;
        cap->prev = capNou;;
        return capNou;
    }
    return cap->prev;
}

void problema_6::afisare(Nr* cap)
{
    Nr* iter = cap;
    std::cout.fill('0');
    std::cout << std::endl;
    std::cout << iter->nr;
    iter = iter->next;
    while (iter != cap)
    {
        std::cout << ".";
        std::cout.width(3);
        std::cout<< iter->nr;
        iter = iter->next;
    }
}

problema_5::Nr* problema_5::citire()
{
    Nr* toReturn = 0;
    Nr* Cap = nullptr;
    int n;
    std::cin >> n;
    while (n != 0)
    {
        Nr* p = new Nr{ n,nullptr };
        if (Cap == nullptr)
        {
            p->next = p;
            Cap = p;
            toReturn = Cap;
        }
        else
        {
            p->next = Cap->next;
            Cap->next = p;
            Cap = p;
        }
        std::cin >> n;
    }
    return toReturn;
}

void problema_5::afisare(Nr* a)
{
    if (a == nullptr)
    {
        return;
    }
    Nr* iter = a;
    std::cout << std::endl;
    do {
        std::cout << iter->e<<" ";
        iter = iter->next;
    } while (iter != a);
}

void addElement(problema_5::Nr* xy, problema_5::Nr*& z)
{
    using problema_5::Nr;
    if (xy == nullptr)
    {
        return;
    }
    Nr* p = new Nr{ xy->e ,nullptr };
    if (z == nullptr)
    {
        p->next = p;
        z = p;
    }
    else
    {
        p->next = z->next;
        z->next = p;
        z = p;
    }
}
problema_5::Nr* problema_5::unire(Nr* x, Nr* y)
{
    Nr* z = nullptr;
    Nr* iter = x;
    do {
        addElement(iter, z);
        iter = iter->next;
    } while (iter != x);
    iter = y;
    do {
        addElement(iter, z);
        iter = iter->next;
    } while (iter != y);
    return z;
}

problema_5::Nr* problema_5::inter(Nr*& x, Nr*& y)
{
    Nr* z = nullptr;
    Nr* iter1 = x;
    Nr* iter2 = y;
    do {
        addElement(iter1, z);
        if (iter1 != nullptr)
        {
            iter1 = iter1->next;
        }
        addElement(iter2, z);
        if (iter2 != nullptr)
        {
            iter2 = iter2->next;
        }
        if (iter1 == x)
        {
            iter1 = nullptr;
        }
        if (iter2 == y)
        {
            iter2 = nullptr;
        }
    } while (iter2 != nullptr || iter1 != nullptr);
    return z->next;
}