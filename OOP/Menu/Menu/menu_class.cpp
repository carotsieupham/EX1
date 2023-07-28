#include "menu.h"
menu& menu::operator<<(const string& option)
{
    cout << *this;
	return *this;
}

void menu::xuat()
{

	cout << "\n-----" << "Menu" << "-----\n";
	for (int i = 0; i < dsLuachon.size(); i++)
		cout << i << ". " << dsLuachon[i] << endl;
}

int menu::chon()
{
    int ch;
    do {
        xuat();
        cout << "Moi chon?";
        cin >> ch;
        //xoa ky tu xuong dong de cac lenh getline sau nay khong bi anh huong
        string tmp;
        getline(cin, tmp);
        if (ch < 0 || ch >= dsLuachon.size())
            cout << "Chon sai, moi chon lai!!!\n";
    } while (ch < 0 || ch >= dsLuachon.size());//Lap lai neu user chon sai
    return ch;
}
ostream& operator<<(ostream& os, menu a)
{
    os << a;
    return os;
}