#pragma once
#include <iostream>
using namespace std;

class BieuthucSohoc
{
protected:
	int a, b;
	char pheptoan; // +, -, *
public:
	BieuthucSohoc();
	friend ostream& operator<<(ostream& out, BieuthucSohoc bt);
	friend istream& operator>>(istream& in, BieuthucSohoc& bt);
	virtual void SinhBieuThuc(int level);
	bool KiemTra(int traloi);
	~BieuthucSohoc();
};

