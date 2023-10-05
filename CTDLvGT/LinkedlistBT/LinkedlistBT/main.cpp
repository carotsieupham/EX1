#include <iostream>
#include"linkedlistPolynomialTerm.h"
using namespace std;
int main() {
	linkedlistPolynomialTerm* list1 = new linkedlistPolynomialTerm;
	linkedlistPolynomialTerm* list2 = new linkedlistPolynomialTerm;

	polynomialTerm* e;
	e = new polynomialTerm(2, 3);
	list1->insertLast(e);
	e = new polynomialTerm(4,3);
	list1->insertLast(e);
	e = new polynomialTerm(2, 5);
	list1->insertLast(e);
	cout << "Da thuc 1: ";
	list1->travel();
	e = new polynomialTerm(3, 3);
	list2->insertLast(e);
	e = new polynomialTerm(3, 5);
	list2->insertLast(e);
	e = new polynomialTerm(3, 2);
	list2->insertLast(e);
	cout << "Da thuc 2: ";
	list2->travel();
	//linkedlistPolynomialTerm  sum= *list1 + *list2;
	//cout << "Tong da thuc 1 va da thuc 2: ";
	//sum.travel();
	cout << "Tong da thuc 1 va da thuc 2: ";
	linkedlistPolynomialTerm  sum = *list1 * *list2;
	sum.travel();
	return 0;
}