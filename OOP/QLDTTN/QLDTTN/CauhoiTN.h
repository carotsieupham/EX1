#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class CauhoiTN
{
private:
	string noidung;
	string cauA;
	string cauB;
	string dapan; //'A' hoac 'B'
public:
	void nhap();
	void docfile(ifstream& f);
	void ghifile(ofstream& f);
	bool kiemtra();
	void xuat();
	friend bool giongnhau(CauhoiTN cau1, CauhoiTN cau2);

};

