#include <iostream>
using namespace std;
int main(){
    int n1,n2,i;
    cout<<"Nhap so thu nhat:";cin>>n1;
    cout<<"Nhap so thu hai:";cin>>n2;

    if(n1>n2){
    for ( i = n1; i >=1; i--)
    {if(n1%i==0 && n2%i==0){
        cout<<"UCLN"<<"("<<n1<<","<<n2<<")="<<i<<endl;
        break;
    for ( i = n1; i <=n1*n2; i++)
    { if (i%n1==0 && i%n2==0)
    {
        cout<<"BCNN"<<"("<<n1<<","<<n2<<")="<<i<<endl;
        break;
    }
    }
    
    }        
    }
    }
    else if (n2>n1)
    {
        for ( i = n2; i >=1; i--)
    {if(n1%i==0 && n2%i==0){
        cout<<"UCLN"<<"("<<n1<<","<<n2<<")="<<i<<endl;
        break;
    }        
    }
    for ( i = n2; i <=n1*n2; i++)
    { if (i%n1==0 && i%n2==0)
    {
        cout<<"BCNN"<<"("<<n1<<","<<n2<<")="<<i<<endl;
        break;
    }
    }
    }
    else{
                cout<<"UCLN"<<"("<<n1<<","<<n2<<")="<<n1<<endl;
                cout<<"BCNN"<<"("<<n1<<","<<n2<<")="<<n1<<endl;
    }
    
    

    
    
}
    
        