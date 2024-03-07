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
			op2 = Top(s); Pop(s);
			op1 = Top(s); Pop(s);
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
	if (s == nullptr)
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
string inline af_op(problema_4::Operand*&s)
{
	using namespace problema_4;
	string rez = "";
	while (!IsEmpty(s) && Top(s) != "(")
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
	string prio = "*/%";
	string index;
	while (!formula.empty())
	{
		index = formula.substr(0, 1);
		formula = formula.substr(1);
		if ("9" >= index && index >= "0")
		{
			rez += index;
		}
		if (operatori.find(index)!=string::npos)
		{
			if (prio.find(index) != string::npos)
			{
				Push(s, "(");
				Push(s, index);
				formula = formula.substr(0, 1) + ")" + formula.substr(1);
				continue;
			}
			if (index == ")")
			{
				rez += af_op(s);
			}
			else
			{
				Push(s, index);
			}
		}
	}
	rez += af_op(s);
	return rez;
}


string problema_bonus::infixat_prefixat(string& formula, int& mijloc, int& paranteze, int& prio)
{
	string rez = "";
	mijloc = 0;
	paranteze = 0;
	prio = 0;

	string index = formula.substr(0, 1);
	if (!formula.empty())
	{
		formula = formula.substr(1);
		rez = infixat_prefixat(formula, mijloc, paranteze, prio);
	}
	else
	{
		return rez;
	}
	if (numar.find(index) != string::npos)
	{
		if (mijloc>0 && operatori_prio.find(rez[mijloc-1])!=string::npos)
		{
			if (rez[mijloc]==' ')
			{
				if (prio >= 1)
				{
					rez[mijloc] = index[0];
					mijloc--;
				}
			}
		}
		else
		{
			rez.insert(mijloc, index);
		}
		return rez;
	}
	if (operatori_prio.find(index) != string::npos){
		rez.insert(mijloc, index+" ");
		prio++;
		mijloc++;
		return rez;
	}
	if (index == ")")//set
	{
		paranteze = mijloc;
		if (rez[mijloc] == ' ')
		{
			mijloc++;
			prio += 1;
		}
		return rez;
	}
	if (index == "(")//reset
	{
		mijloc = paranteze;
		paranteze = 0;
		if (prio == 1 )
		{
			if (rez[mijloc] != ' ')
			{
				prio -= 1;
					mijloc--;
			}
		}
		if (mijloc < 0)
		{
			mijloc = 0;
		}
		return rez;
	}
	if (paranteze > 0)
	{
		rez.insert(mijloc, index);
		mijloc++;
		return rez;
	}
	if (rez[mijloc] == ' ')
	{
		mijloc -= 2;
		if (mijloc < 0)
		{
			mijloc = 0;
		}
	}
	rez.insert(mijloc, index);
	mijloc++;
	return rez;
}

string clean(string& a)
{
	for (int i=0;i < a.length();i++)
	{
		if (a[i] == ' ')
		{
			a = a.substr(0, i) + a.substr(i + 1);
		}
	}
	return a;
}
string problema_bonus::infixat_prefixat_clean(string a)
{
	a=clean(a);
	int d, b, c;
	a = infixat_prefixat(a, d, b, c);
	a = clean(a);
	return a;
}
string problema_bonus::infixat_prefixat_b(string& formula)
{
	char index;
	string rez;
	string tmp;
	int begin = 0;
	while (!formula.empty())
	{
		index = formula[0];
		formula = formula.substr(1);
		if (numar.find(index)!=string::npos)
		{
			rez = rez + index;
		}
		switch (index)
		{
		case '*':
		case '/':
		case '%':
			tmp = index;
			if (numar.find(rez[begin]) != string::npos)
			{
				if (rez.size() == 1 || operatori_prio.find(rez[begin]) != string::npos)
				{
					rez = index + rez;
					break;
				}
				
			}
			if (operatori_prio.find(rez[begin]) == string::npos)
			{
				begin++;
			}

			rez.insert(begin, tmp);
			break;
		case '-':
		case '+':
			rez = index + rez;
			begin++;
			break;
		case'(':
			rez += infixat_prefixat_b(formula);
			break;
		case')':
			return rez;
		default:
			break;
		}
	}
	return rez;
}
double (*pb)(string&) = &problema_bonus::evaluare_prefixat;
double problema_bonus::evaluare_prefixat(string& formula)
{
	char index;
	double rez = 0;
	if (!formula.empty())
	{
		index = formula[0];
		formula = formula.substr(1);
		switch(index)
		{
		case '*': 
			rez = pb(formula) * pb(formula);
			break;
		case '/':
			rez = pb(formula) / pb(formula);
			break;
		case '+':
			rez = pb(formula) + pb(formula);
			break;
		case '-':
			rez = pb(formula) - pb(formula);
			break;
		case '%':
			rez = pb(formula) * pb(formula);
			break;
		}
		if (numar.find(index) != string::npos)
		{
			return double(index - '0');
		}
	}
	return rez;
}