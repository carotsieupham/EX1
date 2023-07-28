#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
class point
{
private:
	float x;
	float y;
public:
	point(float x=0, float y=0);
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	float kcdengoctoado();
	void docfile(ifstream& ifs);
	bool operator<(point& b);
	friend ostream& operator<<(ostream& os, point p);
};

