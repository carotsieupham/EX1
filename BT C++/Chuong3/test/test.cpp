#include <iostream>
using namespace std;

int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int BCNN(int a, int b) {
    return (a * b) / UCLN(a, b);
}

int main() {
    int num1, num2;
    cout << "Nhập số nguyên dương thứ nhất: ";
    cin >> num1;
    cout << "Nhập số nguyên dương thứ hai: ";
    cin >> num2;

    if (num1 <= 0 || num2 <= 0) {
        cout << "Vui lòng nhập số nguyên dương." << endl;
    } else {
        int bcnn = BCNN(num1, num2);
        cout << "Bội chung nhỏ nhất của " << num1 << " và " << num2 << " là: " << bcnn << endl;
    }

    return 0;
}
