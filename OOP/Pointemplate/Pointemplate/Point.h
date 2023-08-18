#pragma once
#include <iostream>
using namespace std;

template <class T>
class Point {
private:
    T x, y;

public:
    Point();
    Point(T x, T y);
    double distance();
    T getX();
    T getY();
    template <class T>
    friend ostream& operator<<(ostream& os, Point<T>& p);
};
