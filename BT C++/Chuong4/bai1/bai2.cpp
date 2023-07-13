#include <iostream>
using namespace std;
int main(){
    int n , *dau,*p,t,*q,*h,s{0},max,index,i{0},j{0},k,l;
    cout<<"Nhap vao so phan tu cua day:";cin>>n;
    dau= new int[n];
    for ( p = dau; p < dau+n; p++)
    {
        cout<<"So thu "<<p-dau+1<<":";cin>>*p;
    }
    cout<<"dao nguoc mang:"<<endl;
    for (p=dau+n-1; p>=dau; p--) {   
    cout <<*p<<'\t' ;
    }
    cout<<endl;
    max = *dau;
    q=dau;
    for( p=dau+n-1;p>=dau;p--){
        
        if(*p > max){
            max= *p;
            index=q-dau+1;
        }
        q++;
    }
    cout << "So lon nhat trong day: " << max << " Vi tri trong day la: " << index << endl;
    cout<<"Sap xep tang dan"<<endl;
    for (  p= dau; p < dau+n-1; p++)
    {   for ( h = p+1; h < dau+n; h++)
    {
        if (*p>*h)
        {   t=*p;
            *p=*h;
            *h=t;
        }
    }
    }
    
    for ( p = dau; p < dau+n; p++)
    {
        cout<<*p<<'\t';
    }
    p=dau;
    while (*(p+i)<0)
    {
        i++;
    }
    j=i;
    while (*(p+j)==0)
    {
       j++;
    }
    
    
    for ( k = i; k < j-1; k++)
    {   for ( l = k+1; l < j; l++)
    {
       
        if (*(p+k)<*(p+l))
    {   t=*(p+k);
        *(p+k)=*(p+l);
        *(p+l)=t;
    }
    }
    }
     for ( k = j; k < n-1; k++)
    {   for ( l = k+1; l < n; l++)
    {
       
        if (*(p+k)>*(p+l))
    {   t=*(p+k);
        *(p+k)=*(p+l);
        *(p+l)=t;
    }
    }
    }
    cout<<endl;
    for ( p = dau; p < dau+n; p++)
    {
        cout<<*p<<'\t';
    }
    delete dau;
}
        
    
    
    
    

          
        
    
        
    