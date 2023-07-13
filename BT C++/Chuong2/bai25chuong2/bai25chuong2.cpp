#include <iostream>
using namespace std;
int main(){
    int n;
    float tiendien;
    cout<<"Nhap so dien nha ban:";cin>>n;
    if(150>=n>100){
        tiendien=100*550+(n-100)*900;
    }
    else if(150<n<=200){
        tiendien=100*550+50*900+(n-150)*1250;
    }
    else if(200<n<=300){
        tiendien=100*550+50*900+50*1250+(n-200)*1450;
    }
    else if(300<n){
        tiendien=100*550+50*900+50*1250+100*1450+(n-300)*1700;
    }
    else{
        tiendien=n*550;
    }
    tiendien*=1.1;
    cout<<"Tien dien phai tra la:"<<tiendien;
}