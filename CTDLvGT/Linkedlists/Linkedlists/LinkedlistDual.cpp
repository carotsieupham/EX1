#include "LinkedlistDual.h"
#include <iostream>
using namespace std;
LinkedlistDual::LinkedlistDual()
{
	this->head = nullptr;
	this->tail = nullptr;
}

void LinkedlistDual::insertFist(ElementDual* p)
{
	if (this->head == nullptr) {
		this->head = this->tail = p;
	}
	else{
		p->setpointernext(this->head);
		this->head->setpointerprev(p);
		this->head = p;
	}
}

void LinkedlistDual::insertTail(ElementDual* p)
{
	if (this->head == nullptr) {
		this->head = this->tail = p;
	}
	else {
		p->setpointerprev(this->tail);
		this->tail->setpointernext(p);
		this->tail = p;
	}
}



void LinkedlistDual::travelNext()
{
	ElementDual* p=this->head;
	while (p!=nullptr)
	{
		cout << p->getdata() << endl;
		p = p->getpointernext();
	}
}

void LinkedlistDual::travelPrev()
{
	ElementDual* p = this->tail;
	while (p != nullptr)
	{
		cout << p->getdata() << endl;
		p = p->getpointerprev();
	}
}
