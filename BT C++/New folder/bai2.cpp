#include <iostream>
#include <math.h>
using namespace std;
void kdq(int n){
    int s{0};
    for (int i = 0; i <=n; i++)
    {
        s+=3*i+pow(-1,i)*2;
    }
    cout<<"Tong cua t(n):"<<s<<endl;
}
int dq(int n){
    if(n==0) return 2;
    else return dq(n-1)+3*n +pow(-1,n)*2;
}
int main(){
    int n;
    cout<<"Nhap n:";cin>>n;
    kdq(n);
    
    cout<<"Tong t(n) de quy:"<<dq(n);
}