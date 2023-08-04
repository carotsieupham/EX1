#pragma once
#include"Employee.h"
class Commission:public Employee
{
private:
	double grossSales;
	double commissionRate;
public:
	Commission(const string&, const string&, const string&, double = 0.0, double = 0.0);
	void setgrossSales(double);
	double getgrossSales();
	void setcommissionRate(double);
	double getcommissionRate();
	virtual void print();
	virtual double earning();
};

