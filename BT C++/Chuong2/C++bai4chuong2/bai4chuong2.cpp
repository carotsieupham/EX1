#include <iostream>
using namespace std;
int main(){
    int day;
    cout<<"Nhap ngay cua thang 2:";cin>>day;
    while(day<1&&day>29){
        cout<<"Nhap lai";cin>>day;
    }
    switch (day)
    {
    case 6:
    case 13:
    case 20:
    case 27:
     cout<<"Thu 2";
        break;
     case 7:
    case 14:
    case 21:
    case 28:
     cout<<"Thu 3";
        break;   
    case 1:
    case 8:
    case 15:
    case 22:
     cout<<"Thu 4";
        break;
    case 2:
    case 9:
    case 16:
    case 23:
     cout<<"Thu 5";
        break;   
    case 3:
    case 10:
    case 17:
    case 24:
     cout<<"Thu 6";
        break;
    case 4:
    case 11:
    case 18:
    case 25:
     cout<<"Thu 7";
        break; 
    case 5:
    case 12:
    case 19:
    case 26:
     cout<<"Chu Nhat";
        break;   
    default:cout<<"Thang nay khong co ngay do";
        break;
    }
}