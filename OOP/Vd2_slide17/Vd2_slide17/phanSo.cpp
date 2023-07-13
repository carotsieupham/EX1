#include "phanSo.h"
#include <iostream>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
phanSo::phanSo(int tu=0, int mau=1) {
	this->tu = tu;
	this->mau = mau;
}
void phanSo::input(int tu, int mau){
	this->tu = tu;
	this->mau = mau;
}
void phanSo::print() {
	cout << this->tu << "/" << this->mau << endl;
}
phanSo phanSo::add( phanSo& b) {
	phanSo c;
	c.tu = this->tu * b.mau + b.tu * this->mau;
	c.mau = this->mau * b.mau;
	return c;
}void phanSo::minimum() {
	int g = gcd(tu, mau);
	tu /= g;
	mau /= g;
}