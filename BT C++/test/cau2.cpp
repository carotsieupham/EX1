#include <iostream>
using namespace std;
#include<math.h>
int main(){
    int a[100],n,s{1},x,h;
    cout<<"Nhap so nguyen can nhap vao mang:";cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Nhap so thu "<<i+1<<":";cin>>a[i];
    }
   for (int i = 0; i < n; i++)
   {    if(a[i]>99 && a[i]<1000 && a[i]%2==0 ){
            
            
               s*=a[i];
            }
   }
            
        
    cout<<"Tich cua cac so co ba chu so trong mang la:"<<s<<endl;
   cout<<"Nhap X=";cin>>x;
    for(int i=0;i<n;i++){
        h=a[i];
        while(h>0){
            
            if(h%10==x){
                cout<<a[i]<<",";
                break;
            }
            h/=10;
        }
    }

}