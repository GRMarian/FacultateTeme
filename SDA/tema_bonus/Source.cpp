#include<iostream>
#include<string>
#include"Header.h"

using namespace std;

int main()
{
	string ll = "(1+2)*(2+3)";
	string v = "(1+9*2)/3+5";
	string n = "1+2*3";
	string x = "5+(2*3+4)/(6-4)";
	string xx = "5+(2*3+4)/(6-4)";
	string z = "(1+2)*3";
	string l = "1*(3*4)";
	string p = "1*2+3*4";
	string j = "1+(2+3*4)";
	string h = "1+(2*3)/4";
	string g = "1+(2*3)";
	string f = "2+(1-2)+3";
	string e = "2*3+4";
	//string a = "(5+6)/2";
	string k = problema_bonus::infixat_prefixat_clean(xx);
	string kk = problema_bonus::infixat_prefixat_b(xx);

	cout << k;
	cout << endl << kk;
	//string god = problema_bonus::infixat_prefixat_gpt(e);
	//double rezultat = problema_bonus::evaluare_prefixat(k);
	//cout << k;
	//cout << " = " ;
	//cout << rezultat;
	//cout << god;
	//cout << endl;
	//string x = problema_4::infixat_postfaxat(a);
	//cout << x;

	//string p = "123";
	//reverse(p.begin(),p.end());
	//cout << p;
}