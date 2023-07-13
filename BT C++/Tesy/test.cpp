#include <iostream>
#include <algorithm>
using namespace std;

const int ROW = 6;
const int COL = 5;
int b[ROW][COL]={{2,1,14,12,17},{3,16,22,91,23},{4,56,87,31,65},{27,43,90,100,101},{76,54,32,99,66},{178,154,150,200,543}};

bool isValid(int x,int y){
    return (x>=0 && x<ROW && y>=0 && y<COL);
}

int maxVal(int x,int y){
    int maxV = -1;
    if(isValid(x-1,y) && b[x-1][y]>maxV) maxV = b[x-1][y];
    if(isValid(x+1,y) && b[x+1][y]>maxV) maxV = b[x+1][y];
    if(isValid(x,y-1) && b[x][y-1]>maxV) maxV = b[x][y-1];
    if(isValid(x,y+1) && b[x][y+1]>maxV) maxV = b[x][y+1];
    return maxV;
}

void moveRobot(int &x,int &y){
    int maxV = maxVal(x,y);
    if(isValid(x-1,y) && b[x-1][y]==maxV){
        x = x-1;
        return;
    }
    if(isValid(x+1,y) && b[x+1][y]==maxV){
        x = x+1;
        return;
    }
    if(isValid(x,y-1) && b[x][y-1]==maxV){
        y = y-1;
        return;
    }
    if(isValid(x,y+1) && b[x][y+1]==maxV){
        y = y+1;
        return;
    }
}

int main(){
    int xa,ya; // position of robot A
    int xb,yb; // position of robot B
    cout<<"Enter the position of robot A: ";
    cin>>xa>>ya;
    cout<<"Enter the position of robot B: ";
    cin>>xb>>yb;

    int sumA=b[xa][ya],sumB=b[xb][yb];
    cout<<"Robot A: "<<b[xa][ya]<<" ";
    cout<<"Robot B: "<<b[xb][yb]<<" ";
    while(true){
        moveRobot(xa,ya);
        if(b[xa][ya]==0 || (xa==xb && ya==yb)) break;
        sumA+=b[xa][ya];
        cout<<b[xa][ya]<<" ";
        b[xa][ya]=0;

        moveRobot(xb,yb);
        if(b[xb][yb]==0 || (xa==xb && ya==yb)) break;
        sumB+=b[xb][yb];
        cout<<endl<<"Robot B: "<<b[xb][yb]<<" ";
        b[xb][yb]=0;
    }
    cout<<endl;

    cout<<"Sum of robot A: "<<sumA<<endl;
    cout<<"Sum of robot B: "<<sumB<<endl;

    if(sumA>sumB) cout<<"Robot A wins"<<endl;
    else if(sumA<sumB) cout<<"Robot B wins"<<endl;
    else cout<<"Draw"<<endl;

}