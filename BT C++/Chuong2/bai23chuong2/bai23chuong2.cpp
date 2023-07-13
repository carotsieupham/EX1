#include<iostream>  
using namespace std;
int main(){
    float TS1,MS1,TS2,MS2;
    do
    {
        cout<<"Nhap tu so cua phan so thu nhat:";cin>>TS1;
        cout<<"Nhap mau so so cua phan so thu nhat:";cin>>MS1;
        cout<<"Nhap tu so cua phan so thu hai:";cin>>TS2;
        cout<<"Nhap mau so so cua phan so thu hai:";cin>>MS2;
    } while (MS1==0 && MS2==0);
    cout<<"Tong 2 phan so:"<<float(((TS1*MS2)+(TS2*MS1))/(MS2*MS1))<<endl;
    cout<<"Hieu 2 phan so:"<<float(((TS1*MS2)-(TS2*MS1))/(MS2*MS1))<<endl;
    cout<<"Tich 2 phan so:"<<float(((TS1*TS2)/(MS2*MS1)))<<endl;
    cout<<"Thuong 2 phan so:"<<float(((TS1*MS2)/(MS1*TS2)))<<endl;

    
   

}