#include <iostream>
using namespace std;
int main(){
    double a,b,c;
    cout<<"Nhap lan luot 3 so:";cin>>a>>b>>c;
    if (a>b)
    {   if (a>c)
    {
        cout<<"So lon nhat la:"<<a<<endl;
        if (b>c)
        {
            cout<<"So be nhat la:"<<c<<endl;
        }
        else{
            cout<<"So be nhat la:"<<b<<endl;
        }
        
    }else{
        cout<<"So lon nhat la:"<<c;
    }
    }
    else if (b>a){
        if(b>c){
           cout<<"So lon nhat la:"<<b<<endl; 
           if (a>c)
        {
            cout<<"So be nhat la:"<<c<<endl;
        }
        else{
            cout<<"So be nhat la:"<<a<<endl;
        }
        }
        else
        {
             cout<<"So lon nhat la:"<<c<<endl; 
        }
    }
    else
    {

        if (a>c)
        {
            cout<<"So lon nhat la:"<<a<<endl;
             cout<<"So be nhat la:"<<c<<endl;
        }
        
    }
        
    
}