#include <iostream>
#include <cmath>
using namespace std;
int giaithua(int n){
    int giai_thua=1;
    for (int i = 1; i <=n ; i++)
    {
        giai_thua*=i;
        
    }return giai_thua;
}
int main(){
    float x,sin,h;
    int n;
    cout<<"nhap x ";
    cin >> x;
    n=0;
    while (h=abs((pow(x,(2*n+1))/(giaithua(2*n+1))))>=0.000001)
    {
       sin+=pow((-1),n)*((pow(x,(2*n+1))/(giaithua((2*n+1)))));
       n++;
    }
    cout<<"sin(x)="<<sin;
}
        
    
    
    

    
