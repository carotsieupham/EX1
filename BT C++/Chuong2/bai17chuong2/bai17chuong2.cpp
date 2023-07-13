#include <iostream>
using namespace std;
int main(){
    int giobd, giokt, thoigian, tien;
do
{
cout<<"Nhap gio bat dau:";cin>>giobd;
cout<<"Nhap gio ket thuc";cin>>giokt;
} while (giobd<8 || giokt>24);
    

thoigian = giokt - giobd;
if (thoigian > 3)
tien = 3 * 30000 + (thoigian - 3) * 30000 * 0.7;
else tien = thoigian * 30000;
if (giokt <= 17) 
tien *= 0.9; 
cout<<"so tien phai tra:"<<tien;
}