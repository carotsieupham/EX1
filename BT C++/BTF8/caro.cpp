#include<iostream>
using namespace std;
struct point{
    int x;
    int y;
    friend istream& operator>>(istream& is,point& a){
        cout<<"Nhap o muon di:";
        is>>a.x>>a.y;
        return is;
    }
};
int menu(){
    int chose;
    cout<<"=====MENU====="<<endl;
    cout<<"1.Play"<<endl;
    cout<<"2.Quit game"<<endl;
    cout<<"Your choice:";cin>>chose;
    return chose;
}
void player1(char a[3][3],point b){
    
    if (b.x >= 0 && b.x < 3 && b.y >= 0 && b.y < 3) {
        a[b.x][b.y]='O';
    } else {
        cout << "Vi tri khong hop le!" << endl;
    }
}
void player2(char a[3][3],point b){
    
    if (b.x >= 0 && b.x < 3 && b.y >= 0 && b.y < 3) {
        a[b.x][b.y]='X';
    } else {
        cout << "Vi tri khong hop le!" << endl;
    }
}
void printmap(char a[3][3]){
    for (int i = 0; i < 3; i++)
    {for ( int j = 0; j < 3; j++){
        cout<< a[i][j]<<" "; }
	cout<<"\n";
    }}
int checked1(char a[3][3]){
    for (int i = 0; i < 3; i++) {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] == 'O') {
            return 1;
        }
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] == 'O') {
            return 1;
        }
    }
    if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] == 'O') {
        return 1;
    }
    if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] == 'O') {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != ' ') {
                count++;
            }
        }
    }
    if (count == 9) {
        return 2;
    } 
}
int checked2(char a[3][3]){
    for (int i = 0; i < 3; i++) {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] == 'X') {
            return 1;
        }
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] == 'X') {
            return 1;
        }
    }
    if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] == 'X') {
        return 1;
    }
    if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] == 'X') {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != ' ') {
                count++;
            }
        }
    }
    if (count == 9) {
        return 2;
    }
}
void reset(char a[3][3]){
    for (int i = 0; i < 3; i++)
    {for ( int j = 0; j < 3; j++){
        a[i][j]=' '; }
    }}
int main(){
    int chose,check1,check2;
    point a,c;
    char b[3][3]={ {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    
	bool is_continue = true;
	while (is_continue)
	{   int chose=menu();
		system("cls");
		switch (chose)
		{
		case 1:
			//Play
			while (true)
			{   system("cls");
                printmap(b);
                cout<<"Nguoi choi 1"<<endl;cin>>a;
			   player1(b,a);
			   printmap(b);
			   check1= checked1(b);
			   if(check1==1){ cout<<"Player 1 win"<<endl;reset(b);break;}
                if(check1==2){cout<<"Draw"<<endl;reset(b);break;}
                cin.ignore();
               cout<<"Nguoi choi 2"<<endl;cin>>c; 
			   player2(b,c);
               printmap(b);
               check2= checked2(b);
                if(check2==1){ cout<<"Player 2 win"<<endl;reset(b);break;}
                if(check2==2){cout<<"Draw"<<endl;reset(b);break;}
			}
			break;
		case 2:
			cout<<"Bye see you next time"<<endl;
		default:
			cout<<"Khon co lua chon nay"<<endl;
			break;
		}
		cout << "Ban co muon tiep tuc khong(1/0):";
		cin >> is_continue;
	}
	cout << "Bye Bye" << endl;
}
