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