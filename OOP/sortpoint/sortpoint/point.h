#pragma once
#include <iostream>
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
};

