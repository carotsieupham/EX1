#include <iostream>
using namespace std;
#include <math.h>
int main(){
    double s,u ;
    int i,n;
    u=0;
    cout<<"nhap n ";
    cin >> n;
    for ( i = 1; i < n+1; i++)
    {   u=u+i*i;
        
    }
    s=sqrt(u);
    cout<<"ket qua"<<s;
}