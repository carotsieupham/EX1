#include "BieuthucSohoc.h"
#include <iostream>
#include <time.h>
using namespace std;

BieuthucSohoc::BieuthucSohoc()
{
	a = b = 1;
	pheptoan = '+';   
}

void BieuthucSohoc::SinhBieuThuc(int level)
{
	//sinh a, b
	if (level <= 3) //sinh so hang trong khoang 1-10
	{
		a = 1 + rand() % 10;
		b = 1 + rand() % 10;
	}
	else
	{
		a = 10 + rand() % 100;
		b = 10 + rand() % 100;
		if (a > 100) a = 100;
		if (b > 100) b = 100;
	}
	//sinh phep toan
	char dspt[] = { '+', '-', '*' };
	if (level == 1)
		pheptoan = '+';
	else if (level == 2 || level == 4)
	 //hoac + hoac -
		pheptoan = dspt[rand() % 2];
	else
	  // +, -, *
		pheptoan = dspt[rand() % 3];
}

bool BieuthucSohoc::KiemTra(int traloi)
{
	int dapan = a;
	switch (pheptoan)
	{
	case '+': dapan = a + b;
		break;
	case '-': dapan = a - b;
		break;
	case '*':dapan = a * b;
		break;
	}
	return (traloi == dapan);
}

BieuthucSohoc::~BieuthucSohoc()
{
}

ostream& operator<<(ostream& out, BieuthucSohoc bt)
{
	// 2 + 3 = ?
	out << bt.a << bt.pheptoan << bt.b << "= ?";
	return out;
}

istream& operator>>(istream& in, BieuthucSohoc& bt)
{
	cout << " Nhap bieu thuc (vi du 2 + 3): ";
	in >> bt.a >> bt.pheptoan >> bt.b;
	return in;
}
