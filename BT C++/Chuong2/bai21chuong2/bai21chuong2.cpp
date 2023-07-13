#include <iostream>
using namespace std;
int main(){
    double n;
    cout<<"Nhap diem cua hoc sinh:";cin>>n;
    if (n>=8)
    {
        cout<<"Hoc luc gioi";
    }
    else if (6.5<=n<8)
    {
       cout<<"Hoc luc kha";
    }
     else if (5<=n<6.5)
    {
       cout<<"Hoc luc trung binh";
    }
    else{
        cout<<"Hoc luc yeu";
    }
}