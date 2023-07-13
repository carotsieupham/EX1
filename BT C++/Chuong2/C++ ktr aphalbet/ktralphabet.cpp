#include <iostream>
using namespace std;
int main(){
    char kytu;
    cout<<"nhap chu cai ";
    cin.get(kytu) ;
    if (kytu >= 'a' && kytu <='z')
    {
        cout<<" chu cai thuong ";
    }
    else if (kytu >='A' && kytu <='Z')
    {
        cout<<"chu cai in hoa";

    }
    else
    {
        cout<<"khong phai chu cai";
    }
    
    
    
}