#pragma once
#include "Commission.h"
class BasePlusCommission:public Commission
{
private:
	double basesalary;
public:
	BasePlusCommission(const string&, const string&, const string&, double = 0.0, double = 0.0, double = 0.0);
	void setbasesalary(double);
	double getbasesalary();
	void print();
	double earning();
};

