#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int so_nt(int i){
    int u{2};
    int flag{0};
    int a;
    while (u<=sqrt(i)){
        a=i%u;
        if (a==0){
            flag=1;
            break;
        }
        u++;
    }
    if (flag==0)
    {
        return true;
    }
    else{
                return false;
    }
}
int main(){
    int sum{0};
    for(int i=2 ;i<=1000;i++){
        if(so_nt(i)&&so_nt((i-2))){
            if(i-2>1){
          cout<<"("<<(i-2)<<","<<i<<")"<<"\t";
          }
        }
    }
}


          
          
       

    
    
