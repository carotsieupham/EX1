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
vecto congVecto(vecto a, vecto b) {
    vecto c;
    c.dau.x = a.dau.x + b.dau.x;
    c.dau.y = a.dau.y + b.dau.y;
    c.cuoi.x = a.cuoi.x + b.cuoi.x;
    c.cuoi.y = a.cuoi.y + b.cuoi.y;
    return c;
}
void sapxep(vecto L[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (dodaivecto(L[i]) > dodaivecto(L[j]))
            {
                vecto temp = L[i];
                L[i] = L[j ];
                L[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Nhap kich thuoc mang:";cin>>n;
    vecto L[100];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap toa do diem dau cua vecto thu " << i + 1 << ": ";
        cin >> L[i].dau.x >> L[i].dau.y;
        cout << "Nhap toa do diem cuoi cua vecto thu " << i + 1 << ": ";
        cin >> L[i].cuoi.x >> L[i].cuoi.y;
    }
    cout << "Danh sach cac vector truoc khi sap xep:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Vector thu " << i + 1 << ": (" << L[i].cuoi.x-L[i].dau.x << "," << L[i].cuoi.y -L[i].dau.y << ")"<<endl ;
    }
    sapxep(L,n);
     cout << "Danh sach cac vector sau khi sap xep:\n";
    for (int i = 0; i < n; i++)
    {
         cout << "Vector thu " << i + 1 << ": (" << L[i].cuoi.x-L[i].dau.x << "," << L[i].cuoi.y -L[i].dau.y << ")"<<endl ;;
    } 
}