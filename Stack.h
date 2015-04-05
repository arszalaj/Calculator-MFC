#pragma once
#include <vector>
#include <string>
using namespace std;

/** \brief Implementacja stosu 
* Implementacja stosu elementów klasy string z wykorzystaniem pojemnika (vector).
* @author 
*/


class CStack
{
public:
	CStack(void);
	~CStack(void);

	int getActualSize();
	void push(string element);
	bool pop(string &dest);
	bool isEmpty();
	bool look(string &bufor);

private:
	std::vector <std::string> stack; ///< pojemnik elementów klasy string
};
