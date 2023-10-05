#include "ElementDual.h"

ElementDual::ElementDual()
{
	this->data = 100;
}

ElementDual::ElementDual(int data)
{
	this->data = data;
	this->next = nullptr;
	this->prev = nullptr;
}

ElementDual* ElementDual::getpointernext()
{
	return this->next;
}
ElementDual* ElementDual::getpointerprev()
{
	return this->prev;
}

void ElementDual::setpointernext(ElementDual* p)
{
	this->next = p;
}

void ElementDual::setpointerprev(ElementDual* p)
{
	this->prev = p;
}

void ElementDual::setdata(int data)
{
	this->data = data;
}

int ElementDual::getdata()
{
	return this->data;
}

