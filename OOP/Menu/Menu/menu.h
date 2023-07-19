#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class menu
{
private:

	vector<string> dsLuachon;
public:
 menu& operator<<(const string& option);
 void xuat();
 int chon();
};

