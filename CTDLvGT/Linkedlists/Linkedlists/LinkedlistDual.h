#pragma once
#include "ElementDual.h"
class LinkedlistDual
{
private:
	ElementDual* head, * tail;
public:
	LinkedlistDual();
	void insertFist(ElementDual *p);
	void insertTail(ElementDual *p);
	void travelNext();
	void travelPrev();
};

