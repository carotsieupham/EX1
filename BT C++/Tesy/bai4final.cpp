#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <windows.h>
using namespace std;
struct Point{
    int x;
    int y;
    friend istream& operator>>(istream& is,Point &a){
        is>>a.x;
        is>>a.y;
        return is;
    }
};
int Menu(){
    int choose;
    cout<<"======MENU======"<<endl;
    cout<<"1.Play"<<endl;
    cout<<"2.Quit"<<endl;
    cout<<"Lua chon cua ban:";cin>>choose;
    return choose;
}
int Menu_mode(){
    int choose;
    cout<<"======MODE======"<<endl;
    cout<<"1.In quang duong robot di qua"<<endl;
    cout<<"2.Tim so diem cat nhau cua 2 robot"<<endl;
    cout<<"3.Doi khang"<<endl;
    cout<<"Lua chon cua ban:";cin>>choose;
    return choose;
}
bool ktrdk(int x,int y,int b[][100],int m,int n){
    if(x>=0 &&x<m&&y>=0&&y<n&&b[x][y]==0){return true;}
    else return false;
}
void Taomtr(int a[][100],int m, int n){
        srand(time(NULL));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num;
            bool duplicate;

            do
            {
                num = rand() % 100; // tạo số nguyên ngẫu nhiên từ 0 đến 100
                duplicate = false;//Kiem so trong mang da co chua
                for (int k = 0; k < i; k++)
                {
                    for (int l = 0; l < j; l++)
                    {
                        if (a[k][l] == num)
                        {
                            duplicate = true;
                            break;
                        }
                    }
                }
            } while (duplicate);
            a[i][j] = num;
        }
    }
}
void Inmtr(int a[][100],int m,int n){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void Taomatran0(int a[][100],int m ,int n){
    for (int i = 0; i < m; i++)
   {for ( int j = 0; j < n; j++)
    {a[i][j]=0;}}
}
void demdiemcatnhau(int a[][100],int b[][100],int m,int n){
    int i,j,count=0;
     for (i = 0; i<m; i++){
	 for (j = 0; j<n; j++)
        {	if (a[i][j]==1&&b[i][j]==1)
        {
            count++;
        }
         }
	    }
   cout<<"So diem cat nhau cua 2 robot:"<<count<<endl;
}    
int moveRobot(int a[][100],int b[][100], Point &c,int m ,int n)
{   
    int max1 = a[c.x][c.y],h,z,k,r,max2;
    int nextX = c.x;
    int nextY = c.y;
    
    if (ktrdk(c.x-1,c.y,b,m,n)&& a[c.x - 1][c.y] > max1)
    {
        max1 = a[c.x - 1][c.y];
        nextX = c.x - 1;
        nextY = c.y;
    }
    if ( ktrdk(c.x+1,c.y,b,m,n)&&a[c.x + 1][c.y] > max1)
    {
        max1 = a[c.x + 1][c.y];
        nextX = c.x + 1;
        nextY = c.y;
    }
    if (ktrdk(c.x,c.y-1,b,m,n)&&a[c.x][c.y - 1] > max1)
    {
        max1 = a[c.x][c.y - 1];
        nextX = c.x;
        nextY = c.y - 1;
    }
    if ( ktrdk(c.x,c.y+1,b,m,n)&&a[c.x][c.y + 1] > max1)
    {
        max1 = a[c.x][c.y + 1];
        nextX = c.x;
        nextY = c.y + 1;
    }
    if (max1 == a[c.x][c.y]){
        if (ktrdk(c.x-1,c.y,b,m,n))
        {h=a[c.x-1][c.y];}
        else h=-1;
        if (ktrdk(c.x+1,c.y,b,m,n))
        {z=a[c.x+1][c.y];}
        else z=-1;
        if (ktrdk(c.x,c.y-1,b,m,n))
        {k=a[c.x][c.y-1];}
        else k=-1;
        if (ktrdk(c.x,c.y+1,b,m,n))
        {r=a[c.x][c.y+1];}
        else r=-1;
        max2=max({h,z,k,r});
        if(max2==-1){return -1;}
        if (max2==h){b[c.x-1][c.y]=1;max1=a[c.x-1][c.y];nextX=c.x-1;nextY=c.y;}
        if (max2==z){b[c.x+1][c.y]=1;max1=a[c.x+1][c.y];nextX=c.x+1;nextY=c.y;}
        if (max2==k){b[c.x][c.y-1]=1;max1=a[c.x][c.y-1];nextX=c.x;nextY=c.y-1;}
        if (max2==r){b[c.x][c.y+1]=1;max1=a[c.x][c.y+1];nextX=c.x;nextY=c.y+1;}
        }
        c.x=nextX;c.y=nextY;
        b[c.x][c.y]=1;
        return max1;
}
int main(){
    int a[100][100],b[100][100],c[100][100];
	int m,n,choose,max,max1,s1=0,s2=0;
    Point d,e;
    while(true){
    choose=Menu();
    system("cls");
    switch (choose)
    {
    case 1:
        choose=Menu_mode();;
         system("cls");
        switch (choose)
        {
        case 1://In quan duong Robot di duoc
            cout<<"Nhap kich thuoc me cung mxn:";cin>>m>>n; 
            Taomtr(a,m,n);
            Inmtr(a,m,n);
            Taomatran0(b,m,n);
            cout<<"Nhap tao do dat robot:";cin>>d;
            cout<<"Quang duong robot di qua"<<endl;
                b[d.x][d.y]=1;
                max=a[d.x][d.y];
                while (max!=-1)
                {   
                    cout<<max<<" ";max=moveRobot(a,b,d,m,n);
                }
            cout<<endl;
            break;
        case 2://Tim so diem 2 Robot cat nhau
            cout<<"Nhap kich thuoc me cung mxn:";cin>>m>>n; 
            Taomtr(a,m,n);
            Inmtr(a,m,n);
            Taomatran0(b,m,n);
            Taomatran0(c,m,n);
            cout<<"Nhap toa do robot A:";cin>>e;
            cout<<"Nhap toa do robot B:";cin>>d;
            cout<<"Quang duong robot A di qua:"<<endl;
            c[e.x][e.y]=1;
            max1=a[e.x][e.y];
            while (max1!=-1)
            {
                cout<<max1<<" ";max1=moveRobot(a,c,e,m,n);
            }
            cout<<endl;
            cout<<"Quang duong robot B di qua:"<<endl;
            max=a[d.x][d.y];
            b[d.x][d.y]=1;
            while (max!=-1)
            {
            cout<<max<<" ";max=moveRobot(a,b,d,m,n);
            }  
            cout<<endl;
            demdiemcatnhau(b,c,m,n);
                break;
        case 3://Đối kháng 
                cout<<"Nhap kich thuoc me cung mxn:";cin>>m>>n; 
                Taomtr(a,m,n);
                Inmtr(a,m,n);
                Taomatran0(b,m,n);
                cout<<"Nhap toa do robot A:";cin>>d;
                cout<<"Nhap toa do robot B:";cin>>e;
                max=a[d.x][d.y];
                max1=a[e.x][e.y];
                b[d.x][d.y]=1;
                b[e.x][e.y]=1;              
                do{
                if(max!=-1){
                cout<<"Robot A:"<<max<<" ";
                s1+=max;
                max=moveRobot(a,b,d,m,n);
                }
                 else{ cout<<"Robot A:"<<"  ";}              
                if(max1!=-1){
                    cout<<"Robot B:"<<max1<<endl;
                    s2+=max1;
                    max1=moveRobot(a,b,e,m,n);
                }
                else { cout<<"Robot B:"<<" "<<endl;}
                
                }while(max!=-1 ||max1!=-1);
                cout<<endl;
                    cout<<"Tong so cua robot A:"<<s1<<endl;
                    cout<<"Tong so cua robot B:"<<s2<<endl;
                    if(s1>s2){cout<<"A la ng thang";}
                    else if(s1<s2){cout<<"B la ng thang";}
                    else cout<<"A hoa B";
                            cout<<endl;
                            break;
            default:
                     cout<<"Nhap sai"<<endl;
                     break;        
                        }    break;                 
    case 2:
        cout<<"Bye Bye"<<endl;
        break;
    default:
        cout<<"Nhap sai"<<endl;
        break;
    }
    cout<<"Ban co muon tiep tuc khong (1/0) ";
        bool iscontinue;
        cin>>iscontinue;
        system("cls");
        if(!iscontinue){
            cout<<"Bye";
            break;
        } 
    }
    }