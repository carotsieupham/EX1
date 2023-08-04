#include "SalariedEmployee.h"
#include "Employee.h"
#include "Commission.h"
#include "BasePlusCommission.h"
#include <iomanip>
#include<vector>
#include <algorithm>

#include<iostream>
using namespace std;
string generateRandomString(int length) {

    static const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result;

    for (int i = 0; i < length; ++i) {
        result += characters[rand() % (sizeof(characters) - 1)];
    }

    return result;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    vector<Employee*> employees;
    for (int i = 0; i < 10; ++i) {
        employees.push_back(new SalariedEmployee(generateRandomString(2), generateRandomString(2), generateRandomString(9), static_cast<double>(rand() % 10000 + 1000)));
        employees.push_back(new Commission(generateRandomString(2), generateRandomString(2), generateRandomString(9), static_cast<double>(rand() % 100000 + 10000), static_cast<double>(rand()) / RAND_MAX));
        employees.push_back(new BasePlusCommission(generateRandomString(2), generateRandomString(2), generateRandomString(9), static_cast<double>(rand() % 100000 + 10000), static_cast<double>(rand()) / RAND_MAX, static_cast<double>(rand() % 5000 + 1000)));
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