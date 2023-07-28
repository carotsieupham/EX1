#include "fraction.h"

fraction::fraction()
{
	numerator = 0;
	denominator = 1;
}

fraction::fraction(int n)
{   
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(0, n);
    numerator = distribution(generator);
    denominator = distribution(generator) + 1;
}

fraction::fraction(int num, int dem)
{
	numerator = num;
	denominator = dem;
}

int fraction::getNum() const {
    return numerator;
}

int fraction::getDen() const {
    return denominator;
}

int uscln(fraction a) {
    while (a.denominator != 0) {
        int r = a.numerator % a.denominator;
        a.numerator = a.denominator;
        a.denominator = r;
    }
    return a.numerator;
}

fraction rutgon(fraction a) {
    int gcd = uscln(a);
    a.numerator = a.numerator / gcd;
    a.denominator = a.denominator / gcd;
    return a;
}

fraction fraction::operator+(const fraction& other) const {
    fraction v;
    v.numerator = this->numerator * other.denominator + this->denominator * other.numerator;
    v.denominator = this->denominator * other.denominator;
    return rutgon(v);
}

fraction fraction::operator-(const fraction& other) const {
    fraction v;
    v.numerator = this->numerator * other.denominator - this->denominator * other.numerator;
    v.denominator = this->denominator * other.denominator;
    return rutgon(v);
}

fraction fraction::operator*(const fraction& other) const {
    fraction v;
    v.numerator = this->numerator * other.numerator;
    v.denominator = this->denominator * other.denominator;
    return rutgon(v);
}

fraction fraction::operator/(const fraction& other) const {
    fraction v;
    v.numerator = this->numerator * other.denominator;
    v.denominator = this->denominator * other.numerator;
    return rutgon(v);
}

bool fraction::operator==(const fraction& other) const {
    return this->numerator * other.denominator == other.numerator * this->denominator;
}

bool fraction::operator!=(const fraction& other) const {
    return !(*this == other);
}

bool fraction::operator<=(const fraction& other) const {
    return this->numerator * other.denominator <= other.numerator * this->denominator;
}

bool fraction::operator>=(const fraction& other) const {
    return this->numerator * other.denominator >= other.numerator * this->denominator;
}

bool fraction::operator<(const fraction& other) const
{
    return this->numerator * other.denominator < other.numerator * this->denominator;
}

ostream& operator<<(ostream& os, const fraction& other) {
    os << other.numerator << "/" << other.denominator;
    return os;
}

istream& operator>>(istream& is, fraction& other) {
    is >> other.numerator >> other.denominator;
    return is;
}



