#include <iostream>
#include <math.h>
using namespace std;
float Can(int n){
    double s;
    if(n==1){return s=sqrt(3);}
    return sqrt(3+Can(n-1));

}
int main(){
    int n;
    cout<<"Nhap so dau can:";cin>>n;
    cout<<Can(n);
    
}