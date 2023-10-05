#include <iostream>
using namespace std;
#include <math.h>
int main(){
    float a,b,c;
    float x1,x2;
    float delta;
    cin >> a>>b>>c;
    if(a==0){
        if(b==0 && c==0){
            cout<<"Ptr vo so nghiem";}
        else if(b==0 && c!=0){
            cout<<"ptr vo nghiem";

        }
    }
    else{
        delta=b*b-4*a*c;
        if(delta=0){
            x1=-b/(2*a);
            cout<<"nghiem cua ptr la:"<<x1;}
        
        else if (delta>0){
            x1=(-b+sqrt(delta))/(2*a);
            x2=(-b-sqrt(delta))/(2*a);
            cout<<"nghiem cua ptr la x1 ="<<x1<<"x2="<<x2;
        }
        else{
            cout<<"ptr vo nghiem";
        }

    }
    return 0;

}
