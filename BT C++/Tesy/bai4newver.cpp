#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;
struct Point {
    int x;
    int y;
    friend istream& operator>>(istream& is, Point& a) {
        is >> a.x;
        is >> a.y;
        return is;
    }
};
int Menu() {
    int choose;
    cout << "======MENU======" << endl;
    cout << "1.Play" << endl;
    cout << "2.Quit" << endl;
    cout << "Lua chon cua ban:";
    cin >> choose;
    return choose;
}
int Menu_mode() {
    int choose;
    cout << "======MODE======" << endl;
    cout << "1.In quang duong robot di qua" << endl;
    cout << "2.Tim so diem cat nhau cua 2 robot" << endl;
    cout << "3.Doi khang" << endl;
    cout<<"4.Dau voi may"<<endl;
    cout << "Lua chon cua ban:";
    cin >> choose;
    return choose;
}
bool ktrdk(int x, int y, int** b, int m, int n) {
    if (x >= 0 && x < m && y >= 0 && y < n && b[x][y] == 0) {
        return true;
    } else {
        return false;
    }
}
void Taomtr(int**& a, int m, int n) {
    srand(time(NULL));
    a = new int*[m];
    for (int i = 0; i < m; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) {
            int num;
            bool duplicate;
            do {
                num = rand() % 101; // Tạo số nguyên ngẫu nhiên từ 0 đến 100
                duplicate = false; // Kiểm tra số đã tồn tại trong ma trận chưa
                for (int k = 0; k < i; k++) {
                    for (int l = 0; l < n; l++) {
                        if (a[k][l] == num) {
                            duplicate = true;
                            break;
                        }
                    }
                    if (duplicate) {
                        break;
                    }
                }
            } while (duplicate);
            a[i][j] = num;
        }
    }
}
void Inmtr(int** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
void Taomatran0(int** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
}
void demdiemcatnhau(int** a, int** b, int** c, int m, int n) {
    int i, j, count = 0;
    cout << "Cac diem robot cat nhau:" << endl;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (b[i][j] == 1 && c[i][j] == 1) {
                cout << a[i][j] << " ";
                count++;
            }
        }
    }
    cout << endl;
    cout << "So diem cat nhau cua 2 robot: " << count << endl;
}
void Ai(Point &a,Point &b,int m,int n){
    srand(time(NULL));
    do{ a.x=rand()% m;
        a.y=rand()% n;}while(a.x==b.x && a.y==b.y);
}
int moveRobot(int** a,int** b, Point &c,int m ,int n)
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
void Mode1(int** a, int** b,Point &d,int m, int n){
    int max,moveCount=0;
    Taomtr(a,m,n);
    Inmtr(a,m,n);
    Taomatran0(b,m,n);
    do{cout<<"Nhap tao do dat robot:";cin>>d;} while (d.x>=m||d.y>=n);
    cout<<"Quang duong robot di qua"<<endl;
    b[d.x][d.y]=1;
    max=a[d.x][d.y];
    while (max!=-1)
    {   
        cout<<max<<"->";max=moveRobot(a,b,d,m,n);
        moveCount++;
    }
    cout<<"END"<<endl;
    cout << "Tong so luot di chuyen cua robot: " << moveCount << endl;
}
void Mode2(int** a,int** b,int** c,Point &d, Point &e,int m,int n){
    int max,max1,moveCount1=0,moveCount2=0;
    Taomtr(a,m,n);
    Inmtr(a,m,n);
    Taomatran0(b,m,n);
    Taomatran0(c,m,n);
    do{cout<<"Nhap toa do robot A:";cin>>d;}while(d.x>=m ||d.y>=n);
    do{cout<<"Nhap toa do robot B:";cin>>e;}while(e.x>=m||e.y>=n);
    cout<<"Quang duong robot A di qua:"<<endl;
    b[d.x][d.y]=1;
    max=a[d.x][d.y];
    while (max!=-1)
    {
        cout<<max<<"->";max=moveRobot(a,b,d,m,n);
        moveCount1++;
    }
    cout<<"END"<<endl;
    cout << "Tong so luot di chuyen cua robot A: " << moveCount1 << endl;
    cout<<"Quang duong robot B di qua:"<<endl;
    max1=a[d.x][d.y];
    c[d.x][d.y]=1;
    while (max1!=-1)
    {
        cout<<max1<<"->";max1=moveRobot(a,c,e,m,n);
        moveCount2++;
    }  
    cout<<"END"<<endl;
    cout << "Tong so luot di chuyen cua robot B: " << moveCount2 << endl;
    demdiemcatnhau(a,b,c,m,n);
}
void Mode3(int** a,int** b,Point &d, Point &e,int m,int n){
    int max,max1,s1=0,s2=0,moveCountA=0,moveCountB=0;
    Taomatran0(b,m,n);
    max=a[d.x][d.y];
    max1=a[e.x][e.y];
    b[d.x][d.y]=1;
    b[e.x][e.y]=1;              
    do{
    if(max!=-1){
        cout<<"Robot A:"<<max<<" ";
        s1+=max;
        max=moveRobot(a,b,d,m,n);
        moveCountA++;
    }
    else{ cout<<"Robot A:"<<"  ";}              
    if(max1!=-1){
        cout<<"Robot B:"<<max1<<endl;
        s2+=max1;
        max1=moveRobot(a,b,e,m,n);
        moveCountB++;
    }
    else { cout<<"Robot B:"<<" "<<endl;}
    }while(max!=-1 ||max1!=-1);
    cout<<endl;
    cout << "Tong so luot di chuyen cua robot A: " << moveCountA <<","<<"Tong so luot di chuyen cua robot B: "<<moveCountB<<endl;
    cout<<"Tong so cua robot A:"<<s1<<endl;
    cout<<"Tong so cua robot B:"<<s2<<endl;
    if(s1>s2){cout<<"A la ng thang";}
    else if(s1<s2){cout<<"B la ng thang";}
    else cout<<"A hoa B";
    cout<<endl;
}
void Mode4(int** a,int** b,Point &d, Point &e,int m,int n){
    Taomtr(a,m,n);
    Inmtr(a,m,n);
    do{cout<<"Nhap toa do robot cua ban:";cin>>d;}while(d.x>=m||d.y>=n);
    Ai(e,d,m,n);
    cout<<"Toa do robot cua may:"<<"("<<e.x<<","<<e.y<<")"<<endl;
    Mode3(a,b,d,e,m,n);
}
int main(){
	int m,n,choose;
    Point d,e;
    while (true) {
    choose = Menu();
    system("cls");
    switch (choose) {
        case 1:
            choose = Menu_mode();;
            system("cls");
            switch (choose) {
                case 1: {
                    cout << "Nhap kich thuoc me cung mxn: "; cin >> m >> n;
                    int** a = new int*[m];
                    int** b = new int*[m];
                    for (int i = 0; i < m; i++) {
                        a[i] = new int[n];
                        b[i] = new int[n];
                    }
                    Mode1(a, b, d, m, n);
                    for (int i = 0; i < m; i++) {
                        delete[] a[i];
                        delete[] b[i];
                    }
                    delete[] a;
                    delete[] b;
                    break;
                }
                case 2: {
                    cout << "Nhap kich thuoc me cung mxn: "; cin >> m >> n;
                    int** a = new int*[m];
                    int** b = new int*[m];
                    int** c = new int*[m];
                    for (int i = 0; i < m; i++) {
                        a[i] = new int[n];
                        b[i] = new int[n];
                        c[i] = new int[n];
                    }
                    Mode2(a, b, c, d, e, m, n);
                    for (int i = 0; i < m; i++) {
                        delete[] a[i];
                        delete[] b[i];
                        delete[] c[i];
                    }
                    delete[] a;
                    delete[] b;
                    delete[] c;
                    break;
                }
                case 3: {
                    cout << "Nhap kich thuoc me cung mxn: "; cin >> m >> n;
                    int** a = new int*[m];
                    int** b = new int*[m];
                    for (int i = 0; i < m; i++) {
                        a[i] = new int[n];
                        b[i] = new int[n];
                    }
                    Taomtr(a,m,n);
                    Inmtr(a,m,n);
                    do{cout<<"Nhap toa do robot A:";cin>>d;}while(d.x>=m ||d.y>=n);
                    do{cout<<"Nhap toa do robot B:";cin>>e;}while(e.x>=m||e.y>=n);
                    Mode3(a, b, d, e, m, n);
                    for (int i = 0; i < m; i++) {
                        delete[] a[i];
                        delete[] b[i];
                    }
                    delete[] a;
                    delete[] b;
                    break;
                }
                case 4:{
                    cout << "Nhap kich thuoc me cung mxn: "; cin >> m >> n;
                    int** a = new int*[m];
                    int** b = new int*[m];
                    for (int i = 0; i < m; i++) {
                        a[i] = new int[n];
                        b[i] = new int[n];
                    }
                    Mode4(a,b,d,e,m,n);
                    for (int i = 0; i < m; i++) {
                        delete[] a[i];
                        delete[] b[i];
                    }
                    delete[] a;
                    delete[] b;
                    break;
                }
                default:
                    cout << "Nhap sai" << endl;
                    break;
            }
            break;
        case 2:
            cout << "Bye Bye" << endl;
            break;
        default:
            cout << "Nhap sai" << endl;
            break;
    }
    cout << "Ban co muon tiep tuc khong (1/0): ";
    bool iscontinue;
    cin >> iscontinue;
    system("cls");
    if (!iscontinue) {
        cout << "Bye";
        break;
    }
}
return 0;
}