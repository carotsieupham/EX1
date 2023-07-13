#include <iostream>
using namespace std;
void NhapMang(int a[100][100],int m , int n ){
	for (int i = 0; i<m; i++){
	for (int j = 0; j<n; j++)
	{ 	cout<<"[" << i << "]["<<j<<"] = "; cin>>a[i][j]; }
	}
}
void XuatMang(int a[100][100],int m , int n ){
	for (int i = 0; i<m; i++){
	for (int j = 0; j<n; j++)
	{ 	cout<< a[i][j]<<" "; }
	cout<<"\n";}
}
void Cong2Matran(int a[100][100],int b[100][100],int sum[100][100],int m ,int n){
	for (int i = 0; i<m; i++){
	for (int j = 0; j<n; j++)
	{ 	
	 sum[i][j]=a[i][j]+b[i][j]; 
	}}
	for (int i = 0; i<m; i++){
	for (int j = 0; j<n; j++)
	{ 	cout<< sum[i][j]<<" "; }
	cout<<"\n";}
}
void TimSolon(int a[100][100],int m,int n){
	int i,j,max;
	for (int i = 0; i<m; i++){
	for (int j = 0; j<n; j++)
	{ if(a[i][j]>max){
		max=a[i][j];
	}
	}
	
}
cout<<"Phan tu lon nhat cua ma tran:"<<max;
}
int TongMatran(int a[100][100],int m,int n){
	int sum{0};
	for (int i = 0; i<m; i++){
	for (int j = 0; j<n; j++)
	{ sum+=a[i][j];
	}
	
}return sum;
}
void sortTang(int a[100][100],int m,int n){
	int k,i,j,t;
	for ( k = 0; k < m; k++)
	{
		for ( i = 0; i < n-1; i++)
		{
			for ( j = i+1; j < n; j++)
			{
				if ((a[k][i])>(a[k][j]))
				{
					t=a[k][i];
					a[k][i]=a[k][j];
					a[k][j]=t;
				}
			}
		}
	}
				
			
		
	for ( k = 0; k < n; k++)
	{
		for ( i = 0; i < m-1; i++)
		{
			for ( j = i+1; j < m; j++)
			{
				if ((a[i][k])>(a[j][k]))
				{
					t=a[i][k];
					a[i][k]=a[j][k];
					a[j][k]=t;
				}
			}
		}
	}
}
void sortGiam(int a[100][100],int m,int n){
	int k,i,j,t;
	for ( k = 0; k < m; k++)
	{
		for ( i = 0; i < n-1; i++)
		{
			for ( j = i+1; j < n; j++)
			{
				if ((a[k][i])<(a[k][j]))
				{
					t=a[k][i];
					a[k][i]=a[k][j];
					a[k][j]=t;
				}
				
			}
			
		}
		
	}
	for ( k = 0; k < n; k++)
	{
		for ( i = 0; i < m-1; i++)
		{
			for ( j = i+1; j < m; j++)
			{
				if ((a[i][k])<(a[j][k]))
				{
					t=a[i][k];
					a[i][k]=a[j][k];
					a[j][k]=t;
				}
			}
		}
	}
}
int main(){
    int a[100][100],b[100][100],m,n;
	int sum[100][100];
	cout<<"Nhap so hang va cot ";cin>>m>>n;
	cout<<"Nhap ma tran A"<<std::endl;
	NhapMang(a,m,n);
	cout<<"Nhap ma tran B"<<std::endl;
	NhapMang(b,m,n);
	//A
	cout<<"Ma tran A"<<std::endl;
	XuatMang(a,m,n);
	cout<<"Ma tran B"<<std::endl;
	XuatMang(b,m,n);
	//B
	TimSolon(a,m,n);
	cout<<std::endl;
	TimSolon(b,m,n);
	cout<<std::endl;
	cout<<"Tong hai ma tran"<<std::endl;
	Cong2Matran(a,b,sum,m,n);
	//C
	if(TongMatran(a,m,n)>TongMatran(b,m,n)){
		cout<<"Tong ma tran A lon hon"<<std::endl;
	}
	else{
		cout<<"Tong ma tran B lon hon"<<std::endl;
	}
	cout<<"Sap xep ma tran A "<<std::endl;
	sortTang(a,m,n);
	XuatMang(a,m,n);
	cout<<"Sap xep ma tran B "<<std::endl;
	sortGiam(b,m,n);
	XuatMang(b,m,n);
	

}
				
			
		
	
	
				
			
		
	
	
