#include "CauhoiTN.h"
#include "DethiTN.h"
#include "Menu.h"
int main() {
	DethiTN dethi;
	Menu menu;
	string filename;
	cout << setw(50) << "---Chuong trinh quan ly de thi---TranMinhTri---2251150039" << endl;
	menu.add_item("Thoat chuong trinh");
	menu.add_item("Tao de thi trac nghiem moi");
	menu.add_item("Them cau hoi");
	menu.add_item("In danh sach cau hoi hien co trong de thi");
	menu.add_item("Luu de thi vao file");
	menu.add_item("Doc de thi tu file");
	menu.add_item("Cho thi");
	
	while (true)
	{
		switch (menu.choose()) {
		case 0:
			cout << "Bye Bye" << endl;
			return 0;
			break;
		case 1:
			dethi.create();
			break;
		case 2:
			dethi.add();
			break;
		case 3:
			dethi.deletesameqs();
			dethi.print();
			break;
		case 4:
			cout << "Nhap ten file: ";getline(cin, filename);
			dethi.savefile(filename);
			break;
		case 5:
			cout << "Nhap ten file: ";getline(cin, filename);
			dethi.readfile(filename);
			break;
		case 6:
			dethi.start();
			break;
		default:
			cout << "Lua chon sai" << endl;
			break;
		}
	}

}