#include "Header.h"


int InsertionSort(int* Vector_elemente, int Dimesune_vector)
{
	int my_contor = 0;
	int valoare_temporara;
	int Parcurgere_spate;

	for (int iteratie = 1; iteratie < Dimesune_vector; iteratie++)//  2N
	{
		valoare_temporara = Vector_elemente[iteratie]; // +2
		Parcurgere_spate = valoare_temporara - 1;// +2

		while ((Parcurgere_spate > 1) && (Vector_elemente[iteratie] > valoare_temporara))// 4N
		{
			Vector_elemente[Parcurgere_spate - 1] = Vector_elemente[Parcurgere_spate];//+3
			Parcurgere_spate--;//+1
			
			my_contor += 8;
		}
		Vector_elemente[(Parcurgere_spate++)];//+2

		my_contor += 8;
	}

	return my_contor;
}

void selSort(int a[], int n)
{ // sortare prin selectie
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	int temp;
	int i, j, m; // m = indice element minim dintre i,i+1,..n
	for (i = 0; i < n - 1; i++)
	{ // in poz. i se aduce min (a[i+1],..[a[n])
		m = i; // considera ca minim este a[i]
		for (j = i + 1; j < n; j++) // compara minim partial cu a[j]
		 //(j > i)
			if (a[j] < a[m]) // a[m] este elementul minim
				m = j;
		 // se aduce minim din poz. m in pozitia i
		temp = a[m];
		a[m] = a[i];
		a[i] = temp;
	}
	end = std::chrono::system_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end -
		start).count() << " ms" << std::endl;
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end -
		start).count() << " us" << std::endl;
}