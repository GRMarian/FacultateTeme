#pragma once
struct Lista {
	int element;
	Lista* legatura;
};

Lista* citire_my_list();
void afisare_my_list(Lista*);
void delete_recursiv(Lista*);
bool cautare_lista(Lista*,int);
void inserare(Lista*&, int, Lista*);

