#include "BasePlusCommission.h"

BasePlusCommission::BasePlusCommission(const string& first, const string& last, const string& ssn, double gsl, double cmr,double bsl):Commission(first,last,ssn,gsl,cmr)
{
	setbasesalary(bsl);
}

void BasePlusCommission::setbasesalary(double bsl)
{
	if (bsl >= 0.0) basesalary = bsl;
	else
		throw invalid_argument("Based salary must be >= 0.0");
}

double BasePlusCommission::getbasesalary()
{
	return basesalary;
}

void BasePlusCommission::print()
{
	cout << "Base Plus Commission Employee:";
	Commission::print();
	cout << "Base Salary:" << basesalary<<endl;
}

double BasePlusCommission::earning()
{
	return Commission::earning()+getbasesalary();
}
