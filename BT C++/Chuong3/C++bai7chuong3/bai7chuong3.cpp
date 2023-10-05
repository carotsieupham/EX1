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
    int result= Fibo(n);
	cout << "Phần tử thứ " << n << " trong dãy Fibonacci là: " << result << endl;
}
