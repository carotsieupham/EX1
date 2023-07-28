#pragma once
#include<iostream>
#include <cstdlib>
#include <ctime>
#include<random>
#include <string>
using namespace std;
class BieuthucSohoc
{
protected:
	string pheptoan;
	int a, b;
public:
	BieuthucSohoc();
	BieuthucSohoc(int n);
	friend istream& operator>>(istream& is, BieuthucSohoc& a);
	friend ostream& operator<<(ostream& os, BieuthucSohoc& a);
	virtual bool ktrdapan();
};

