#include <iostream>
using namespace std;
#include<math.h>
int main(){
    int c,f,le,chan;
    double b,d,e,g;
for (int i = 1000; i < 10000; i++) {
    b=i/1000;//so hang nghin
    c=i/100;
    d=c%10;//so hang tram
    e=i%10;//so hang don vi
    f=i/10;
    g=f%10;//so hang chuc
    le=b+d;
    chan=e+g;
       if (le%2!=0&&chan%2==0)
       {
        cout<<i<<"\t";
       }
    }
}
   
    
        
    
    
    
    



        
 
    
        
    
    
