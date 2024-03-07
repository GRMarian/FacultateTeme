#pragma once
class Complex
{
private:
	int real;
	int imag;
public:
	Complex(int r, int i) :real(r), imag(i) {}
	int getReal() { return real; }
	int getImag() { return imag; }

	void afisare();
	Complex operator+(Complex);
};


template <typename T>
T Aduna(T a, T b) { return a + b; };
