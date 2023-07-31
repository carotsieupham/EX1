#pragma once
#include "sv.h"
#include <set>
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

