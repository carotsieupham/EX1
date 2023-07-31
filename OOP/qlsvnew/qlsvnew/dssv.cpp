#include "dssv.h"

void dssv::create()
{
	system("cls");
	dssv.clear();
	cout << "Danh sach duoc tao thanh cong!" << endl;
	system("pause");
}

void dssv::add()
{
	system("cls");
	
	int quantity;
	sv* svien = new sv();
	cout << "So luong sinh vien :";
	cin >> quantity;
	for (int i = 0; i < quantity; i++)
	{
		cout << "Nhap sinh vien thu " << i + 1 << ":" << endl;
		cin >> *svien;
		dssv.push_back(*svien);
	}
	system("pause");

}

void dssv::print()
{
	system("cls");
	int index = 3;
	cout << "Danh Sach Sinh Vien"<<endl;
	box(0, 1, dssv.size()+2,98);
	gotoXY(1, 2);cout << "Ho va ten";gotoXY(31, 2);cout << "Ma sinh vien";gotoXY(44, 2);cout << "Buoi vang";gotoXY(54, 2);cout << "Diem thuc hanh";gotoXY(69, 2);cout << "Diem giua ky";gotoXY(84, 2);cout << "Diem thuc hanh";
	cout << endl;
	for (int i = 0; i < dssv.size(); i++)
	{
		dssv[i].hienthiTTSV(index);cout <<endl;
	}
	
	gotoXY(0, 1 + dssv.size() + 3);
	system("pause");
}
void dssv::danhSachSvDuDk()
{
	system("cls");
	int index = 3;
	int count = 0;
	gotoXY(0, 0);
	cout << "Danh sach sinh vien du dieu kien" << endl;
	gotoXY(1, 2);cout << "Ho va ten";gotoXY(31, 2);cout << "Ma sinh vien";gotoXY(44, 2);cout << "Buoi vang";gotoXY(54, 2);cout << "Diem thuc hanh";gotoXY(69, 2);cout << "Diem giua ky";gotoXY(84, 2);cout << "Diem thuc hanh";
	for (int i = 0;i < dssv.size();i++)
	{
		if (dssv[i].TinhDiemQT() >= 3) {
			dssv[i].hienthiTTSV(index);
			count++;
		}
	}
	box(0, 1, count + 2, 98);
	system("pause");
	gotoXY(0 , 1 + count + 3);
}

void dssv::danhSachSvHoNguyen()
{
	system("cls");
	int count = 0;
	int index = 3;
	cout << "Danh sach sinh vien ho Nguyen" << endl;
	gotoXY(1, 2);cout << "Ho va ten";gotoXY(31, 2);cout << "Ma sinh vien";gotoXY(44, 2);cout << "Buoi vang";gotoXY(54, 2);cout << "Diem thuc hanh";gotoXY(69, 2);cout << "Diem giua ky";gotoXY(84, 2);cout << "Diem thuc hanh";
	for (int i = 0;i < dssv.size();i++)
	{
		if ((dssv[i].get_familyname()).find("Nguyen") != string::npos || (dssv[i].get_familyname()).find("nguyen") != string::npos) {
			dssv[i].hienthiTTSV(index);
			count++;
		}
	};
	box(0, 1, count + 2, 98);
	if (count == 0) cout << "Khong co sinh vien nao mang ho Nguyen" << endl;
	gotoXY(0 , 1 + count + 3);
	system("pause");
}

void dssv::danhSachSvCungTen()
{
	system("cls");
	int index = 3;
	int size=dssv.size();
	set<int>temp;
	cout << "Danh sach sinh vien trung ten" << endl;
	gotoXY(1, 2);cout << "Ho va ten";gotoXY(31, 2);cout << "Ma sinh vien";gotoXY(44, 2);cout << "Buoi vang";gotoXY(54, 2);cout << "Diem thuc hanh";gotoXY(69, 2);cout << "Diem giua ky";gotoXY(84, 2);cout << "Diem thuc hanh";
	for (int i = 0; i < dssv.size(); i++) {
		for (int j = i + 1;j < dssv.size();j++) {
			if (trungten(dssv[i], dssv[j])) {
				temp.insert(i);
				temp.insert(j);
			}
		}
	}
	for (auto it = temp.begin(); it != temp.end(); ++it){
		dssv[*it].hienthiTTSV(index);
	}
	box(0, 1, temp.size() + 2, 98);
	if (temp.size() == 0) cout << "Trong" << endl;
	gotoXY(0, 1+temp.size()+3);
	system("pause");
}

void dssv::savefile(string filename)
{
	system("cls");
	ofstream ofs(filename);
	if (!ofs.is_open()) {
		cout << "Khong mo duoc file" << endl;return;
	}
	ofs << dssv.size() << endl;
	for (int i = 0; i < dssv.size(); i++)
	{
		dssv[i].ghifile(ofs);
	}
	cout << "Luu file thanh cong" << endl;
	ofs.close();
	system("pause");
}

void dssv::readfile(string filename)
{
	system("cls");
	dssv.clear();
	ifstream ifs(filename);
	if (!ifs.is_open()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	int n;
	ifs >> n;
	ifs.ignore();
	for (int i = 0; i < n; i++)
	{
		sv* svien = new sv();
		svien->docfile(ifs);
		dssv.push_back(*svien);
	}
	cout << "Doc file thanh cong" << endl;
	ifs.close();
	system("pause");
}