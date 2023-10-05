#pragma once
#include"polynomialTermDual.h"
class linkedlistDtDual
{
private:
	polynomialTermDual* head, * tail;
public:
	linkedlistDtDual ();
	void insertFirst(polynomialTermDual* p);
	void insertLast(polynomialTermDual* p);
	void deleteFirst();
	void deleteLast();
	void rutgondathuc();
	linkedlistDtDual operator+(linkedlistDtDual& p);
	linkedlistDtDual operator*(linkedlistDtDual& p);
	void travelnext();
	void travelprev();
};

