#include "listpoint.h"
#include"point.h"
#include<iostream>
using namespace std;
int main() {
	listpoint l;
	l.readfile("data.txt");
	cout << "Danh sach truoc khi sap xep:";
	l.print();
	l.sortlist();
	cout << "Danh sach sau khi sap xep:";
	l.print();
}