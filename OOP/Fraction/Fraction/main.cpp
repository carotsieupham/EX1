#include "fraction.h"
#include <vector>
#include <set>

int main() {
    int n;
    fraction f1(1,2), f2(2,3);
    cout << "Nhap n: ";
    cin >> n;
    cout << "Cong phan so:" <<f1+f2<< endl;
    cout << "Tru phan so:" << f1 - f2 << endl;
    cout << "Nhan phan so:" << f1 * f2 << endl;
    cout << "Chia phan so:" << f1 / f2 << endl;
    vector<fraction> frac;
    for (int i = 0; i < 100; i++) {
       
        fraction* fr=new fraction(n);
        if (*fr <= fraction(1, 2)) {
            frac.push_back(*fr);
        }
        
    }

    cout << "Danh sach phan so nho hon 1/2" << endl;
    for (int i = 0;i < frac.size();i++) {
        cout << rutgon(frac[i]) << " ";
    }
    cout << endl;

    set<fraction> uniquefrac(frac.begin(), frac.end());
    cout << "Danh sach phan so khong trung" << endl;
    for (auto it = uniquefrac.begin(); it != uniquefrac.end(); ++it) {
        cout << rutgon(*it) << " ";
    }

    return 0;
}