
#include <iostream>
#include "sv.h"
#include"dssv.h"
#include"Menu.h"
using namespace std;
int main()
{
	dssv ds;
	Menu m;
	string filename;
	cout << "Chuong trinh quan ly sinh vien" << endl;
	m.add_item("Thoat chuong trinh");
	m.add_item("Tao danh sach moi");
	m.add_item("Nhap danh sach sinh vien");
	m.add_item("In danh sach sinh vien");
	m.add_item("In danh sach sinh vien du dieu kien");
	m.add_item("In danh sach sinh vien co ho Nguyen");
	m.add_item("In danh sach sinh vien trung ten");
	m.add_item("Luu file");
	m.add_item("Doc file");
    while (true) {

		switch (m.choose())
		{
		case 0:
			cout << "Bye Bye!" << endl;
			return 0;
			break;
		case 1:
			ds.create();
			break;
		case 2:
			ds.add();
			break;
		case 3:
			ds.print();
			break;
		case 4:
			ds.danhSachSvDuDk();
			break;
		case 5:
			ds.danhSachSvHoNguyen();
			break;
		case 6:
			ds.danhSachSvCungTen();
			break;
		case 7:
			cout << "Nhap ten file: ";
			getline(cin, filename);
			ds.savefile(filename);
			break;
		case 8:
			cout << "Nhap ten file: ";
			getline(cin, filename);
			ds.readfile(filename);
			break;
		default:
			break;
		}
    }
}


