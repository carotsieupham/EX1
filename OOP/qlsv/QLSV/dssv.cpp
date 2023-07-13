#include "dssv.h"

void dssv::create()
{
	dssv.clear();
	cout << "Danh sach duoc tao thanh cong!" << endl;
}

void dssv::add()
{
	int quantity;
	sv* svien = new sv();
	cout << "So luong sinh vien :";
	cin >> quantity;
	for (int i = 0; i < quantity; i++)
	{
		cout << "Nhap sinh vien thu " << i + 1 << ":" << endl;
		cin >> *svien ;
		dssv.push_back(*svien);
	}
}

void dssv::print()
{
	cout << "Danh sach sinh vien " << endl;
	cout << setw(30) << left << "Ho ten" << "\t" << setw(12) << left << "Ma sinh vien" << "\t" << setw(4) << left << "Buoi vang" << "\t" << setw(4) << left << "Diem thuc hanh" << "\t" << setw(4) << left << "Diem giua ki" << "\t" << setw(4) << left << "Diem qua trinh" << endl;
	for (int i = 0; i < dssv.size(); i++)
	{
		dssv[i].hienthiTTSV();
	}
}

void dssv::danhSachSvDuDk()
{
	cout << "Danh sach sinh vien du dieu kien" << endl;
	cout << setw(30) << left << "Ho ten" << "\t" << setw(12) << left << "Ma sinh vien" << "\t" << setw(4) << left << "Buoi vang" << "\t" << setw(4) << left << "Diem thuc hanh" << "\t" << setw(4) << left << "Diem giua ki" << "\t" << setw(4) << left << "Diem qua trinh" << endl;
	for (int i = 0;i < dssv.size();i++)
	{
		if (dssv[i].TinhDiemQT() >= 3) {
			dssv[i].hienthiTTSV();
		}
	}
}

void dssv::danhSachSvHoNguyen()
{
	int count = 0;
	cout << "Danh sach sinh vien ho Nguyen" << endl;
	cout << setw(30) << left << "Ho ten" << "\t" << setw(12) << left << "Ma sinh vien" << "\t" << setw(4) << left << "Buoi vang" << "\t" << setw(4) << left << "Diem thuc hanh" << "\t" << setw(4) << left << "Diem giua ki" << "\t" << setw(4) << left << "Diem qua trinh" << endl;
	for (int i = 0;i < dssv.size();i++)
	{
		if ((dssv[i].get_name()).find("Nguyen") != string::npos || (dssv[i].get_name()).find("nguyen") != string::npos) {
			dssv[i].hienthiTTSV();
			count++;
		}
	}
	if (count == 0) cout << "Khong co sinh vien nao mang ho Nguyen" << endl;
}

void dssv::danhSachSvCungTen()
{
	int tmp=-1,count=0;
	cout << "Danh sach sinh vien trung ten" << endl;
	cout << setw(30) << left << "Ho ten" << "\t" << setw(12) << left << "Ma sinh vien" << "\t" << setw(4) << left << "Buoi vang" << "\t" << setw(4) << left << "Diem thuc hanh" << "\t" << setw(4) << left << "Diem giua ki" << "\t" << setw(4) << left << "Diem qua trinh" << endl;
	for (int i = 0; i < dssv.size(); i++) {
		for (int j = i + 1; j < dssv.size(); j++) {
			if (trungten(dssv[i], dssv[j])) {
				if (tmp == i) {
					dssv[j].hienthiTTSV();
					count++;
				}
				else
				{
					dssv[i].hienthiTTSV();
					dssv[j].hienthiTTSV();
					count++;
					tmp = i;
				}
			}
		}
	}
	if (count == 0) cout << "Trong" << endl;
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
}

void dssv::readfile(string filename)
{
	system("cls");
	ifstream ifs(filename);
	if (!ifs.is_open()) {
		cout << "Khong mo duoc file" << endl;return;
	}
	int n;
	ifs >> n;
	string skipendl;
	getline(ifs, skipendl);
	for (int i = 0; i < n; i++)
	{
		sv* svien = new sv();
		svien->docfile(ifs);
		dssv.push_back(*svien);
	}
	cout << "Doc file thanh cong" << endl;
	ifs.close();

}
