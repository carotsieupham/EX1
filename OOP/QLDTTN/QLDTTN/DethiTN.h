#pragma once
#include "CauhoiTN.h"
using namespace std;
class DethiTN
{
private:
	vector<CauhoiTN> dethi;
public:
	void create();
	void add();
	void print();
	void savefile(string filename);
	void readfile(string filename);
	void start();
	void deletesameqs();
};

