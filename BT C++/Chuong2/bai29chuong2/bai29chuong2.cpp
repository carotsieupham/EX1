#include <iostream>
using namespace std ;
int main(){
    int n ,gt{1},h;
    cout<<"Nhap n:";cin>>n;
    if (n%2==1)
    {
       h=1;
    }else
    {
        h=2;
    }
    for(int i = h; i <= n; i += 2) {
    gt *= i;}
    cout<<"Ket qua:"<<gt;
}
    
    