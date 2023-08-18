#include "Point.h"
#include <cmath>

template <class T>
Point<T>::Point() {
    x = 0;
    y = 0;
}

template <class T>
Point<T>::Point(T x, T y) {
    this->x = x;
    this->y = y;
}

template <class T>
double Point<T>::distance() {
    return sqrt(x * x + y * y);
}

template <class T>
T Point<T>::getX() {
    return x;
}

template <class T>
T Point<T>::getY() {
    return y;
}

template <class T>
ostream& operator<<(ostream& os, Point<T>& p) {
    os << "(" << p.getX() << "," << p.getY() << ")" ;
    return os;
}