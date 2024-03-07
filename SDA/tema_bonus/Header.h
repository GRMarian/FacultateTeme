#pragma once
#include<string>;
using std::string;
namespace problema_1 {
	#define DIM_MAX 10
	struct Stiva
	{
		int vf;
		int vect[DIM_MAX];
	};
	void InitStack(Stiva&s);
	bool IsEmpty(Stiva&s);	bool IsFull(Stiva&s);
	int Top(Stiva&s);	void Push(Stiva&s, int val);	void Pop(Stiva&s);
}

namespace probelma_2 {
	struct Element
	{
		int value;
		Element*next;
	};
	void InitStack(Element*&s);
	bool IsEmpty(Element*&s);
	int Top(Element*&s);	void Push(Element*&s, int val);	void Pop(Element*&s);
}

namespace problema_3 {
	struct Operand {
		int value;
		Operand* next;
	};
	void InitStack(Operand*&s);
	bool IsEmpty(Operand*&s);
	int Top(Operand*s);	void Push(Operand*&s, int val);	void Pop(Operand*&s);

	int evaluare_forma_postfixata(string);
}

namespace problema_4 {
	struct Operand {
		string value;
		Operand* next;
	};
	void InitStack(Operand*&s);
	bool IsEmpty(Operand*&s);
	string Top(Operand*s);	void Push(Operand*&s, string val);	void Pop(Operand*&s);

	string infixat_postfaxat(string formula);
}
namespace problema_bonus {
	using namespace problema_4;

	string const operatori = "+-*/%()";
	string const operatori_prio = "*/%";
	string const numar = "0123456789";

	string infixat_prefixat(string& formula,int&,int&,int&);
	string infixat_prefixat_clean(string);
	string infixat_prefixat_b(string&);
	double evaluare_prefixat(string&);
}
