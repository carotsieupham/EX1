#include "Commission.h"

Commission::Commission(const string& first, const string& last, const string& ssn, double gsl, double cmr):Employee(first,last,ssn)
{
	setgrossSales(gsl);
	setcommissionRate(cmr);
}

void Commission::setgrossSales(double gsl)
{
	if (gsl >= 0.0) grossSales = gsl;
	else
		throw invalid_argument("Gross sales must be >= 0.0");
}

double Commission::getgrossSales()
{
	return grossSales;
}

void Commission::setcommissionRate(double rate)
{
	if (rate > 0.0 && rate< 1.0) commissionRate = rate;
	else
		throw invalid_argument("Commission Rate must be > 0.0 and <1.0");
}

double Commission::getcommissionRate()
{
	return commissionRate;
}

void Commission::print()
{
	cout << "Commission Employee:";
	Employee::print();
	cout << endl;
	cout << "Gross sales:" << grossSales<<endl;
	cout << "Commission Rate:" << commissionRate<<endl;
}

double Commission::earning()
{
	return grossSales * commissionRate;
}
