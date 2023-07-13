#include <iostream>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int countDays(Date date) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(date.year)) {
        daysInMonth[1] = 29;
    }
    int days = date.day;
    for (int i = 0; i < date.month - 1; i++) {
        days += daysInMonth[i];
    }
    for (int i = 2000; i < date.year; i++) {
        days += isLeapYear(i) ? 366 : 365;
    }
    return days;
}

int main() {
    Date date ;
    cout<<"Nhap ngay,thang,nam:";cin>>date.day>>date.month>>date.year;
    int days = countDays(date);
    int wday = (days - countDays({1, 1, 2000})) % 7;
    string daysOfWeek[] = {"Thu Bay", "Chu Nhat", "Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau"};
    cout << date.day << "/" << date.month << "/" << date.year << " la: " << daysOfWeek[wday] << endl;
    return 0;
}