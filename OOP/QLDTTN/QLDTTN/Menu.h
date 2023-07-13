#pragma once
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Menu
{
private:
	vector<string> menu;
public:
	void add_item(string item);
	void print_menu();
	int choose();

};

