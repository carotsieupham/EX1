#include <iostream>
#include <cstring>

using namespace std;

struct sv
{   string hoten;
    int day;
    int month;
    int year;
};


int main(){
   sv *p,*dau,*q,t;
   int n;
   cout<<"Nhap so sinh vien can nhap:";cin>>n;
   dau=new sv[n];
   for ( p = dau; p < dau+n; p++)
   {
        cout<<"Nhap ho ten sv thu "<<p-dau+1<<":";
        cin.ignore();
        getline(cin, p->hoten);
        cout<<"Nhap ngay sinh sv thu " <<p-dau+1<<":";cin>>p->day;
        cout<<"Nhap thang sinh sv thu " <<p-dau+1<<":";cin>>p->month;
        cout<<"Nhap nam sinh sv thu " <<p-dau+1<<":";cin>>p->year;
        
   }
   
   for (p=dau; p<dau+n-1; p++) {
		for (q=p+1; q<dau+n; q++) { 
           if ( p->year < q->year)
           { t=*p;*p=*q;*q=t;}
           else if (p->year == q->year)
           {
            if (p->month ==q->month)
           { if (p->day < q->day)
           {t=*p;*p=*q;*q=t;}
           }
            else if (p->month < q->month)
            {t=*p;*p=*q;*q=t;}
           }
        }
                
    }
   
   cout<<"Danh sach sv sau khi sap xep"<<endl;
   
   
   for ( p = dau; p < dau+n; p++)
   {
        cout<<p->hoten<<" ngay sinh:"<<p->day<<"/"<<p->month<<"/"<<p->year<<endl;
}
delete[]dau;
return 0;
}
