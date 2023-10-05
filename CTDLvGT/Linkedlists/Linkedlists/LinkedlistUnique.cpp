#include "LinkedlistUnique.h"

void LinkedlistUnique::insertFirstUnique(Element* p)
{
	if (this->head == nullptr) {
		this->head = this->tail = p;
	}
	else
	{
		Element* q = this->head;
		while (q != nullptr)
		{
			if (q->getdata() == p->getdata()) return;
			q= q->getpointer();
		}
		p->setpointer(this->head);
		this->head = p;
	}
}

void LinkedlistUnique::insertLastUnique(Element* p)
{
	if (this->head == nullptr) {
		this->head = this->tail = p;
	}
	else
	{
		Element* q = this->head;
		while (q != nullptr)
		{
			if (q->getdata() == p->getdata()) return;
			q = q->getpointer();
		}
		tail->setpointer(p);
		this->tail = p;
	}
}

