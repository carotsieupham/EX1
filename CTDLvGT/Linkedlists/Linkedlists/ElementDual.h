#pragma once
class ElementDual
{
private:
	int data;
	ElementDual* prev, * next;
public:
	ElementDual();
	ElementDual(int data);
	ElementDual* getpointernext();
	ElementDual* getpointerprev();
	void setpointernext(ElementDual *p);
	void setpointerprev(ElementDual* p);
	void setdata(int data);
	int getdata();
};

