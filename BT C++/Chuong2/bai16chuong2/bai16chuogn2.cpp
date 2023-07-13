#include <iostream>
using namespace std;
int main(){
    int tnct;
    double luong,heso;
    if (tnct <12)
    {
        heso=1.92;
    }
    else if(12<=tnct<36){
        heso=2.34;
    }
    else if(36<=tnct<60){
        heso=2.34;
    }
    else
    {
        heso=4.5;
    }
    luong=heso*650000;
    cout<<"luong cua nhan vien:"<<luong;
}