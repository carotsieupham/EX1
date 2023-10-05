#pragma once
#include"Element.h"
class Linkedlist
{
protected:
	Element* head, * tail;
public:
	Linkedlist();
	void insertFirst(Element*p);
	void insertLast(Element* p);
	void removeAll();
	int sumList();
	int maxList();
	int countList();
	void deleteFirst();  
	void deleteLast();
	int countSameX(int x);
	void splitList(int x);
	void insertP(Element* p, Element* x);
	void deleteP(Element* p);
	void travel();
	~Linkedlist();
};

