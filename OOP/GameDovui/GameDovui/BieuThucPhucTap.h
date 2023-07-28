#pragma once
#include "BieuthucSohoc.h"
class BieuThucPhucTap:public BieuthucSohoc
{
private:
	int random_bt;
public:
	BieuThucPhucTap();
	friend ostream& operator<<(ostream& os, BieuThucPhucTap& a);
	bool ktrdapan();
};

