#include <iostream>
using namespace std;
int main() {
    char s[] = "this is a test string",t[100];
    int m ,n,i{0},flag{1};
     
    std::cout<<"Nhap vi tri m va do dai n";cin>>m>>n;
    
    for ( i ; i < n; i++)
    {   *(t+i)=*(s+m+i);
    }
     *(t+n)='\0';
     std::cout<<t<<endl;
    
    for ( i = 0; *(t + i) != '\0'; i++) {
         if (flag==1 && *(t + i) >= 'a' && *(t + i) <= 'z') {
            *(t + i) -= 32;
           flag=0;
        } 
        else if(*(t + i) == ' '){
            flag=1;
        }
        else{
            flag=0;
        }
    }
    std::cout<<t;
    return 0;
}