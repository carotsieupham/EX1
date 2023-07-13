#include <iostream>
using namespace std;
#include <iomanip>
void sort(int a[], int size) //Hàm sắp xếp mảng tăng dần
{
	int i, j, t;
	for(i=0; i<size-1; i++)
	for(j=i+1; j<size; j++)
		if(a[i]>a[j]) //Nếu phần tử a[i]>a[j] ( a[j] - Các phần tử sau a[i])
			 { t=a[i];	a[i]=a[j]; a[j]=t; }	//hoán đổi a[i] cho a[j]
}
void XoaX(int a[], int n,float x) {

            int i, j;

            int dem=0;

            for(i=0; i<n; i++) {

                        if(a[i] == x) {

                                    for(j=i; j<n-1; j++) {

                                                a[j] = a[j+1];}
                                    
                                    n--;
                                    i--;}
            }
}
void ChenY(int a[],int n,float y){
    for (int i = n; i >0; i--)
    {
        a[i]=a[i-1];

    }
    a[0]=y;
    n++;
    
}
int main(){
    int h=50;
    int n[h],min,count{0},t;
    float x,y;
    // A
    cout<<"Cau A"<<std::endl;
    for (int i = 0; i < 50; i++)
    {
        cout<<"n["<<i<<"]=";
         cin>>n[i];
    }
    for ( int i = 0; i < 50; i++)
    {
        if (n[i]%2==0&&n[i]>30)
    {
        cout<<n[i]<<";";
    }
     }
     cout<<std::endl;
    //  B
    cout<<"Cau B"<<std::endl;
     min=n[0];
     for (int i = 0; i < 50; i++) //Tìm số nhỏ nhất 
     {
        if (n[i]<min)
        {
            min=n[i];
            
        }
        
     }
        for(int i =0;i<50;i++){ //Đếm số lần xuất hiện của số nhỏ nhất
            if (n[i]==min)
            {
                count+=1;
            }
            
        }
     cout<<"so be nhat:"<<min<<endl;
     cout<<"so lan so be nhat xuat hien:"<<count<<endl;
    //  C
   cout<<"cau C"<<endl;
    sort(n,50); // Sắp xếp mảng a tang dần
	for(int i=0; i<50; i++)	{cout<<n[i]<<"\t";}
    cout<<std::endl;
    //D
    cout<<"cau D:"<<endl;
     cout<<"nhap x can xoa"<<"\t";
     cin>>x;
    XoaX(n,50,x);
    for (int i = 0; i < 50; i++)
    {
        cout<<n[i]<<"\t";
    }
    cout<<std::endl;
    //E
    cout<<"Cau E"<<std::endl;
    cout<<"nhap y can chen"<<"\t";
    cin>>y;
    ChenY(n,h,y);
    sort(n,h);
    for ( int i = 0; i < h; i++)
    {
        cout<<n[i]<<"\t";
    }
    return 0;
}
    

    
    



                                    


                        

