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
	cout <<  "Danh sach sinh vien " << endl;
	cout << "+-------------------------------+---------------+---------------+---------------+---------------+---------------+" << endl;
	cout << "|"<<setw(28) << left << "Ho ten" << "\t" << "|" << setw(10) << left << "Ma sinh vien" << "\t" << "|" << setw(4) << left << "Buoi vang" << "\t" << "|" << setw(4) << left << "Diem thuc hanh" << "\t" << "|" << setw(4) << left << "Diem giua ki" << "\t" << "|" << setw(4) << left << "Diem qua trinh" << "\t" << "|" << endl;
	for (int i = 0; i < dssv.size(); i++)
	{
		cout << "|";dssv[i].hienthiTTSV();cout << "|" << endl;
	}
	cout << "+-------------------------------+---------------+---------------+---------------+---------------+---------------+" << endl;
	system("pause");
}

void dssv::danhSachSvDuDk()
{
	system("cls");
	cout   << "Danh sach sinh vien du dieu kien"  << endl;
	cout << "+-------------------------------+---------------+---------------+---------------+---------------+---------------+" << endl;
	cout << "|" << setw(28) << left << "Ho ten" << "\t" << "|" << setw(10) << left << "Ma sinh vien" << "\t" << "|" << setw(4) << left << "Buoi vang" << "\t" << "|" << setw(4) << left << "Diem thuc hanh" << "\t" << "|" << setw(4) << left << "Diem giua ki" << "\t" << "|" << setw(4) << left << "Diem qua trinh" << "\t" << "|" << endl;
	for (int i = 0;i < dssv.size();i++)
	{
		if (dssv[i].TinhDiemQT() >= 3) {
			cout << "|";dssv[i].hienthiTTSV();cout << "|" << endl;
		}
	}
	cout << "+-------------------------------+---------------+---------------+---------------+---------------+---------------+" << endl;
	system("pause");

}

void dssv::danhSachSvHoNguyen()
{
	system("cls");
	int count = 0;
	cout << "Danh sach sinh vien ho Nguyen" << endl;
	cout << "+-------------------------------+---------------+---------------+---------------+---------------+---------------+" << endl;
	cout << "|" << setw(28) << left << "Ho ten" << "\t" << "|" << setw(10) << left << "Ma sinh vien" << "\t" << "|" << setw(4) << left << "Buoi vang" << "\t" << "|" << setw(4) << left << "Diem thuc hanh" << "\t" << "|" << setw(4) << left << "Diem giua ki" << "\t" << "|" << setw(4) << left << "Diem qua trinh" << "\t" << "|" << endl;
	for (int i = 0;i < dssv.size();i++)
	{
		if ((dssv[i].get_name()).find("Nguyen") != string::npos || (dssv[i].get_name()).find("nguyen") != string::npos) {
			cout << "|";dssv[i].hienthiTTSV();cout << "|" << endl;
			count++;
		}
	}
	cout << "+-------------------------------+---------------+---------------+---------------+---------------+---------------+" << endl;
	if (count == 0) cout << "Khong co sinh vien nao mang ho Nguyen" << endl;
	system("pause");
}

void dssv::danhSachSvCungTen()
{
	system("cls");
	int tmp = -1, count = 0;
	cout <<  "Danh sach sinh vien trung ten" <<  endl;
	cout << "+-------------------------------+---------------+---------------+---------------+---------------+---------------+" << endl;
	cout << "|" << setw(28) << left << "Ho ten" << "\t" << "|" << setw(10) << left << "Ma sinh vien" << "\t" << "|" << setw(4) << left << "Buoi vang" << "\t" << "|" << setw(4) << left << "Diem thuc hanh" << "\t" << "|" << setw(4) << left << "Diem giua ki" << "\t" << "|" << setw(4) << left << "Diem qua trinh" << "\t" << "|" << endl;
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
	if (count == 0) cout <<"|"<< "Trong" << endl;
	cout << "+-------------------------------+---------------+---------------+---------------+---------------+---------------+" << endl;
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