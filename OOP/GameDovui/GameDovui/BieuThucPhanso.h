#pragma once
#include "Fraction.h"
#include "BieuthucSohoc.h"
class BieuThucPhanso:public BieuthucSohoc
{
private:
	Fraction a;
	Fraction b;
public:
	BieuThucPhanso(int level);
	friend ostream& operator<<(ostream& os, BieuThucPhanso& a);
	 bool ktrdapan();
};

