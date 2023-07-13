#include <iostream>
#include <math.h>
using namespace std;
bool ktrsochingphuong(int n ){
    if(sqrt(n)*sqrt(n)==n){return true;}
    return false;
}
int demsochinhphuongtrenduongcheochinh(int a[][10],int n){
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if(ktrsochingphuong(a[i][i])){count++;}
    }
    return count;
}
int main(){
    int a[10][10];
    int n;
    cout<<"Nhap kich thuoc ma tran vuong nxn:";cin>>n;
    for(int i =0;i<n;i++)
    {   for(int j=0;j<n;j++){
         cout << "a[" << i << "][" << j << "]:";cin>>a[i][j];}
    } 
    cout<<"So luong so chinh phuong tren duong cheo chinh:"<<demsochinhphuongtrenduongcheochinh(a,n);
}