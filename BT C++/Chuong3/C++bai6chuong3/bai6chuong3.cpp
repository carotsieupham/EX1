#include <iostream>
using namespace std;
#include <math.h>
int giaithua(int n){
    if(n==1 or n==0){return 1;}
    if (n==2)
    {return 2;
        }
    if(n>2){return giaithua(n-1)*n;}    
}
int C(int k, int n) {
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    return C(k - 1, n - 1) + C(k, n - 1);
}
float NhithucNT(int k,int n){
    
    float t;
    t=C(k-1,n)*pow(1,(n-(k-1)))*pow(1,k-1);
    return t;
    }
int main(){
    int n,k,i,j ;
    float a,b;
    cout<<"So can tim giai thua:";
    cin>>n;
    cout<<"Giai thua cua"<<n<<":"<<giaithua(n)<<endl;
    cout<<"Nhap k:";cin>>k;
    while(k<=n){
        cout<<"To hop chap"<<k<<"cua"<<n<<"la:"<<C(k,n);
        break;
    }
    while(k>n){
        cout<<"Nhap lai k";cin>>k;
    }
    cout<<endl;
    
    cout<<"He so cua so hang thu"<<k<<NhithucNT(k,n);
    cout<<endl;
    for ( i = 0; i < n; i++)
    { for (int j = n; j > i; j--)
 cout << " ";
        for(j=0;j<=i;j++){
        cout<<C(j,i)<<" ";
    }
        cout<<endl;
    }
    return 0;
    
}
