#include "StdAfx.h"
#include "Stack.h"

/**
* Konstruktor bezparametrowy.
* Rezerwuje wstêpnie pamiêæ na 20 elementów, aby przyspieszyæ dzia³anie programu.
*/
CStack::CStack(void)
{
	stack.reserve(20);
}

/**
* Destruktor zwalniaj¹cy pamiêæ po pojemniku.
*/
CStack::~CStack(void)
{
	stack.clear();
}

/**
* Zwraca iloœæ elementów na stosie.
* @return iloœæ elementów (int)
*/
int CStack::getActualSize()
{
	return stack.size();
}
/**
* Sprawdza, czy stos jest pusty.
* @return true, je¿eli stos jest pusty, w przeciwnym razie false
*/
bool CStack::isEmpty()
{
	if(!stack.size())
		return true;
	else return false;
}
/**
* K³adzie element na stosie.
* @param element Element klasy string.
*/
void CStack::push(string element)
{
	stack.push_back(element);
}
/**
* Zdejmuje element z góry stosu.
* @param obiekt klasy string, do którego zostanie przypisana wartoœæ elementu ze stosu.
* @return true, je¿eli uda³o siê zdj¹æ element, false - jezeli stos by³ pusty.
*/
bool CStack::pop(string &dest)
{
	if(this->isEmpty())
		return false;
	dest = stack[stack.size()-1];
	stack.pop_back();
	return true;
	
}
/**
* Podgl¹da element z góry stosu, bez œci¹gania go.
* @param obiekt klasy string, do którego zostanie przypisana wartoœæ elementu ze stosu.
* @return @return true, je¿eli by³ element na stosie, false - jezeli stos by³ pusty.
*/
bool CStack::look(string &bufor)
{
	if(this->isEmpty())
		return false;
	bufor = stack[stack.size()-1];

	return true;
}



