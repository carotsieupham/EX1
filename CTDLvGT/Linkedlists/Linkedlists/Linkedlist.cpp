#include "Linkedlist.h"

Linkedlist::Linkedlist()
{
	this ->head  = nullptr;
	this->tail = nullptr;
}

void Linkedlist::insertFirst(Element* p)
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

void Linkedlist::insertLast(Element* p)
{
	if (this->head == nullptr) {
		this->head = this->tail = p;
	}
	else {
		tail->setpointer(p);
		this->tail = p;
	}
}

void Linkedlist::removeAll()
{
	this->head = this->tail = nullptr;
}

int Linkedlist::sumList()
{
	Element* p = this->head;
	int sum = 0;
	while (p != nullptr)
	{
		sum += p->getdata();
		p = p->getpointer();
	}
	return sum;
}

int Linkedlist::maxList()
{
	Element* p = this->head;
	int s = p->getdata();
	while (p != nullptr)
	{
		if (p->getdata() > s) {
			s = p->getdata();
		}
		p = p->getpointer();
	}
	return s;
}

int Linkedlist::countList()
{
	Element* p = this->head;
	int count = 0;
	while (p != nullptr)
	{
		count++;
		p = p->getpointer();
	}
	return count;
}

void Linkedlist::deleteFirst()
{
	Element* p = this->head;
	this->head= this->head->getpointer();
	delete p;
}

void Linkedlist::deleteLast()
{
	if (this->head == nullptr) {
		return;
	}
	if ((this->head)->getpointer()==NULL) {
		return deleteFirst();
	}
	else{
	Element* p = this->head;
	while (p->getpointer() != this->tail)
	{
		p = p->getpointer();
	}
	delete tail;
	tail = p;
	tail->setpointer(nullptr);
	}
}

int Linkedlist::countSameX(int x)
{	
	Element* p = this->head;
	int count = 0;
	while (p != nullptr)
	{
		if (p->getdata() == x) {
			count++;
		}
		p = p->getpointer();
	}
	return count;
}

void Linkedlist::splitList(int x)
{
	Linkedlist *llarge = new Linkedlist();
	Linkedlist *lsmall = new Linkedlist();
	Element* p = this->head;
	while (p != nullptr)
	{
		if (p->getdata() >= x) {
			llarge->insertLast(new Element(p->getdata()));
		}
		else {
			lsmall->insertLast(new Element(p->getdata()));
		}
		p = p->getpointer();
	}
	cout << "List lon hon X:" << endl;
	llarge->travel();
	cout << "List be hon X:" << endl;
	lsmall->travel();
}

void Linkedlist::insertP(Element* p, Element* x)
{
	x->setpointer(p->getpointer());
	p->setpointer(x);
}

void Linkedlist::deleteP(Element* p)
{
	Element* q = this->head;
	while ((q->getpointer())->getdata() != p->getdata())
	{
		q = q->getpointer();
	}
	q->setpointer((q->getpointer())->getpointer());
	delete p;
}

void Linkedlist::travel()
{
	Element* p = this->head;
	while (p!=nullptr)
	{
		p->showdata();
		p = p->getpointer();
	}
}

Linkedlist::~Linkedlist()
{

}
