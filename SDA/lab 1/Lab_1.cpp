#include<iostream>
#include"GRUPA.h"


int main()
{
	Grupa O2_B;
	InitGrupa(O2_B);
	AfisGrupa(O2_B);

	std::cout << std::endl;
	CautaStudent((char*)"peista", O2_B);

	std::cout << std::endl;
	MaxMinNota(O2_B);

	StergeGrupa(O2_B);
}