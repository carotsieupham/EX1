#include "listpoint.h"

void listpoint::readfile(string filename)
{
	list.clear();
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
		point* p = new point();
		p->docfile(ifs);
		list.push_back(*p);
	}
	cout << "Doc file thanh cong" << endl;
	ifs.close();
}

void listpoint::print()
{
	cout << "Danh sach cac diem:";
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] <<" ";
	}
	cout << endl;
}

void listpoint::sortlist()
{
	sort(list.begin(), list.end());
}

