#pragma once
#include<vector>
using std::vector;

namespace problema_1 {
	struct List {
		int data;
		List* leg;
	};
	List* creareList();
	void afisare(List*);
}

//problema 2
int cmmdc(int m, int n);

//problema 3
int fact(int n);
float putere(float x, int n);
float S(float x, int n);

//problema 4
int binSearch(int a[], int b, int st, int dr);

//problema 5
int Fibonacci(int n);

//problema 6
bool isPrime(int p, int i);

//problema 7
void permutari(int n, vector<int>& perm, int pos);

//problema 8
void Hanoi(int n, char ti, char tf, char tm);

//problema 9
