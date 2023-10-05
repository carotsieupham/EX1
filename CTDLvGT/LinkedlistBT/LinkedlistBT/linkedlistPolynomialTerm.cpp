#include "linkedlistPolynomialTerm.h"

linkedlistPolynomialTerm::linkedlistPolynomialTerm()
{
	this->head = nullptr;
	this->tail = nullptr;
}

void linkedlistPolynomialTerm::insertFirst(polynomialTerm* p)
{
	if (this->head == nullptr) {
		this->head = this->tail = p;
	}
	else
	{
		p->setpointer(this->head);
		this->head = p;
	}
}

void linkedlistPolynomialTerm::insertLast(polynomialTerm* p)
{
	if (this->head == nullptr) {
		this->head = this->tail = p;
	}
	else {
		tail->setpointer(p);
		this->tail = p;
	}
}

void linkedlistPolynomialTerm::insertP(polynomialTerm* p, polynomialTerm* x)
{
	x->setpointer(p->getpointer());
	p->setpointer(x);
}

void linkedlistPolynomialTerm::deleteP(polynomialTerm* p)
{
	polynomialTerm * q = this->head;
	while ((q->getpointer())->getheso() != p->getheso()&& (q->getpointer())->getsomu() != p->getsomu())
	{
		q = q->getpointer();
	}
	q->setpointer((q->getpointer())->getpointer());
	delete p;
}

void linkedlistPolynomialTerm::deleteFirst()
{
	polynomialTerm* p = this->head;
	this->head = this->head->getpointer();
	delete p;
}

void linkedlistPolynomialTerm::deleteLast()
{
	if (this->head == nullptr) {
		return;
	}
	if ((this->head)->getpointer() == NULL) {
		return deleteFirst();
	}
	else {
		polynomialTerm * p = this->head;
		while (p->getpointer() != this->tail)
		{
			p = p->getpointer();
		}
		delete tail;
		tail = p;
		tail->setpointer(nullptr);
	}
}

void linkedlistPolynomialTerm::rutgondathuc()
{
	if (head == nullptr) {
		return; 
	}

	polynomialTerm* current = head;
	while (current != nullptr) {
		polynomialTerm* prev = current;
		polynomialTerm* nextTerm = current->getpointer();

		while (nextTerm != nullptr) {
			if (current->getsomu() == nextTerm->getsomu()) {
				current->setheso(current->getheso() + nextTerm->getheso());
				prev->setpointer(nextTerm->getpointer());
				delete nextTerm;
				nextTerm = prev->getpointer();
			}
			else {
				prev = nextTerm;
				nextTerm = nextTerm->getpointer();
			}
		}
		current = current->getpointer();
	}
}

linkedlistPolynomialTerm linkedlistPolynomialTerm::operator+(linkedlistPolynomialTerm& p)
{
	linkedlistPolynomialTerm result;
	polynomialTerm* t1 = this->head;
	polynomialTerm* t2 = p.head;
	polynomialTerm* e;
	while (t1 != nullptr && t2 !=nullptr )
	{
		if (t1->getsomu() == t2->getsomu()) {
			int sumheso = t1->getheso() + t2->getheso();
			 e = new polynomialTerm(sumheso, t1->getsomu());
			result.insertLast(e);
			t1 = t1->getpointer();
			t2 = t2->getpointer();
		}
		else if (t1->getsomu() > t2->getsomu())
		{
			e = new polynomialTerm(t1->getheso() ,t1->getsomu());
			result.insertLast(e);
			t1 = t1->getpointer();
		}
		else {
			e = new polynomialTerm(t2->getheso(), t2->getsomu());
			result.insertLast(e);
			t2 = t2->getpointer();
		}
		while (t1 != nullptr) {
			e = new polynomialTerm(t1->getheso(), t1->getsomu());
			result.insertLast(e);
			t1 = t1->getpointer();
		}
		while (t2 != nullptr) {
			e = new polynomialTerm(t2->getheso(), t2->getsomu());
			result.insertLast(e);
			t2 = t2->getpointer();
		}
	
	}

	return result ;
}

linkedlistPolynomialTerm linkedlistPolynomialTerm::operator*(linkedlistPolynomialTerm& p)
{
	linkedlistPolynomialTerm result;

	polynomialTerm* t1 = this->head;
	while (t1 != nullptr) {
		polynomialTerm* t2 = p.head;
		while (t2 != nullptr) {
			int newCoefficient = t1->getheso() * t2->getheso();
			int newExponent = t1->getsomu() + t2->getsomu();
			result.insertLast(new polynomialTerm(newCoefficient,newExponent));
			t2 = t2->getpointer();
		}
		t1 = t1->getpointer();
	}

	return result;
}



void linkedlistPolynomialTerm::travel()
{
	polynomialTerm * p = this->head;
	while (p != nullptr)
	{
		cout << p->getheso() << "x^" << p->getsomu();
		p = p->getpointer();
		if (p != nullptr) {
			cout << " + ";
		}
	}
	cout << endl;
}
