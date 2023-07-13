#include<iostream>
#include<string.h>
using namespace std;
int main()
{   
	char Sinh_vien[10][25],temp; //Mảng Sinh_vien gồm 10 chuỗi
	int i,j,count{0},n{10};
	for( i=0; i<10; i++)
	{
		cout<<"Nhap vao ho va ten sinh vien thu " <<i+1<<" :\n";
		cin.getline(Sinh_vien[i], 24);//Nhập tối đa 24 kí tự cho chuỗi Sinh_vien[i]
	}
	cout<<"Danh sach sinh vien vua nhap la: \n";
	for( i=0; i<10; i++){
	cout<<"Sinh vien thu "<<i+1<<": "<<Sinh_vien[i]<<"\n";}
    for(i=0;i<10;i++){
        
            if(Sinh_vien[i][0]=='N'&&Sinh_vien[i][1]=='g'&&Sinh_vien[i][2]=='u'&&Sinh_vien[i][3]=='y'&&Sinh_vien[i][4]=='e'&&Sinh_vien[i][5]=='n'){
                count++;
            }
    }
    cout<<"so ng ho nguyen la:"<<count<<endl;
     for ( i = 0; i <n; i++)
    {
        if(Sinh_vien[i][0]>Sinh_vien[i+1][0]){
            for(j=0;j<strlen(Sinh_vien[i]);j++){
            temp=Sinh_vien[i][j];
            Sinh_vien[i][j]=Sinh_vien[i+1][j];
            Sinh_vien[i+1][j]=temp;
        }
        i--;

    }
        
        
    }
    for( i=0; i<10; i++){
	cout<<"Sinh vien thu "<<i+1<<": "<<Sinh_vien[i]<<"\n";}

    
}	
