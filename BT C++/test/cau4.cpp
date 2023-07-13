#include<iostream>
using namespace std;
#include<math.h>
float s( int n){
    float s{0},h{1};
    for (int i = 1; i <= n; i++)
    {   h=1;
        for ( int j = 1; j <=i; j++)
    {
        h*=j;
    }
        s+=static_cast<float>(h)/static_cast<float>(sqrt(i+1));
        
    }
    return s;
}
float dqs(int n){
      
}

int main(){
    int n;
    cout<<"nhap so n:";cin>>n;
    cout<<s(n);
}