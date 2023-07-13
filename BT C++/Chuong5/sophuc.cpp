#include <iostream>
#include <math.h>
using namespace std ;
struct sophuc
{
    int thuc;
    int ao;
    friend istream& operator>>(istream& is,sophuc &a){
        cout<<"Nhap phan thuc va ao cua so phuc";is>>a.thuc>>a.ao;
    }
    friend ostream& operator<<(ostream& os,sophuc &a){
        os<<a.thuc<<"+"<<a.ao<<"i"<<endl;
        return os;
    }
    friend sophuc operator+(sophuc a,sophuc b){
    sophuc c;
    c.thuc=a.thuc+b.thuc;
    c.ao=a.ao+b.ao;
    return c;}
    friend sophuc operator-(sophuc a,sophuc b){
    sophuc c;
    c.thuc=a.thuc-b.thuc;
    c.ao=a.ao-b.ao;
    return c;}
    friend sophuc operator*(sophuc a,sophuc b){
   
    sophuc c;
    c.thuc=(a.thuc*b.thuc-a.ao*b.ao);
    c.ao=(a.thuc*b.ao+b.thuc*a.ao);
    return c;}
};

float module(sophuc a){
    float c;
    c=sqrt(a.thuc*a.thuc+a.ao*a.ao);
    return c;
}
int main(){
    sophuc a,b,c;
    cout<<"So phuc a:"<<endl;
    cin>>a;
    cout<<"So phuc b:"<<endl;
    cin>>b;
    cout<<a;
    cout<<b;
    c=a+b;
    cout<<"cong so phuc"<<c;
    c=a-b;
}