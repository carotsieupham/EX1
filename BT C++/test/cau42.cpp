#include<iostream>
using namespace std;
#include <math.h>
int tong(int n, int k){
    int s{0},digit;
    for(n;n>0;n/=10){
        digit=n%10;
        if (digit % k == 0){
            s+=digit;
        }
        
    }
    return s;
}
int tongdq(int n,int k){
    int digit;
    if(n==0){
        return 0;
    }
    else{
        digit=n%10;
        if(digit%k == 0){
            return digit +tongdq(n/10,k);

        }
        else{
            return tongdq(n/10,k);
        }
    }
}
    

int main(){
int n,k;
cout<<"Nhap so nguyen n va k:";cin>>n>>k;
cout<<tong(n,k)<<endl;
cout<<tongdq(n,k)<<endl;
}