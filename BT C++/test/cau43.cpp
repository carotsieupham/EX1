#include <iostream>
using namespace std; 
int F(int n)
{
	if(n==1){
        return 0;
        }
	if(n==2){
        return 1;
        }
	if(n>2){
        return F(n-1)+ F(n-2);
        }
	
}	

int main() {
    int m, n;
    cout << "nhap lan luot m va n ";cin>>m>>n;
    for(int i = 1;i<=n;i++){
        if(F(i)%2!=0&& F(i)>=m&&F(i)<=n){
            cout<<F(i)<<",";
        }
    }

    return 0;}