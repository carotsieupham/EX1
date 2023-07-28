#include "point.h"

point::point(float x, float y)
{
	this->x = x;
	this->y = y;
}

float point::getX()
{
	return x;
}

float point::getY()
{
	return y;
}

void point::setX(float x)
{
	this->x = x;
}

void point::setY(float y)
{
	this->y = y;
}

float point::kcdengoctoado()
{
	return sqrt(x * x + y * y);
}

void point::docfile(ifstream& ifs)
{
	ifs >> x;
	ifs >> y;
}

bool point::operator<(point& b)
{

	return this->kcdengoctoado()<b.kcdengoctoado();
}



ostream& operator<<(ostream& os, point p)
{
	os << "(" << p.x << "," << p.y << ")";
	return os;
}

