#include "Element.h"



Element::Element()
{
	this->data = 100;
}

Element::Element(int d)
{
	this->data = d;
	this->p = nullptr;
}

int Element::getdata()
{
	return this->data;
}

void Element::setdata(int d)
{
	this->data = d;
}

void Element::showdata()
{
	cout << this->data<<endl;
}

Element* Element::getpointer()
{
	return this->p;
}

void Element::setpointer(Element* p)
{
	this->p = p;
}

Element::~Element()
{

}


