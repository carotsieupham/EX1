#include <iostream>
using namespace std;
struct date
{
    int day;
    int month;
    int year;
};
int ngaytrongthang(int thang,int nam){
    if (thang==2)
    {
        
        return 28;
    }
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) return 30;
    return 31;
}
int tinhngay(date a){
    int days = a.day -1;
    
    for (int i = 1; i < a.month; i++)
    {
       days+=ngaytrongthang(i,a.year);
    }
    return days;
    
}
int main(){
    date a={9,4,2023};
    cout<<tinhngay(a);
}