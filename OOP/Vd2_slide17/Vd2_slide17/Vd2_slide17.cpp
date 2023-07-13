
#include <iostream>
#include"phanSo.h"
using namespace std;
int main()
{
	phanSo a(3, 15), b(4, 3);
	a.minimum();
	a.print();
	b.minimum();
	b.print();
	(a.add(b)).minimum();
	(a.add(b)).print();
}

