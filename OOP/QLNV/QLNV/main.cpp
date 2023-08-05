#include "SalariedEmployee.h"
#include "Employee.h"
#include "Commission.h"
#include "BasePlusCommission.h"
#include <iomanip>
#include<vector>
#include <algorithm>
#include<iostream>
using namespace std;
int main() {
    srand(static_cast<unsigned int>(time(0)));
    vector<Employee*> employees;
    for (int i = 0; i < 10; ++i) {
        employees.push_back(new SalariedEmployee());
        employees.push_back(new Commission());
        employees.push_back(new BasePlusCommission());
    }
    for (int i = 0; i < employees.size(); i++)
    {
        employees[i]->print();
        cout << "Earning:" << employees[i]->earning() << endl;
        cout << "---------------------------------" << endl;
    }
    cout << "An 1 phim bat ki de sap xep:" << endl;
    system("pause");
    sort(employees.begin(), employees.end(), [](Employee *a, Employee *b) {
        return a->earning() > b->earning();
        });
    system("cls");
    cout << "Xem danh sach nhan vien sau khi sap xep:" << endl;
    for (int i = 0; i < employees.size(); i++)
    {
        employees[i]->print();
        cout << "Earning:" << employees[i]->earning() << endl;
        cout << "---------------------------------" << endl;
    }
}