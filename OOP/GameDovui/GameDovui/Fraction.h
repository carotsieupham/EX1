#pragma once
#include<iostream>
#include<random>
using namespace std;
class Fraction
{
protected:
    int numerator;
    int denominator;
public:

    Fraction();
    Fraction(int num, int den);
    int getNum() const;
    int getDen() const;
    friend int uscln(Fraction a);
    friend Fraction rutgon(Fraction a);

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    bool operator<(const Fraction& other)const;
    friend ostream& operator<<(ostream& os, const Fraction& other);
    friend istream& operator>>(istream& is, Fraction& other);
};

