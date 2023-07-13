#include <iostream>
using namespace std;
int main(){
    float a,b,c,d,max1,max2,min1,min2;
    cout<<"Nhap lan luot 4 so:";
    cin >> a>>b>>c>>d;
    max1=a;
    max2=c;
    min1=b;
    min2=d;
    if(a<b){
        max1=b;
        min1=a;
    }
    if(c<d){
        max2=d;
        min2=c;
    }
    if (max2>max1 )
    {
        cout<<"so lon nhat la "<<max2<<endl;
    }
    else{
        cout<<"so lon nhat la "<<max1<<endl;
    }
    
   if (min2>min1 )
    {
        cout<<"so nho nhat la "<<min1<<endl;
    }
    else{
        cout<<"so nho nhat la "<<min2<<endl;
    }
    
}