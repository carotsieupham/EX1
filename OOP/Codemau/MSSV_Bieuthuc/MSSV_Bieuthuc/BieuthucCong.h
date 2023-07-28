#pragma once
#include "BieuthucSohoc.h"
class BieuthucCong :
	public BieuthucSohoc
{
public:
	//overide ham sinh bieu thuc de chi sinh phep toan +
	void SinhBieuThuc(int level);
	friend istream& operator>>(istream& in, BieuthucCong& bt);
};

