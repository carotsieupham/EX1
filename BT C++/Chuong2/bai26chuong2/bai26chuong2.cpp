#include <iostream>
using namespace std;
int main(){
    int maso,luongX,luongY,doanhsoZ,n,s,luong,giolamviec;
    do
    {cout<<"Nhap ma so(1,2,3,4):";cin>>maso;
    } while (0>maso>4);
    
    
    if (maso==1)
    {
        cout<<"Nhap luong cua ban";cin>>luongX;
        cout<<"Luong ban nhan duoc tuan nay la:"<<luongX;
    }
    else if (maso==2)
    {   cout<<"Nhap luong co ban";cin>>luongY;
        cout<<"Nhap so gio lam viec trong tuan:";cin>>giolamviec;
        if(giolamviec<=40){
            luong=luongY*giolamviec;
            cout<<"Luong ban nhan duoc tuan nay la:"<<luong;
        }
        else
        {
            luong=40*luongY+(giolamviec-40)*luongY*1.5;
            cout<<"Luong ban nhan duoc tuan nay la:"<<luong;
        }
        
    }
     else if (maso==3)
    {   cout<<"Nhap doanh so kiem duoc trong tuan";cin>>doanhsoZ;
        luong=500000+0.7*doanhsoZ;
        cout<<"Luong ban nhan duoc tuan nay la:"<<luong;
    }
     else if (maso==4)
    { 
        cout<<"Nhap so san pham  lam ra:";cin>>n;
        cout<<"Nhap so tien nhan duoc cho moi san pham:";cin>>s;
        luong=n*s;
        cout<<"Luong ban nhan duoc tuan nay la:"<<luong;
    }
   
    
    
}