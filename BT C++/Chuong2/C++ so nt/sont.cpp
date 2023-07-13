#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    int i{2};
    int a;
    int flag{0};
    cout<<"nhap n=";
    cin>> n;
    while (i<=sqrt(n)){
        a=n%i;
        if (a==0){
            flag=1;
            break;
        }
        i++;

    }
    if (flag==1)
    {
        cout<<n<<" khong phai la so nt";
    }
    else{
        cout<<n<<" la so nt";
    }
    

}