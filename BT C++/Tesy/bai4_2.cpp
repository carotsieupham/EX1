#include <iostream>
#include <algorithm>
using namespace std;
int a[100][100],b[100][100],c[100][100];
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
int Menu_play(){
    int choose;
    cout<<"=======Player======="<<endl;
    cout<<"1.Mot nguoi choi"<<endl;
    cout<<"2.Hai nguoi choi"<<endl;
    cout<<"Lua chon cua ban:";cin>>choose;
    return choose;
}
int Menu_mode(){
    int choose;
    cout<<"======Mode======"<<endl;
    cout<<"1.Tim so diem cat nhau cua 2 robot"<<endl;
    cout<<"2.Doi khang"<<endl;
    cout<<"Lua chon cua ban:";cin>>choose;
    return choose;
}
void Nhapmtr(int a[][100],int m, int n){
    for (int i = 0; i < m; i++)
        {
            for ( int j = 0; j < n; j++)
            {
        cout<<"a"<<"["<<i<<"]"<<"["<<j<<"]:";cin>>a[i][j];
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
bool ktrdk(int x,int y,int b[][100],int m,int n){
    if(x>=0 &&x<m&&y>=0&&y<n&&b[x][y]==0){return true;}
    else return false;
}
void Taomatran0(int a[][100],int m ,int n){
    for (int i = 0; i < m; i++)
   {
    for ( int j = 0; j < n; j++)
    {
        a[i][j]=0;
    }
   }
}
void moveRobot(int a[][100],int b[][100], Point c,int m ,int n)
{   
    int max1 = a[c.x][c.y],h,z,r,k,max2;
    int nextX = c.x;
    int nextY = c.y;
cout<<max1<<" ";
while(true){
    b[c.x][c.y]=1;
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
        {
            h=a[c.x-1][c.y];
        }
        else h=-1;
        if (ktrdk(c.x+1,c.y,b,m,n))
        {
            z=a[c.x+1][c.y];
        }
        else z=-1;
        if (ktrdk(c.x,c.y-1,b,m,n))
        {
            r=a[c.x][c.y-1];
        }
        else r=-1;
        if (ktrdk(c.x,c.y+1,b,m,n))
        {
            k=a[c.x][c.y+1];
        }
        else k=-1;
        max2=max({h,z,r,k});
        if(max2==-1){break;}
        if (max2==h){b[c.x-1][c.y]=1;max1=a[c.x-1][c.y];nextX=c.x-1;nextY=c.y;}
        if (max2==z){b[c.x+1][c.y]=1;max1=a[c.x+1][c.y];nextX=c.x+1;nextY=c.y;}
        if (max2==r){b[c.x][c.y-1]=1;max1=a[c.x][c.y-1];nextX=c.x;nextY=c.y-1;}
        if (max2==k){b[c.x][c.y+1]=1;max1=a[c.x][c.y+1];nextX=c.x;nextY=c.y+1;}
        }
        c.x=nextX;    
        c.y=nextY;
        cout << max1<<" ";}
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
void moveRobotAB(int a[][100],int b[][100],Point c,Point d,int m, int n){
    int max1 = a[c.x][c.y],h,z,r,k,max2,s1,s2,max3=a[d.x][d.y];
    s1=0;s2=0;
    int nextX1 = c.x;
    int nextX2 = d.x;
    int nextY1 = c.y;
    int nextY2 = d.y;
    b[c.x][c.y]=1;
    b[d.x][d.y]=1;
while(true){
    std::cout <<"Robot A:" <<max1;  
    s1+=max1;
    cout <<" "<<"Robot B:"<<max3<<endl;
    s2+=max3;   
    if (ktrdk(c.x-1,c.y,b,m,n) && a[c.x - 1][c.y] > max1 &&c.x<5)
    {
        max1 = a[c.x - 1][c.y];
        nextX1 = c.x - 1;
        nextY1 = c.y;
    }
    if (  ktrdk(c.x+1,c.y,b,m,n)&& a[c.x+ 1][c.y] > max1)
    {
        max1 = a[c.x + 1][c.y];
        nextX1 = c.x + 1;
        nextY1= c.y;
    }
    if (ktrdk(c.x,c.y-1,b,m,n) &&a[c.x][c.y - 1] > max1)
    {
        max1 = a[c.x][c.y - 1];
        nextX1 = c.x;
        nextY1 = c.y - 1;
    }
    if (  ktrdk(c.x,c.y+1,b,m,n) &&a[c.x][c.y + 1] > max1)
    {
        max1 = a[c.x][c.y + 1];
        nextX1 = c.x;
        nextY1 = c.y + 1;
    }
    if (max1 == a[c.x][c.y]){
        if (ktrdk(c.x-1,c.y,b,m,n))
        {
            h=a[c.x-1][c.y];
        }
        else h=-1;
        if (ktrdk(c.x+1,c.y,b,m,n))
        {
            z=a[c.x+1][c.y];
        }
        else z=-1;
        if (ktrdk(c.x,c.y-1,b,m,n))
        {
            r=a[c.x][c.y-1];
        }
        else r=-1;
        if (ktrdk(c.x,c.y+1,b,m,n))
        {
            k=a[c.x][c.y+1];
        }
        else k=-1;
        max2=max({h,z,r,k});
        if(max2==-1){break;}
        if (max2==h){b[c.x-1][c.y]=1;max1=a[c.x-1][c.y];nextX1=c.x-1;nextY1=c.y;}
        if (max2==z){b[c.x+1][c.y]=1;max1=a[c.x+1][c.y];nextX1=c.x+1;nextY1=c.y;}
        if (max2==r){b[c.x][c.y-1]=1;max1=a[c.x][c.y-1];nextX1=c.x;nextY1=c.y-1;}
        if (max2==k){b[c.x][c.y+1]=1;max1=a[c.x][c.y+1];nextX1=c.x;nextY1=c.y+1;}
        }
        c.x=nextX1;    
        c.y=nextY1;
        b[c.x][c.y]=1;
        //B
    if (ktrdk(d.x-1,d.y,b,m,n) && a[d.x - 1][d.y] > max3)
    {
        max3 = a[d.x - 1][d.y];
        
        nextX2 = d.x - 1;
        nextY2 = d.y;
    }
    if (  ktrdk(d.x+1,d.y,b,m,n)&&a[d.x+ 1][d.y] > max3)
    {
        max3 = a[d.x + 1][d.y];
        nextX2 = d.x + 1;
        nextY2= d.y;
    }
    if (ktrdk(d.x,d.y-1,b,m,n)&&a[d.x][d.y - 1] > max3)
    {
        max3 = a[d.x][d.y - 1];
        nextX2 = d.x;
        nextY2 = d.y - 1;
    }
    if ( ktrdk(d.x,d.y+1,b,m,n)&&a[d.x][d.y + 1] > max3)
    {
        max3 = a[d.x][d.y + 1];
        nextX2 = d.x;
        nextY2 = d.y + 1;
    }
    if (max3 == a[d.x][d.y]){
        if (ktrdk(d.x-1,d.y,b,m,n))
        {
            h=a[d.x-1][d.y];
        }
        else h=-1;
        if (ktrdk(d.x+1,d.y,b,m,n))
        {
            z=a[d.x+1][d.y];
        }
        else z=-1;
        if (ktrdk(d.x,d.y-1,b,m,n))
        {
            r=a[d.x][d.y-1];
        }
        else r=-1;
        if (ktrdk(d.x,d.y+1,b,m,n))
        {
            k=a[d.x][d.y+1];
        }
        else k=-1;
        max2=max({h,z,r,k});
        if(max2==-1){break;}
        if (max2==h){b[d.x-1][d.y]=1;max3=a[d.x-1][d.y];nextX2=d.x-1;nextY2=d.y;}
        if (max2==z){b[d.x+1][d.y]=1;max3=a[d.x+1][d.y];nextX2=d.x+1;nextY2=d.y;}
        if (max2==r){b[d.x][d.y-1]=1;max3=a[d.x][d.y-1];nextX2=d.x;nextY2=d.y-1;}
        if (max2==k){b[d.x][d.y+1]=1;max3=a[d.x][d.y+1];nextX2=d.x;nextY2=d.y+1;}
        }
        d.x=nextX2;    
        d.y=nextY2;
        b[d.x][d.y]=1;
     }
        cout<<endl;
        cout<<"Tong so cua robot A:"<<s1<<endl;
        cout<<"Tong so cua robot B:"<<s2<<endl;
        if(s1>s2){cout<<"A la ng thang";}
        else if(s1<s2){cout<<"B la ng thang";}
        else cout<<"A hoa B";
}        
int main()
{   
	int m,n,choose;
    Point d,e;
while(true){
    choose=Menu();
    system("cls");
    switch (choose)
    {
    case 1:
        cout<<"Nhap kich thuoc me cung mxn:";cin>>m>>n; 
        Nhapmtr(a,m,n);
        choose=Menu_play();
         system("cls");
        switch (choose)
        {
        case 1:
            Inmtr(a,m,n);
            Taomatran0(b,m,n);
            cout<<"Nhap tao do dat robot:";cin>>d;
            cout<<"Quang duong robot di qua"<<endl;
            moveRobot(a,b,d,m,n);
            cout<<endl;
            break;
        case 2:
            choose=Menu_mode();
            system("cls");
            switch (choose)
            {
            case 1:
                Inmtr(a,m,n);
                Taomatran0(b,m,n);
                Taomatran0(c,m,n);
                cout<<"Nhap toa do robot A:";cin>>d;
                cout<<"Nhap toa do robot B:";cin>>e;
                moveRobot(a,b,d,m,n);
                cout<<endl;
                moveRobot(a,c,e,m,n);
                cout<<endl;
                demdiemcatnhau(b,c,m,n);
                break;
            case 2: 
                Inmtr(a,m,n);
                Taomatran0(b,m,n);
                cout<<"Nhap toa do robot A:";cin>>d;
                cout<<"Nhap toa do robot B:";cin>>e;
                moveRobotAB(a,b,d,e,m,n);
                cout<<endl;
                break;
            default:
                cout<<"Nhap sai"<<endl;
                break;
            }
            break;
        default:
            cout<<"Nhap sai"<<endl;
            break;
        }
        break;
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
        if(!iscontinue){
            cout<<"Bye";
            break;
        } 
    }
}    