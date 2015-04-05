#pragma once
#include <string>
#include <ctype.h>
#include "Stack.h"
#include <cmath>
#include <iostream>
#include <sstream>

#define _USE_MATH_DEFINES

#define LEFT_ASSOC 0
#define RIGHT_ASSOC 1

#define ERROR -1
#define NUMBER 0
#define FUNCTION 1
#define OPERATOR 2
#define LB 3
#define RB 4
#define EOS 5

using namespace std;

static const string trigonometric[] = {"sin","cos","tan","ctg","NULL"};
static const double pi = 3.14159265;

/** 
* Zawiera pola i metody do przekszta³cania wyra¿enia do postaci ONP oraz do
* oszacowania wyniku wyra¿enia. Korzysta z klasy Stack.
*/
class CONP
{
public:
	CONP(void);
	~CONP(void);
	int infixToONP(std::string infix,std::string &onp);
	enum trig{ deg, rad};
	int evaluateONP(std::string onp,long double &result, trig units);
	enum sys{ bin,oct,dec,hex } ;
	void setActSystem(sys s);
	int getActualSystem() const;
	string decToHex(string int_string) const;
	string decToBin(string int_string) const;
	string decToOct(string int_string) const;
	string binToDec(string bin_string) const;
	string hexToDec(string hex_string) const;
	string octToDec(string oct_string) const;

	string radToDeg(string rad) const;
	string degToRad(string deg) const;

	string convert(string exp, sys from, sys to) const;


private:
	bool isFunction(string fn);
	int getPrior(string op,int &assoc);
	bool evaluateFunction(string fn, string arg, long double &result, trig units);
	int getNextElement(string exp,string &buffer, int &position,bool ONP);
	long long my_atoll(const char *instr) const;
	int silnia(int n) const;



};
