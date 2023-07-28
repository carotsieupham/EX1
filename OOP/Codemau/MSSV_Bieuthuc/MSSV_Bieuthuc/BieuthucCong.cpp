#include "BieuthucCong.h"
#include "BieuthucSohoc.h"
#include <iostream>
using namespace std;

void BieuthucCong::SinhBieuThuc(int level)
{
	BieuthucSohoc::SinhBieuThuc(level);//Goi lai phuong thuc lop cha
	pheptoan = '+';// chi phep toan +
}

istream& operator>>(istream& in, BieuthucCong& bt)
{
	in >> bt.a >> bt.pheptoan >> bt.b;
	if (bt.pheptoan != '+')
	{
		cout << "Dieu chinh tu dong thanh phep toan +!!!\n";
		bt.pheptoan = '+';
	}
	return in;
}
