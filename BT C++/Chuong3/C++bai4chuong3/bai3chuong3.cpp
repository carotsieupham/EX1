#include <iostream>
#include <string.h>

using namespace std;
int main(){
    char str[100],str2[100],s[100];
    int count{0},countNumber{0},i,n;
    cout<<"Nhap xau ki tu:";cin.getline(str,99);
    cout<<str<<endl;
    for(i=0;i<strlen(str);i++){
        if (str[i]==' ')
        {
            continue;
        }
    
        count++;
    }
    cout<<"so ki tu trong xau la:"<<count<<endl;
    count=0;
    while(str[count]!=0){
        if(str[count]>='0'&&str[count]<='9'){
            countNumber++;
        }
        count++;
    }
    cout<<"so ki tu so trong xau la:"<<countNumber<<endl;
    count=0;
    for(i=0;i<=strlen(str);i++){
        if(str[i]>='!'&&str[i]<='@'){
            continue;
        }
            
        cout<<str[i];
    }   
        
    cout<<endl;
    for ( i = 0; i <= strlen(str); i++)
    {
        if (str[i]>=97&&str[i]<=122)
        {
            str[i]=str[i]-32;
        }
        
    }
    cout<<"Chuoi sau khi in hoa:"<<str<<endl;
    
    cout<<"Nhap chuoi str2:";cin.getline(str2,99);
    cout<<"Nhap vi tri can chen:";cin>>n;
   cout<< strcpy(s,str+n)<<endl;
   cout<< strcpy(str+n,str2)<<endl;
   cout<< strcat(str,s)<<endl;
   
    cout<<"Chuoi str sau khi chen chuoi str2 la:"<<str;
    
return 0;
}