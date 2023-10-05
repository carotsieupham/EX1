#pragma once
#include<iostream>
using namespace std;
class polynomialTerm
{
private:
	int heso;
	int somu;
	polynomialTerm* p;
public:
	polynomialTerm(int heso, int somu);
	int getheso();
	int getsomu();
	polynomialTerm* getpointer();
	void setheso(int heso);
	void setsomu(int somu);
	void setpointer(polynomialTerm* p);
};

