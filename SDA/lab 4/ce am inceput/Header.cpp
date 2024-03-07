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
        while (myList->next != NULL)
        {
            myList = myList->next;
            pozitie--;
            if (pozitie == 0)
            {
                List* ToDelete = myList;
                myList->prev->next = myList->next;
                myList->next->prev = myList->prev;
                myList= myList->prev;
                delete ToDelete;
                return;
            }
        }
    }
    while (myList->prev != NULL)
    {

        myList = myList->prev;
        pozitie--;
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
    //Z_f = NULL;
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
        List* New = new List{element,myList};
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
