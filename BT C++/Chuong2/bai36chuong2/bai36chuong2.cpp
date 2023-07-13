#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int i,j;
    for ( i = 1; i < 10; i++)
    {for ( j = 1; j < 6; j++)
    {
      cout<<j<<" x "<<i<<" = "<<setw(2)<<j*i<<";";
    }
    
        
    }
    
}
