#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;
class sv
{
private:
	string mssv;
	string ht;
	int bv;
	float DiemTH;
	float DiemGK;

public:
	string get_name();
	friend istream& operator>>(istream& is, sv& sv);
	friend ostream& operator<<(ostream& os, sv& sv);
	float TinhDiemQT();
	void hienthiTTSV();
	void ghifile(ofstream& ofs);
	void docfile(ifstream& ifs);
	friend bool trungten(sv sv1, sv sv2);
};
