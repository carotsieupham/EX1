#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;
class fraction
{
private:
	int numerator;
	int denominator;
public:
    fraction();
    fraction(int n);
    fraction(int num, int den);
    int getNum() const;
    int getDen() const;
    friend int uscln(fraction a);
    friend fraction rutgon(fraction a);

    fraction operator+(const fraction& other) const;
    fraction operator-(const fraction& other) const;
    fraction operator*(const fraction& other) const;
    fraction operator/(const fraction& other) const;

    bool operator==(const fraction& other) const;
    bool operator!=(const fraction& other) const;
    bool operator<=(const fraction& other) const;
    bool operator>=(const fraction& other) const;
    bool operator<(const fraction& other)const;

    friend ostream& operator<<(ostream& os, const fraction& other);
    friend istream& operator>>(istream& is, fraction& other);
};

