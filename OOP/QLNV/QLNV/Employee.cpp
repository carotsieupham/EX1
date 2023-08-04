#include "Employee.h"

Employee::Employee(const string&first, const string&last, const string&ssn)
{
	this->firstname = first;
	this->lastname = last;
	this->Ssn = ssn;
}

void Employee::setFirstname(const string& first)
{
	firstname = first;
}

string Employee::getFirstname()
{
	return firstname;
}

void Employee::setLastname(const string& last)
{
	lastname = last;
}

string Employee::getLastname()
{
	return lastname;
}

void Employee::setSsn(const string&ssn)
{
	Ssn = ssn;
}

string Employee::getSsn()
{
	return Ssn;
}

void Employee::print()
{
	cout << getFirstname() << ' ' << getLastname()<<endl;
	cout << "Social security number:" << getSsn();
}
