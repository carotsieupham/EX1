#include<iostream>
using namespace std;
int main(){
    float a[100][100],s{0};
    int m,n,i,j;
    cout<<"Nhap lan luot so hang va cot:";cin>>m>>n;
    for ( i = 1; i <= m; i++)
    {for ( j = 1; j <= n; j++)
    {
        cout<<"a["<<i<<"]"<<"["<<j<<"]";cin>>a[i][j];
    }
    }
    for ( i = 1; i <= m; i++)
    {for ( j = 1; j <= n; j++)
    {
        if (j%2==0)
        {
            s+=a[i][j];
        }
        
    }
    }
    cout<<"Tong cac cot chan trong mang:"<<s<<endl;
    s=0;
    for ( i = 1; i <= m; i++)
    {for ( j = 1; j <= n; j++)
    {
        if(i==1|| i==m||j==1||j==n){
            if ((i==1&&j==1)||(i==m&&j==n||i==1&&j==n||i==m&&j==1)){
                a[i][j]*=2;
            }
           s+= a[i][j];
        }
    }
}
cout<<"Tong cac so tren canh cua A:"<<s;
}
