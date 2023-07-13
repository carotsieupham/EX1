#include <iostream>
#include <string.h>
using namespace std;
int ktrdx(char a[],int n){
    int flag =1;
    for (int i = 0; i < n/2; i++)
    {
        if (a[i] != a[n-i-1])
        {
             flag=0;
        }
        else
        {
            flag=1;
        }
    }
    if (flag==1)
    {
        cout<<"La chuoi doi xung";
    }
    else{cout<<"k phai la chuoi doi xung";}  
        
    
}
int main(){
    char a[100];
    int n,i=0;
    cout<<"Nhap chuoi:";cin.getline(a,99);
    for(i=0;i<strlen(a);i++){
      
    
        n++;
    }
    ktrdx(a,n);

}