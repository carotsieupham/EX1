#pragma once
#include "BieuthucSohoc.h"
#include "BieuThucCong.h"
#include "BieuThucNhan.h"
#include "BieuThucTru.h"
class Dethi
{
private:
	vector<BieuthucSohoc>dethi;
public:
	void sinhDethi(int n1, int n2, int n3, int level);
	void start();
};

