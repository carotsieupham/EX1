#include<iostream>
using namespace std;
int Fibo(int n)
{
	if(n==1){return 0;}
	if(n==2){return 1;}
	if(n>2){return Fibo(n-1)+ Fibo(n-2);}
	
}	
int main()
{   int n;
cout<<"Nhap so phan tu can tim";cin>>n;
	cout<<"\n"<<n<<" phan tu dau tien cua day Fibonacci la:\n";
	for(int i=1; i<=n; i++){
	cout<<Fibo(i)<<"\t";}
    cout<<endl;
    cout<<"Phan tu chan cua day"<<endl;
    for(int i=1;i<=n;i++){
        if (Fibo(i)%2==0)
        {   
            cout<<Fibo(i)<<"\t";
        }
    }
    cout<<endl;
    cout<<"Phan tu le cua day"<<endl;
    for(int i=1;i<=n;i++){
        if (Fibo(i)%2!=0)
        {   
            cout<<Fibo(i)<<"\t";
        }
    }
}
