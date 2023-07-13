#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n,i,p{0};
    long long h{0};
    cout<<"nhap so ";
    cin >> n;
    while(n<0){
      cout<<"Nhap lai :";cin>>n;
    }
    
    while(n>0){
        h+=(n%2)*pow(10,p);
        p++;
        n/=2;
    }
    cout<<"so nhi phan cua so vua nhap la:"<<h;


   
}