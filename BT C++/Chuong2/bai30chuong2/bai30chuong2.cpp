#include <iostream>
using namespace std;
int main(){
    int n,j; 
    double long s{0},f;
    cout<<"Nhap n:";cin>>n;
    cout<<"s=1+2+3+4+...+n";
    for(int i =0;i<=n;i++){
        s+=i;
    }
     cout<<"Ket qua"<<s<<endl;
    cout<<"s=1+3+5+7+...+(2*n+1)";
    s=0;
    for (int i = 0; i <=n; i++)
    {
        s+=(2*i+1);
    }
    cout<<"Ket qua"<<s<<endl;
    cout<<"s=n!"<<endl;
    s=1;
    for (int i = 1; i <=n; i++)
    {
        s*=i;
    }
    cout<<"Ket qua"<<s<<endl;
    cout<<"s=1/(2*3)+1/(3*4)+1/(4*5)+...+1/n*(n+1)"<<endl;
    s=0;
    j=2;
    while(j<=n){
        f=static_cast<float>(1)/static_cast<float>(j*j+j);
        s+=f;
        j++;
    }
     cout<<"Ket qua"<<s<<endl;

    return 0;
}
