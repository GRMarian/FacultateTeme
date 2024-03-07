#include "Header.h"
#include <iostream>
void problema_1::InitStack(Stiva & s)
{
	s.vf = -1;
}

bool problema_1::IsEmpty(Stiva & s)
{
	if (s.vf = - 1)
	{
		return true;
	}
	return false;
}

bool problema_1::IsFull(Stiva & s)
{
	if(s.vf = DIM_MAX - 1)
	{
		return true;
	}
	return false;
}

int problema_1::Top(Stiva & s)
{
	return s.vect[s.vf];
}

void problema_1::Push(Stiva & s, int val)
{
	s.vf++;
	s.vect[s.vf] = val;
}

void problema_1::Pop(Stiva & s)
{
	s.vf--;
}

void probelma_2::InitStack(Element *& s)
{
	s = nullptr;
}

bool probelma_2::IsEmpty(Element *& s)
{
	if (s = nullptr)
	{
		return true;
	}
	return false;
}

int probelma_2::Top(Element *& s)
{
	return s->value;
}

void probelma_2::Push(Element *& s, int val)
{
	Element*p = new Element{ val, s };
	s = p;
}

void probelma_2::Pop(Element *& s)
{
	Element*p = s;
	s = s->next;
	delete p;
}

void problema_3::InitStack(Operand *& s)
{
	s = nullptr;
}

bool problema_3::IsEmpty(Operand *& s)
{
	if (s = nullptr)
	{
		return true;
	}
	return false;
}

int problema_3::Top(Operand * s)
{
	return s->value;
}

void problema_3::Push(Operand *& s, int val)
{
	Operand *p = new Operand{ val,s };
	s = p;
}

void problema_3::Pop(Operand *& s)
{
	Operand*p = s;
	s = s->next;
	delete p;
}

int problema_3::evaluare_forma_postfixata(string formula)
{
	Operand*s;
	int op1;
	int op2;
	InitStack(s);
	while (!formula.empty())
	{
		if ('9' >= formula[0] && formula[0] >= '0')
		{
			Push(s, formula[0] - '0');
		}
		else
		{
			op1 = Top(s); Pop(s);
			op2 = Top(s); Pop(s);
			switch (formula[0])
			{
			case'+':
				Push(s, op1 + op2);
				break;
			case'*':
				Push(s, op1 * op2);
				break;
			case'/':
				Push(s, op1 / op2);
				break;
			case'%':
				Push(s, op1 % op2);
				break;
			case'-':
				Push(s, op1 - op2);
				break;
			default:
				std::cout << std::endl << "element invalid" << std::endl; return 0; break;
			}
		}
		formula = formula.substr(1);
	}
	return Top(s);
}

void problema_4::InitStack(Operand *& s)
{
	s = nullptr;
}

bool problema_4::IsEmpty(Operand *& s)
{
	if (s = nullptr)
	{
		return true;
	}
	return false;
}

string problema_4::Top(Operand * s)
{
	return s->value;
}

void problema_4::Push(Operand *& s, string val)
{
	Operand *p = new Operand{ val,s };
	s = p;
}

void problema_4::Pop(Operand *& s)
{
	Operand*p = s;
	s = s->next;
	delete p;
}
string af_op(problema_4::Operand*&s)
{
	using namespace problema_4;
	if (Top(s) != ")")
	{
		return "";
	}
	Pop(s);
	string rez = "";
	while (Top(s) != "(" && !IsEmpty(s))
	{
		rez += Top(s);
		Pop(s);
	}
	if (!IsEmpty(s))
	{
		Pop(s);
	}
	return rez;
}
string problema_4::infixat_postfaxat(string formula)
{
	Operand*s; InitStack(s);
	string  rez = "";
	string operatori = "+-*/%()";
	while (!formula.empty())
	{
		string index = formula.substr(0, 1);
		if ("9" >= index && index >= "0")
		{
			rez += index;
		}
		if (operatori.find(index))
		{
			if (index == ")")
			{
				rez += af_op(s);
			}
			else
			{
				Push(s, index);
			}
		}
		formula = formula.substr(1);
	}
	return 0;
}
