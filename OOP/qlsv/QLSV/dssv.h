#pragma once
#include "sv.h"
class dssv
{
private:
	vector<sv> dssv;
public:
	void create();
	void add();
	void print();
	void danhSachSvDuDk();
	void danhSachSvHoNguyen();
	void danhSachSvCungTen();
	void savefile(string filename);
	void readfile(string filename);
};

