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
     d.tu=a.tu*b.mau+a.mau*b.tu;
     d.mau=a.mau*b.mau;
     return d;
}
phanso nhan(phanso a,phanso b){
    phanso d;
     d.tu=a.tu*b.tu;
     d.mau=a.mau*b.mau;
     return d;
}
float biendoi(phanso a){
    float c;
    c=static_cast<float>(a.tu)/static_cast<float>(a.mau);
    return c;
}


phanso rutgon(phanso a){
    if(a.tu>a.mau){
        for (int i = a.tu; i >1 ; i--)
        {
            if (a.tu%i==0 && a.mau%i==0)
            {
                a.tu/=i;
                a.mau/=i;
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
        }
        return a;
    }
}}
int main()
{   phanso *p,*dau,*q,tam;
    int n;
    dau=new phanso[n];
    cout<<"Nhap so luong phan so can nhap:";cin>>n;
       for (p = dau; p<dau+n; p++) 	
	{
		cout << "tu thu " << p-dau+1 << ": " ; cin >> p->tu ;	
        cout << "mau thu  " << p-dau+1 << ": " ; cin >> p->mau ;	
	}
for (p=dau; p<dau+n; p++) xuat(*p);
cout<<endl;

for (p=dau; p<dau+n-1; p++) // Sắp xếp dãy
		for (q=p+1; q<dau+n; q++) 
		if (biendoi(*q) > biendoi(*p)) 
		{ tam = *p; *p = *q; *q = tam; }
for (p=dau; p<dau+n; p++) xuat(*p);   
    // phanso a={4,7};
    // xuat(a);; cout<<"\n";
    // a.tu=5;
    // a.mau=8;
    // xuat(a); cout<<"\n";
    // phanso *b=&a;

    // b->tu=7;
    // b->mau=9;
    // xuat(a); cout<<"\n";
    // phanso c={4,9};
    // xuat(rutgon(cong(*b,c)));
    delete dau;
    return 0;
}