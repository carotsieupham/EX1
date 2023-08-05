#include "Employee.h"

Employee::Employee()
{
	firstname = generateRandomString(2);
	lastname = generateRandomString(2);
	Ssn= generateRandomString(9)
}

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
string generateRandomString(int length) {

	static const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string result;

	for (int i = 0; i < length; ++i) {
		result += characters[rand() % (sizeof(characters) - 1)];
	}

	return result;
}