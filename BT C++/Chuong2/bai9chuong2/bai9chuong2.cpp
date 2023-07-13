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
    float x,e,h;
    int n;
    cout<<"nhap x ";
    cin >> x;
    n=0;
    while (h=abs((pow(x,n)/(giaithua(n))))>=0.000001)
    {
       e+=(pow(x,n)/(giaithua(n)));
       n++;
        
    }
    
    cout<<"e^x="<<e;
    
    

}