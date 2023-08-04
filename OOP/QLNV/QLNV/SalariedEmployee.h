#pragma once
#include "Employee.h"
class SalariedEmployee:public Employee
{
private:
	double weeksalary;
public:
	SalariedEmployee(const string&, const string&, const string&,  double = 0.0);
	void setweeklysalary(double ws);
	double getweeksalary();
	void print();
	double earning();
};

