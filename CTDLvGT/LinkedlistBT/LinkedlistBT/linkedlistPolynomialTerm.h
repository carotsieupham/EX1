#pragma once
#include "polynomialTerm.h"
class linkedlistPolynomialTerm
{
private:
	polynomialTerm* head, * tail;
public:
	linkedlistPolynomialTerm();
	void insertFirst(polynomialTerm * p);
	void insertLast(polynomialTerm* p);
	void insertP(polynomialTerm* p, polynomialTerm* x);
	void deleteP(polynomialTerm* p);
	void deleteFirst();
	void deleteLast();
	void rutgondathuc();
	linkedlistPolynomialTerm operator+(linkedlistPolynomialTerm& p);
	linkedlistPolynomialTerm operator*(linkedlistPolynomialTerm& p);
	void travel();
};

