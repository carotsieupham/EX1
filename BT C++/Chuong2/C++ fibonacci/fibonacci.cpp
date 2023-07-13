#include <iostream>

using namespace std;

int main(){
  
    int n;
    int f1{1};
    int f2{1};
    int fn{0};
    cout<<"nhap n=";
     cin >>n ;
 while (n>=1){
    if(n==1||n==2)
    {cout<<f1;
    }
    
    else{
         for(int i{3};i < n+1;i++) {
                 fn=f1+f2;
                 f1 = f2;
                 f2=fn;}
    cout<<fn;
    break;
    }}
while(n<1){
    cout<<"nhap lai n=";
    cin>>n;
}
    
    
    return 0;
}