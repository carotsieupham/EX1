#include <iostream>
#include "Point.h"
#include <string>
#include <random>
#include "Point.cpp"
#include <algorithm>
#include<vector>
using namespace std;

template <class T>
void hoanvi(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
T generateRandomNumber(T min, T max) {
    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<T> distribution(min, max);
    return distribution(gen);
}

int main() {
    int a = 5, b = 6;
    cout << "Chua hoan vi a:" << a << ",b:" << b << endl;
    hoanvi(a, b);
    cout << "Sau hoan vi a:" << a << ",b:" << b << endl;
    float c = 0.5, d = 0.1;
    cout << "Chua hoan vi c:" << c << ",d:" << d << endl;
    hoanvi(c, d);
    cout << "Sau hoan vi c:" << c << ",d:" << d << endl;
    vector<Point<int>*> lsp; // Chú ý sử dụng vector con trỏ
    for (int i = 0; i < 20; i++) {
        int min = 0, max = 100;
        Point<int>* p = new Point<int>(generateRandomNumber(min, max), generateRandomNumber(min, max));
        lsp.push_back(p);
    }
    for (int i = 0; i < lsp.size(); i++) {
        cout << *lsp[i] << ",";
    }
    cout << endl;
    cout << "Danh sach sau khi sap xep:" << endl;
    sort(lsp.begin(), lsp.end(), [](Point<int>* a, Point<int>* b) {
        return a->distance() < b->distance();
        });
    for (int i = 0; i < lsp.size(); i++) {
        cout << *lsp[i] << ",";
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < lsp.size(); i++) {
        delete lsp[i];
    }

}
