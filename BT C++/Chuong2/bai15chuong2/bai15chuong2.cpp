#include <iostream>
using namespace std;
#include <cstdlib>


int main()
{ int player1,player2;
	cout<<"1.Bua 2.Bao 3.Keo"<<endl;
     cout << "Player 01 Chon So Tuong Ung: ";
    cin >> player1;
    cout << "PLayer 02 Chon So Tuong Ung: ";
    cin >> player2;
    if (player1== 1 && player2==2){
        cout<<"Player 2 win";
    }
    else if(player1==3 && player2==1){
        cout<<"Player 2 win";
    }
    else if(player1==2 && player2==3){
        cout<<"Player 2 win";
    }
    else if(player1==player2){
        cout<<"Draw";
    }
    else{
        cout<<"Player 1 win";
    }
	return 0;
}