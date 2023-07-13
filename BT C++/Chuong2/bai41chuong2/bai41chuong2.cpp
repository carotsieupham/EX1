#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    int n,a,b,i{1};
   srand(time(NULL));
   cout<<"nhap cho so:";cin>>n;cout<<endl;
    a=rand()%(101);
    cout<<"May doan:"<<a<<endl;
    /*a*/
    do
    {
        if(a<n){
        cout<<"tim so lon hon"<<endl;
        a=rand()%(100-a+1)+a;
        cout<<"so khac:"<<a<<endl;
        }
        else if(n<a){
        cout<<"tim so be hon"<<endl;
        a=rand()%(a-1+1)+1;
        cout<<"so khac:"<<a<<endl;
        } 
       if (n==a)
       {
        cout<<"ban da doan dung so:"<<n;
       }
        i++;}
    while (n!=a && i<=15);
    if(a!=n){
        cout<<"may da thua"<<endl;
    }
    cout<<"-------------------------------"<<endl;
     /*b*/  
    a=rand()%101;
    i=1;
    cout<<"Ban doan:";cin>>n;
    do
    {
        if(n<a){
        cout<<"tim so lon hon"<<endl;
        cout<<"Hay doan so khac:";cin>>n;
        }
        else if(a<n){
        cout<<"tim so be hon"<<endl;
        cout<<"Hay doan so khac:";cin>>n;
        } 
       if (n==a)
       {
        cout<<"ban da doan dung so:"<<n;
       }
        i++;}
    while (n!=a && i<=15);
    if(a!=n){
        cout<<"Ban da thua";
    }
}