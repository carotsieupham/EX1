#include <iostream>
#include <algorithm>
using namespace std;
bool ktrdk(int x,int y,int b[][5]){
    if(x>=0 &&x<=5&&y>=0&&y<=4&&b[x][y]==0){return true;}
    else return false;
}
void moveRobot(int a[][5],int b[][5], int x, int y)
{   
    int max1 = a[x][y],h,z,r,k,max2;
    int nextX = x;
    int nextY = y;
while(true){
    b[x][y]=1;
    if (ktrdk(x-1,y,b)&& a[x - 1][y] > max1)
    {
        max1 = a[x - 1][y];
        nextX = x - 1;
        nextY = y;
    }
    if ( ktrdk(x+1,y,b)&&a[x + 1][y] > max1)
    {
        max1 = a[x + 1][y];
        nextX = x + 1;
        nextY = y;
    }
    if (ktrdk(x,y-1,b)&&a[x][y - 1] > max1)
    {
        max1 = a[x][y - 1];
        nextX = x;
        nextY = y - 1;
    }
    if ( ktrdk(x,y+1,b)&&a[x][y + 1] > max1)
    {
        max1 = a[x][y + 1];
        nextX = x;
        nextY = y + 1;
    }
    if (max1 == a[x][y]){
        if (ktrdk(x-1,y,b))
        {
            h=a[x-1][y];
        }
        else h=-1;
        if (ktrdk(x+1,y,b))
        {
            z=a[x+1][y];
        }
        else z=-1;
        if (ktrdk(x,y-1,b))
        {
            r=a[x][y-1];
        }
        else r=-1;
        if (ktrdk(x,y+1,b))
        {
            k=a[x][y+1];
        }
        else k=-1;
        max2=max({h,z,r,k});
        if(max2==-1){break;}
        if (max2==h){b[x-1][y]=1;max1=a[x-1][y];nextX=x-1;nextY=y;}
        if (max2==z){b[x+1][y]=1;max1=a[x+1][y];nextX=x+1;nextY=y;}
        if (max2==r){b[x][y-1]=1;max1=a[x][y-1];nextX=x;nextY=y-1;}
        if (max2==k){b[x][y+1]=1;max1=a[x][y+1];nextX=x;nextY=y+1;}
        }
        x=nextX;    
        y=nextY;
        cout << max1<<" ";}
        
}
void demdiemcatnhau(int a[][5],int b[][5]){
    int i,j,count=0;
     for (i = 0; i<6; i++){
	 for (j = 0; j<5; j++)
        {	if (a[i][j]==1&&b[i][j]==1)
        {
            count++;
        }
         }
	    }
   cout<<"So diem cat nhau cua 2 robot:"<<count;
}    
void moveRobotAB(int a[][5],int b[][5],int x1,int y1,int x2,int y2){
    int max1 = a[x1][y1],h,z,r,k,max2,s1,s2,max3=a[x2][y2];
    s1=0;s2=0;
    int nextX1 = x1;
    int nextX2 = x2;
    int nextY1 = y1;
    int nextY2 = y2;
while(true){
    b[x2][y2]=1;
    b[x1][y1]=1;
    std::cout <<"Robot A:" <<max1;  
    s1+=max1;
    cout <<" "<<"Robot B:"<<max3<<endl;
    s2+=max3;   
    if (ktrdk(x1-1,y1,b) && a[x1 - 1][y1] > max1 &&x1<5)
    {
        max1 = a[x1 - 1][y1];
        nextX1 = x1 - 1;
        nextY1 = y1;
    }
    if (  ktrdk(x1+1,y1,b)&& a[x1+ 1][y1] > max1&&x1<5)
    {
        max1 = a[x1 + 1][y1];
        nextX1 = x1 + 1;
        nextY1= y1;
    }
    if (ktrdk(x1,y1-1,b) &&a[x1][y1 - 1] > max1)
    {
        max1 = a[x1][y1 - 1];
        nextX1 = x1;
        nextY1 = y1 - 1;
    }
    if (  ktrdk(x1,y1+1,b) &&a[x1][y1 + 1] > max1&&y1<4)
    {
        max1 = a[x1][y1 + 1];
        nextX1 = x1;
        nextY1 = y1 + 1;
    }
    if (max1 == a[x1][y1]){
        if (ktrdk(x1-1,y1,b))
        {
            h=a[x1-1][y1];
        }
        else h=-1;
        if (ktrdk(x1+1,y1,b))
        {
            z=a[x1+1][y1];
        }
        else z=-1;
        if (ktrdk(x1,y1-1,b))
        {
            r=a[x1][y1-1];
        }
        else r=-1;
        if (ktrdk(x1,y1+1,b))
        {
            k=a[x1][y1+1];
        }
        else k=-1;
        max2=max({h,z,r,k});
        if(max2==-1){break;}
        if (max2==h){b[x1-1][y1]=1;max1=a[x1-1][y1];nextX1=x1-1;nextY1=y1;}
        if (max2==z){b[x1+1][y1]=1;max1=a[x1+1][y1];nextX1=x1+1;nextY1=y1;}
        if (max2==r){b[x1][y1-1]=1;max1=a[x1][y1-1];nextX1=x1;nextY1=y1-1;}
        if (max2==k){b[x1][y1+1]=1;max1=a[x1][y1+1];nextX1=x1;nextY1=y1+1;}
        }
        x1=nextX1;    
        y1=nextY1;
        //B
    if (ktrdk(x2-1,y2,b) && a[x2 - 1][y2] > max3)
    {
        max3 = a[x2 - 1][y2];
        
        nextX2 = x2 - 1;
        nextY2 = y2;
    }
    if (  ktrdk(x2+1,y2,b)&&a[x2+ 1][y2] > max3&&x2<5)
    {
        max3 = a[x2 + 1][y2];
        nextX2 = x2 + 1;
        nextY2= y2;
    }
    if (ktrdk(x2,y2-1,b)&&a[x2][y2 - 1] > max3)
    {
        max3 = a[x2][y2 - 1];
        nextX2 = x2;
        nextY2 = y2 - 1;
    }
    if ( ktrdk(x2,y2+1,b)&&a[x2][y2 + 1] > max3&&y2<4)
    {
        max3 = a[x2][y2 + 1];
        nextX2 = x2;
        nextY2 = y2 + 1;
    }
    if (max3 == a[x2][y2]){
        if (ktrdk(x2-1,y2,b))
        {
            h=a[x2-1][y2];
        }
        else h=-1;
        if (ktrdk(x2+1,y2,b))
        {
            z=a[x2+1][y2];
        }
        else z=-1;
        if (ktrdk(x2,y2-1,b))
        {
            r=a[x2][y2-1];
        }
        else r=-1;
        if (ktrdk(x2,y2+1,b))
        {
            k=a[x2][y2+1];
        }
        else k=-1;
        max2=max({h,z,r,k});
        if(max2==-1){break;}
        if (max2==h){b[x2-1][y2]=1;max3=a[x2-1][y2];nextX2=x2-1;nextY2=y2;}
        if (max2==z){b[x2+1][y2]=1;max3=a[x2+1][y2];nextX2=x2+1;nextY2=y2;}
        if (max2==r){b[x2][y2-1]=1;max3=a[x2][y2-1];nextX2=x2;nextY2=y2-1;}
        if (max2==k){b[x2][y2+1]=1;max3=a[x2][y2+1];nextX2=x2;nextY2=y2+1;}
        }
        x2=nextX2;    
        y2=nextY2;
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
	int i, j,x1,y1,x2,y2;
    int b[6][5]={{2,1,14,12,17},{3,16,22,91,23},{4,56,87,31,65},{27,43,90,100,101},{76,54,32,99,66},{178,154,150,200,543}};
	int a[6][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	int c[6][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    int d[6][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    cout<<"Nhap toa do robot A ";cin>>x1>>y1;
    cout<<"Nhap toa do robot B ";cin>>x2>>y2;
    cout<<b[x1][y1]<<" ";
    moveRobot(b,a, x1, y1);
     cout<<endl;
      cout<<b[x2][y2]<<" ";
    moveRobot(b,c,x2,y2);
    cout<<endl;
    demdiemcatnhau(a,c);cout<<endl;
    moveRobotAB(b,d,x1,y1,x2,y2);
}