#pragma once
#include <vector>
#include "point.h"
#include <string>
#include <algorithm>

class listpoint
{
private:
	vector <point> list;
public:
	void readfile(string filename);
	void print();
	void sortlist();
};

