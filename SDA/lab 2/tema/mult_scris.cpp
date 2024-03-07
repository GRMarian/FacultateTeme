#include "mult_scris.h"

void my_mult_scris::InsertionSort_timp(int* Vector_elemente, int Dimesune_vector)
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	int valoare_temporara;
	int Parcurgere_spate;

	for (int iteratie = 1; iteratie < Dimesune_vector; iteratie++)
	{
		valoare_temporara = Vector_elemente[iteratie];
		Parcurgere_spate = valoare_temporara - 1;

		while ((Parcurgere_spate > 1) && (Vector_elemente[iteratie] > valoare_temporara))
		{
			Vector_elemente[Parcurgere_spate - 1] = Vector_elemente[Parcurgere_spate];
			Parcurgere_spate--;

		}
		Vector_elemente[(Parcurgere_spate++)];
	}
	end = std::chrono::system_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " ";//us
}

void my_mult_scris::InsertionSort_cont(int* Vector_elemente, int Dimesune_vector)
{
	int my_contor = 0;
	int valoare_temporara;
	int Parcurgere_spate;

	for (int iteratie = 1; iteratie < Dimesune_vector; iteratie++)//  2
	{
		valoare_temporara = Vector_elemente[iteratie]; // +2
		Parcurgere_spate = valoare_temporara - 1;// +2

		while ((Parcurgere_spate > 1) && (Vector_elemente[iteratie] > valoare_temporara))// 4
		{
			Vector_elemente[Parcurgere_spate - 1] = Vector_elemente[Parcurgere_spate];//+3
			Parcurgere_spate--;//+1

			my_contor += 8;
		}
		Vector_elemente[(Parcurgere_spate++)];//+2

		my_contor += 8;
	}
	std::cout << my_contor << " ";
}

void my_mult_scris::selSort_timp(int a[], int n)
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
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end -start).count() << " ";//us
}

void my_mult_scris::selSort_cont(int a[], int n)
{
	int count = 0;
	int temp;
	int i, j, m; 
	for (i = 0; i < n - 1; i++)//+3
	{ 
		m = i;//+1
		count += 4;
		for (j = i + 1; j < n; j++)// +2
		{
			count += 5;
			if (a[j] < a[m]) //+3
			{
				count+=1;
				m = j;//+1
			}
		}
		temp = a[m];//+2
		a[m] = a[i];//+3
		a[i] = temp;//+2
		count += 7;
	}
	std::cout <<count << " ";
}

void my_mult_scris::bubble_sort_timp(int*A, int n)
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	bool swapped = 1;
	int j = 0;
	int tmp;
	while (swapped)
	{
		swapped = 0;
		j = j + 1;
		for (int i = 1;i < n - j;i++)
		{
			if (A[i] > A[i + 1])
			{
				tmp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = tmp;
				swapped = 1;
			}
		}
	}
	end = std::chrono::system_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " ";//us
}

void my_mult_scris::bubble_sort_cont(int*A, int n)
{
	int count = 0;
	bool swapped = 1;//+1
	int j = 0;//+1
	int tmp;
	count += 2;
	while (swapped)//+1
	{
		swapped = 0;//+1
		j = j + 1;//+1
		count += 3;
		for (int i = 1;i < n - j;i++)//+3
		{
			count += 6;
			if (A[i] > A[i + 1])//+3
			{
				tmp = A[i];//+2
				A[i] = A[i + 1];//+3
				A[i + 1] = tmp;//+2
				swapped = 1;//+1
				count += 8;
			}
		}
	}
	std::cout << count << " ";
}

int my_mult_scris::My_Binary_search_timp(int*A, int n, int b)
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	int low = 1;
	int high = n;
	int mid = 0;
	while (low <= high)
	{
		mid = (low + high) / 2; // partea intreaga
		if (A[mid] = b)
		{
			return mid;
		}
		else
		{
			if (A[mid] > b)
			{
				high = mid - 1; // restrang cautarea la stanga
			}
			else
			{
				low = mid + 1; // restrang cautarea la dreapta
			}
		}
	}
	end = std::chrono::system_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " ";//us
	return 0;
}

int my_mult_scris::My_Binary_search_cont(int*A, int n, int b)
{
	int count = 0;
	int low = 1;//+1
	int high = n;//+1
	int mid = 0;//imi da warning daca nu initializez valoarea
	count += 2;
	while (low <= high)//+1
	{
		mid = (low + high) / 2; //+3
		count += 6;
		if (A[mid] = b)//+2
		{
			return mid;
		}
		else
		{
			count += 2;
			if (A[mid] > b)//+2
			{
				count += 2;
				high = mid - 1; // +2
			}
			else
			{
				count += 2;
				low = mid + 1; // +2
			}
		}
	}
	std::cout << count << " ";
	return 0;
}

int my_mult_scris::Brute_force_timp(int* A, int n, int b)
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	int i = 1;
	while (i <= n)
	{

		if (A[i] = b)
		{
			return 1;
		}
		i = i + 1;
	}
	end = std::chrono::system_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " ";//us
	return 0;
}

int my_mult_scris::Brute_force_cont(int* A, int n, int b)
{
	int count=0;
	int i = 1;
	while (i <= n)//+1
	{
		count += 3;
		if (A[i] = b)//+2
		{
			return 1;
		}
		count += 2;
		i = i + 1;//+2
	}
	std::cout << count << " ";
	return 0;
}


