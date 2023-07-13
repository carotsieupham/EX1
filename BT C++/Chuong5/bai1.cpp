#include <iostream>
#include <math.h>
using namespace std;
struct phanso{
      int tu;
      int mau;
};
void xuat(phanso p){
    cout<<p.tu<<"/"<<p.mau<<"\t";
}
phanso cong(phanso a,phanso b){
     phanso c;
     c.tu=a.tu*b.mau+a.mau*b.tu;
     c.mau=a.mau*b.mau;
     return c;
}
phanso tru(phanso a,phanso b){
    phanso d;
     d.tu=(a.tu*b.mau)-(a.mau*b.tu);
     d.mau=a.mau*b.mau;
     return d;
}
phanso nhan(phanso a,phanso b){
    phanso d;
     d.tu=a.tu*b.tu;
     d.mau=a.mau*b.mau;
     return d;
}
phanso chia(phanso a , phanso b){
    phanso c;
    c.tu=a.tu*b.mau;
    c.mau=a.mau*b.tu;
    return c;
}

phanso toigian(phanso a){
    if(a.tu>a.mau){
        for (int i = a.tu; i >1 ; i--)
        {
           
            if (a.tu%i==0 && a.mau%i==0)
            {
                a.tu/=i;
                a.mau/=i;
            }
           
         
       
    }return a;}
    else if(a.tu==a.mau){
        phanso c;
        c.tu= 1;
        c.mau=1;
        return c;
    }
    else if(a.tu==0){
        phanso c;
        c.tu= 0;
        c.mau=0;
        return c;
    }
       else{
                for (int i = a.mau; i >1 ; i--)
        {
            if (a.tu%i==0 && a.mau%i==0)
            {
                a.tu/=i;
                a.mau/=i;
            }
            }
            return a;
        }
}
int main(){
phanso a,b;
cout<<"nhap tu so va mau so cua a";cin>>a.tu>>a.mau;
cout<<"nhap tu so va mau so cua b";cin>>b.tu>>b.mau;

xuat(toigian(cong(a,b)));
xuat(toigian(tru(a,b)));
xuat(toigian(nhan(a,b)));
xuat(toigian(chia(a,b)));
}