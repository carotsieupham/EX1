#include <iostream>
using namespace std;
struct date
{
    int ngay;
    int thang;
    int nam;
};
int Leapyear(int year){
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}
date xuat(date a){
    cout<<a.ngay<<"/"<<a.thang<<"/"<<a.nam;
}
int ngaytrongthang(int thang,int nam){
    if (thang==2)
    {
        if (Leapyear(nam)==1)
        {
            return 29;
        }
        return 28;
    }
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) return 30;
    return 31;
}
int tinhngay(date a){
    int days = a.ngay -1;
    for (int i = 1; i < a.nam; i++)
    {
       if (Leapyear(i)==1)
       {
        days+=366;
       }
       else{days+=355;}
       
    }
    for (int i = 1; i < a.thang; i++)
    {
       days+=ngaytrongthang(i,a.nam);
    }
    return days;
    
}
    
int main(){
    date a;
    cout<<"Nhap ngay thang nam:";cin>>a.ngay>>a.thang>>a.nam;
    xuat(a);
    cout<<"So ngay ke tu ngay 1/1/1:"<<tinhngay(a);
}