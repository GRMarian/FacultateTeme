#include "Header.h"
#include<iostream>
#include<vector>
using namespace std;
problema_1::List* problema_1::creareList()
{
	int n;
	std::cin >> n;
	if (n == 0)
	{
		return nullptr;
	}
	return new List{ n, creareList() };
}
void problema_1::afisare(List* l)
{
	if (l == NULL)
	{
		return;
	}
	afisare(l->leg);
	std::cout << l->data<<" ";
}

int cmmdc(int m, int n)
{
	if (!n) return m;
	return cmmdc(n, m % n);
}

int fact(int n)
{
	if (n == 0)
		return 1;
	return n * fact(n - 1);
}

float putere(float x, int n)
{
	if (n == 0)
		return 1;
	return x * putere(x, n - 1);
}

float S(float x, int n)
{
	if (n == 0)
		return 1;
	return S(x, n - 1) + putere(x, n) / fact(n);
}

int binSearch(int a[], int b, int st, int dr)
{
		int m;
		if (st == dr)
		{
			return (b == a[dr]) ? dr : -1;//*1
		}
		else { //*2
			m = (st + dr) / 2;
			if (b <= a[m])
				return
				binSearch(a, b, st, m);
			else
				return
				binSearch(a, b, m + 1, dr);
		}
}
int Fibonacci(int n)
{
	if (n < 2)
		return n;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

bool isPrime(int p, int i) // p este variabila citită de la tastatură
{
	if (i == p) return 1;
	if (p%i == 0) return 0;
	return isPrime(p, i + 1);
}


void permutari(int n, vector<int>& perm, int pos = 0) {
	if (pos == n - 1) {
		for (int i = 0; i < n; i++) {
			std::cout << perm[i] << " ";
		}
		std::cout << std::endl;
	}
	else {
		for (int i = pos; i < n; i++) {
			std::swap(perm[pos], perm[i]);
			permutari(n, perm, pos + 1);
			std::swap(perm[pos], perm[i]);
		}
	}
}

void Hanoi(int n, char ti, char tf, char tm) {
	if (n == 1) {
		std::cout << "Mutam discul 1 de pe turnul " << ti << " pe turnul " << tf << std::endl;
	}
	else {
		Hanoi(n - 1, ti, tm, tf);
		std::cout << "Mutam discul " << n << " de pe turnul " << ti << " pe turnul " << tf << std::endl;
		Hanoi(n - 1, tm, tf, ti);
	}
}
