#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee(const string& first, const string& last, const string& ssn, double salary):Employee(first, last, ssn) {
    setweeklysalary(salary);
}

void SalariedEmployee::setweeklysalary(double ws)
{
    if (ws >= 0.0)weeksalary = ws;
    else
        throw invalid_argument("Weekly salary must be >= 0.0");
}

double SalariedEmployee::getweeksalary()
{
    return weeksalary;
}

void SalariedEmployee::print()
{
    cout << "Salaried employee:";
    Employee::print();
    cout << endl;
    cout << "salary:" << getweeksalary()<<endl;
}

double SalariedEmployee::earning()
{
    return getweeksalary();
}
