#include<iostream>
using namespace std;
int main(){
int B[]={2,4,7,8,9,15};
int c,*p=&B[1];
*p+=1;
c=*p--;
p+=3;
*p+=c;
for (int i = 0; i < 6; i++)
{
   cout<<B[i]<<" ";
}

}