#pragma once
#include <iostream>
#include <string>
using namespace std;
class Employee
{
protected:
	string firstname, lastname;
	string Ssn;
public:
	friend string generateRandomString(int length);
	Employee();
	Employee(const string&, const string&, const string&);
	void setFirstname(const string&);
	string getFirstname();
	void setLastname(const string&);
	string getLastname();
	void setSsn(const string&);
	string getSsn();
	virtual double earning()=0;
	virtual void print();
};

