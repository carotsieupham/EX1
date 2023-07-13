#include <iostream>
#include <iomanip>
using namespace std;
#include <math.h>
int main(){

    int n,i,p{0},z;
    long long h{0};
    cout<<"nhap so ";
    cin >> n;
    n=z;
    while(n<0){
      cout<<"Nhap lai :";cin>>n;
    }
    while(n>0){
        h+=(n%2)*pow(10,p);
        p++;
        n/=2;
    }
    cout<<"He 10:"<<std::dec<<z<<endl;
    cout<<"so nhi phan cua so vua nhap la:"<<h<<endl;
    cout<<"he 8:"<<std::oct<<z<<endl;
    cout<<"he 16:"<<std::hex<<z<<endl;
}


   
