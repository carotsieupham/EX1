#include <iostream>
using namespace std;
const  float pi=3.14;
struct Circle
{
    float r;
    friend istream& operator>>(istream& is ,Circle &a){
        is>>a.r;
        return is;
    }
    
};
void ChuVi(Circle &a){
    float c;
    c=2*a.r*pi;
    cout<<"Chu vi cua hinh tron la:"<<c<<endl;
}
void DienTich(Circle &a){
    float c;
    c=a.r*a.r*pi;
    cout<<"Dien tich hinh tron:"<<c<<endl;
}
int main(){
    Circle a;
    cout<<"Nhap ban kinh hinh tron:";cin>>a;
    ChuVi(a);
    DienTich(a);
}