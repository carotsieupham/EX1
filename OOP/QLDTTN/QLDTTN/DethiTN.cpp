#include "DethiTN.h"
void DethiTN::create()
{
	system("cls");
	dethi.clear();
	cout << "De moi da duoc tao" << endl;
	system("pause");
}

void DethiTN::add()
{
	system("cls");
		int n;
		cout << "Nhap so luong cau hoi trong de thi:";cin >> n;
		CauhoiTN* cauhoi = new CauhoiTN();
		for (int i = 0; i < n; i++)
		{
			cin.ignore();
			cauhoi->nhap();
			dethi.push_back(*cauhoi);
		}
		system("pause");
}
void DethiTN::print()
{
	system("cls");
	cout <<setw(50) <<"De thi" << endl;
	if (dethi.size() > 0) {
		for (int i = 0; i < dethi.size();i++)
		{	
			cout << "Cau " << i + 1 << ": ";
			dethi[i].xuat();
		}
	}
	else cout << "Trong" << endl;
	system("pause");
	
}

void DethiTN::savefile(string filename)
{
	system("cls");
	ofstream ofs(filename);
	if (!ofs.is_open()) {
		cout << "Khong mo duoc file" << endl;return;
	}
	ofs << dethi.size()<<endl;
	for (int i = 0; i < dethi.size(); i++)
	{
		dethi[i].ghifile(ofs);
	}
	cout << "Luu file thanh cong" << endl;
	ofs.close();
	system("pause");

}

void DethiTN::readfile(string filename)
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
		CauhoiTN* cauhoi = new CauhoiTN();
		cauhoi->docfile(ifs);
		dethi.push_back(*cauhoi);
	}
	cout << "Doc file thanh cong" << endl;
	ifs.close();
	system("pause");
}

void DethiTN::start()
{
	system("cls");
	int count = 0;
	cout << setw(50) << "=========Bat dau thi=========" << endl;
	for (int i = 0; i < dethi.size(); i++)
	{
		cout << "Cau " << i + 1 << ": ";
		if (dethi[i].kiemtra()) {
			count++;
		}
	}
	cout << "Bai thi da hoan thanh!" << endl;
	cout << "Total: " << count <<"/"<<dethi.size()<<endl;;
	system("pause");
}

void DethiTN::deletesameqs()
{
	int i=0;
	int h = dethi.size() - 1;
	while ( i <h )
	{
		int j = i + 1;
		while (j < dethi.size()) {
			if (giongnhau(dethi[i], dethi[j])) {
				dethi.erase(dethi.begin() + j);
			}
			else j++;
		}
		i++;
	}
}
