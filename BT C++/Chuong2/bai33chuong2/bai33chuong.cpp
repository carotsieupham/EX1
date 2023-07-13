#include <iostream>
using namespace std;
int main(){
int n;
cout<<"Nhap n: ";
cin>>n;
cout<<n<<" = ";
int i= 2;
while(i <= n)
{
if(n % i == 0){
cout<<i;
n /= i;
if(n != 1) cout<<"*";
}
else i++;
}
}