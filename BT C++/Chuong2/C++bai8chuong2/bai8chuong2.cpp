#include <iostream>
using namespace std;
int main(){
    int n,i,u,h ;
    int sum{0}; cout<<"nhap n";cin>>n;
    i=n-1;
    for ( i = (n-1); i >0; i-=1)
    { sum=0;
        for ( u =1; u <= (i/2); u++)
        {
            if ((i%u)==0)
            {
                sum+=u;              
            }                       
        }
        if(sum==i){
                cout<<i<<"\t";
            }
        
    }
    

}