#include <iostream>
using namespace std;
int main(){
    float n1,n2,n3,avg;
do
{
    cout<<"Nhap diem trung binh cua hs thu nhat";cin>>n1;
    
   
} while (10<n1<0);
do
{
    cout<<"Nhap diem trung binh cua hs thu hai";cin>>n2;
} while (10<n2<0);
do
{
     cout<<"Nhap diem trung binh cua hs thu ba";cin>>n3;
} while (10<n3<0);

    
    avg=(n1+n2+n3)/3;
    cout<<"Diem trung binh tat ca sinh vien"<<avg;


}