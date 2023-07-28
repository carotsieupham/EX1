#include "Fraction.h"
Fraction::Fraction()
{
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(0, 100);
    numerator = distribution(generator);
    denominator = distribution(generator) + 1;
}

Fraction::Fraction(int num, int dem)
{
    numerator = num;
    denominator = dem;
}

int Fraction::getNum() const {
    return numerator;
}

int Fraction::getDen() const {
    return denominator;
}

int uscln(Fraction a) {
    while (a.denominator != 0) {
        int r = a.numerator % a.denominator;
        a.numerator = a.denominator;
        a.denominator = r;
    }
    return a.numerator;
}

Fraction rutgon(Fraction a) {
    int gcd = uscln(a);
    a.numerator = a.numerator / gcd;
    a.denominator = a.denominator / gcd;
    return a;
}

Fraction Fraction::operator+(const Fraction& other) const {
    Fraction v;
    v.numerator = this->numerator * other.denominator + this->denominator * other.numerator;
    v.denominator = this->denominator * other.denominator;
    return rutgon(v);
}

Fraction Fraction::operator-(const Fraction& other) const {
    Fraction v;
    v.numerator = this->numerator * other.denominator - this->denominator * other.numerator;
    v.denominator = this->denominator * other.denominator;
    return rutgon(v);
}

Fraction Fraction::operator*(const Fraction& other) const {
    Fraction v;
    v.numerator = this->numerator * other.numerator;
    v.denominator = this->denominator * other.denominator;
    return rutgon(v);
}

Fraction Fraction::operator/(const Fraction& other) const {
    Fraction v;
    v.numerator = this->numerator * other.denominator;
    v.denominator = this->denominator * other.numerator;
    return rutgon(v);
}

bool Fraction::operator==(const Fraction& other) const {
    return this->numerator * other.denominator == other.numerator * this->denominator;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<=(const Fraction& other) const {
    return this->numerator * other.denominator <= other.numerator * this->denominator;
}

bool Fraction::operator>=(const Fraction& other) const {
    return this->numerator * other.denominator >= other.numerator * this->denominator;
}

bool Fraction::operator<(const Fraction& other) const
{
    return this->numerator * other.denominator < other.numerator * this->denominator;
}

ostream& operator<<(ostream& os, const Fraction& other) {
    os << other.numerator << "/" << other.denominator;
    return os;
}

istream& operator>>(istream& is, Fraction& other) {
    is >> other.numerator >> other.denominator;
    return is;
}