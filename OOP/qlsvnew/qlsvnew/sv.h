#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <Windows.h>
using namespace std;
void gotoXY(int x, int y);
void box(int x, int y, int h, int w);
class sv
{
private:
	string mssv;
	string hodem;
	string ten;
	int bv;
	float DiemTH;
	float DiemGK;
public:
	friend void gotoXY(int x, int y);
	friend void box(int x, int y, int h, int w);
	string get_familyname();
	string get_name();
	friend istream& operator>>(istream& is, sv& sv);
	friend ostream& operator<<(ostream& os, sv& sv);
	float TinhDiemQT();
	void hienthiTTSV(int &index);
	void ghifile(ofstream& ofs);
	void docfile(ifstream& ifs);
	friend bool trungten(sv sv1, sv sv2);
	
};
