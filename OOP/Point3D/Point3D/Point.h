#pragma once
#include <iostream>
#include <math.h>
#include<fstream>
#include<string>
using namespace std;
template <class T>
class Point
{
private:
	T x, y, z;
public:
	Point() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Point(T x, T y, T z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	friend ostream& operator<<(ostream& os, const Point<T>& p) {
		os << "(" << p.x << "," << p.y << "," << p.z << ")";
		return os;
	}
	friend istream& operator>>(istream& is, Point<T>& p) {
		cout << "Nhap toa do diem x,y,z:";
		is >> p.x >> p.y >> p.z;
		return is;
	}
	double operator-(Point<T>& p1) {
		T dx = this->x - p1.x;
		T dy = this->y - p1.y;
		T dz = this->z - p1.z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	 }
	bool operator==(Point<T>& p) {
		return (x == p.x) && (y == p.y) && (z == p.z);
	 }
	bool operator!=(Point<T>& p) {
		return !(*this == p);
	 }
	void docfile(ifstream& ifs) {
		ifs >> x;
		ifs >> y;
		ifs >> z;
	 }

};


