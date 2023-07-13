#include <iostream>
using namespace std;
int main(){
    float a,b,c,d,max1,max2;
    cin >> a>>b>>c>>d;
    max1=a;
    max2=c;
    if(a<b){
        max1=b;
    }
    if(c<d){
        max2=d;
    }
    if (max2>max1)
    {
        cout<<"so lon nhat la "<<max2;
    }
    else{
        cout<<"so lon nhat la "<<max1;
    }
    
   
    
}