#include <iostream>
#include <math.h>
using namespace std;
struct diem
{
    float x;
    float y;
};

struct vecto
{
    diem dau ;
    diem cuoi;
};
float dodaivecto(vecto a){
    float x= a.cuoi.x-a.dau.x;
    float y = a.cuoi.y-a.dau.y;
    float c = sqrt(x*x+y*y);
    return c ;
}
float tichvohuong(vecto a , vecto b){
     float x1= a.cuoi.x-a.dau.x;
     float x2= b.cuoi.x-b.dau.x;
    float y1 = a.cuoi.y-a.dau.y;
    float y2 = b.cuoi.y-b.dau.y;
    float c = x1*x2+y1*y2;
    return c;
}   
int vtrtd(diem x, diem y, int a, int b, int c)
{
    int d1 = a * x.x + b * x.y + c;
    int d2 = a * y.x + b * y.y + c;
    if (d1 > 0 && d2 > 0 || d1 < 0 && d2 < 0)
        return 1;
    else if (d1 == 0 || d2 == 0)
        return 0;
    else
        return -1;
}
int main(){
    vecto a,b;
    diem x,y;
    float c,d,e;
    cout<<"Nhap x va y cua diem thu nhat";cin>>a.dau.x>>a.dau.y;
    cout<<"Nhap x va y cua diem thu hai";cin>>a.cuoi.x>>a.cuoi.y;
    cout<<"Nhap x va y cua diem thu ba";cin>>b.dau.x>>b.dau.y;
    cout<<"Nhap x va y cua diem thu tu";cin>>b.cuoi.x>>b.cuoi.y;
    // a
    cout<<"Do dai vecto a:"<<dodaivecto(a)<<endl;
    cout<<"Do dai vecto b:"<<dodaivecto(b)<<endl;
    // b
    cout<<"tich vo huong cua a va b:"<<tichvohuong(a,b)<<endl;
    // c
    cout<<"Nhap duong thang d:";cin>>c>>d>>e;
    cout<<"Nhap diem toa do diem X";cin>>x.x>>x.y;
    cout<<"Nhap diem toa do diem Y";cin>>y.x>>y.y;
    cout<<"Vi tri tuong doi cua 2 diem voi duong thang"<<vtrtd(x,y,c,d,e);

}