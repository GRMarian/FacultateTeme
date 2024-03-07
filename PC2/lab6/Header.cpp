#include"Header.h"

template<class tip>
void sort(unsigned int dimensiune, tip* vector) {
	tip intermediar;
	for (unsigned int i = 0; i < dimensiune-1; i++) {
		for (unsigned int j = 0; j < dimensiune - i-1; j++) {
			if (vector[j] > vector[j + 1])
			{
				intermediar = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = intermediar;
			}
		}
	}
}
