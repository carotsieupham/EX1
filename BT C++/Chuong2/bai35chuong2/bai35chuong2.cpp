#include <iostream>
using namespace std;
int main(){
    int n,i,s{0};
    float avg;
    int a[100];
    for(i=0;i<10000;i++){
        cout<<"nhap so thu "<<i+1;cin>>a[i];
       
        if (a[i]==9999)
        {
            break;
        }
         s+=a[i];
    }
    avg=static_cast<float>(s)/static_cast<float>(i);
    cout<<"Trung binh:"<<avg;
        
}