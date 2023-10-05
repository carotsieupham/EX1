#pragma once
#include<iostream>
using namespace std;
class Element
{
private:
	int data;
	Element *p;
public:
	Element();
	Element(int d);
	int getdata();
	void setdata(int d);
	void showdata();
	Element* getpointer();
	void setpointer(Element *p);
	~Element();
};

