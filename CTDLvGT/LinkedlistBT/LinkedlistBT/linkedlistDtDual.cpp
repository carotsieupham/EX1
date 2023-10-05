#include "linkedlistDtDual.h"
#include<iostream>
using namespace std;
linkedlistDtDual::linkedlistDtDual()
{
	this->head = nullptr;
	this->tail = nullptr;
}

void linkedlistDtDual::insertFirst(polynomialTermDual* p)
{
	if (this->head == nullptr) {
		this->head = this->tail = p;
	}
	else
	{
		p->setpointernext(this->head);
		this->head->setpointerprev(p);
		this->head = p;
	}
}

void linkedlistDtDual::insertLast(polynomialTermDual* p)
{
	if (this->head == nullptr) {
		this->head = this->tail = p;
	}
	else {
		tail->setpointernext(p);
		p->setpointerprev(this->tail);
		this->tail = p;
	}
}

void linkedlistDtDual::deleteFirst()
{

}

void linkedlistDtDual::deleteLast()
{
}

void linkedlistDtDual::rutgondathuc()
{
	if (head == nullptr) {
		return;
	}

	polynomialTermDual* current = head;
	while (current != nullptr) {
		polynomialTermDual* prev = current;
		polynomialTermDual* nextTerm = current->getpointernext();

		while (nextTerm != nullptr) {
			if (current->getsomu() == nextTerm->getsomu()) {
				current->setheso(current->getheso() + nextTerm->getheso());
				prev->setpointernext(nextTerm->getpointernext());
				delete nextTerm;
				nextTerm = prev->getpointernext();
			}
			else {
				prev = nextTerm;
				nextTerm = nextTerm->getpointernext();
			}
		}
		current = current->getpointernext();
	}
}

linkedlistDtDual linkedlistDtDual::operator+(linkedlistDtDual& p)
{
	linkedlistDtDual result;
	polynomialTermDual* t1 = this->head;
	polynomialTermDual* t2 = p.head;
	polynomialTermDual* e;
	while (t1 != nullptr && t2 != nullptr)
	{
		if (t1->getsomu() == t2->getsomu()) {
			int sumheso = t1->getheso() + t2->getheso();
			e = new polynomialTermDual(sumheso, t1->getsomu());
			result.insertLast(e);
			t1 = t1->getpointernext();
			t2 = t2->getpointernext();
		}
		else if (t1->getsomu() > t2->getsomu())
		{
			e = new polynomialTermDual(t1->getheso(), t1->getsomu());
			result.insertLast(e);
			t1 = t1->getpointernext();
		}
		else {
			e = new polynomialTermDual(t2->getheso(), t2->getsomu());
			result.insertLast(e);
			t2 = t2->getpointernext();
		}
		while (t1 != nullptr) {
			e = new polynomialTermDual(t1->getheso(), t1->getsomu());
			result.insertLast(e);
			t1 = t1->getpointernext();
		}
		while (t2 != nullptr) {
			e = new polynomialTermDual(t2->getheso(), t2->getsomu());
			result.insertLast(e);
			t2 = t2->getpointernext();
		}

	}

	return result;
}

linkedlistDtDual linkedlistDtDual::operator*(linkedlistDtDual& p)
{
	linkedlistDtDual result;

	polynomialTermDual* t1 = this->head;
	while (t1 != nullptr) {
		polynomialTermDual* t2 = p.head;
		while (t2 != nullptr) {
			int newCoefficient = t1->getheso() * t2->getheso();
			int newExponent = t1->getsomu() + t2->getsomu();
			result.insertLast(new polynomialTermDual(newCoefficient, newExponent));
			t2 = t2->getpointernext();
		}
		t1 = t1->getpointernext();
	}

	return result;
}

void linkedlistDtDual::travelnext()
{
	polynomialTermDual* p = this->head;
	while (p != nullptr)
	{
		cout << p->getheso() << "x^" << p->getsomu();
		p = p->getpointernext();
		if (p != nullptr) {
			cout << " + ";
		}
	}
	cout << endl;
}

void linkedlistDtDual::travelprev()
{
	polynomialTermDual* p = this->tail;
	while (p != nullptr)
	{
		cout << p->getheso() << "x^" << p->getsomu();
		p = p->getpointerprev();
		if (p != nullptr) {
			cout << " + ";
		}
	}
	cout << endl;
}
