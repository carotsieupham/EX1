// MSSV_Bieuthuc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BieuthucSohoc.h"
#include "BieuthucCong.h"
#include "BieuthucTru.h"
#include "BieuthucNhan.h"
#include <vector>
#include <time.h>
using namespace std;
vector<BieuthucSohoc> sinhDethi(int n1, int n2, int n3, int level)
{
	vector<BieuthucSohoc> dethi;
	for (int i = 0; i < n1; i++)
	{
		BieuthucCong* bt = new BieuthucCong();
		bt->SinhBieuThuc(level);
		dethi.push_back(*bt);
	}
	for (int i = 0; i < n2; i++)
	{
		BieuthucTru* bt = new BieuthucTru();
		bt->SinhBieuThuc(level);
		dethi.push_back(*bt);
	}
	for (int i = 0; i < n3; i++)
	{
		BieuthucNhan* bt = new BieuthucNhan();
		bt->SinhBieuThuc(level);
		dethi.push_back(*bt);
	}
	return dethi;
}

vector<BieuthucSohoc> sinhDethi_v2(int n1, int n2, int n3, int level)
{
	vector<BieuthucSohoc> dethi;
	int tongsocau = n1 + n2 + n3;
	int socauCong = 0;
	int socauTru = 0;
	int socauNhan = 0;
	for (int i = 0;i < tongsocau;i++)
	{
		BieuthucSohoc* bt=NULL;
		int t = rand() % 3;
		do
		{
			if (t == 0)
				if (socauCong <= n1)
				{
					bt = new BieuthucCong();
					socauCong++;
				}
				else
					t = t + 1;
			if (t == 1)
				if (socauTru <= n2)
				{
					bt = new BieuthucTru();
					socauTru++;
				}
				else
					t = t + 1;
			if (t == 2)
				if (socauNhan <= n3)
				{
					bt = new BieuthucNhan();
					socauNhan++;
				}
				else
					t = -1;
		} while (t == -1);
		bt->SinhBieuThuc(level);
		dethi.push_back(*bt);
	}
	return dethi;
}


int main()
{
	srand(time(NULL)); //Khoi tao bo sinh so ngau nhien
	/*
    std::cout << "MSSV - Demo Cau a\n";
	BieuthucSohoc bt1, bt2;
	int dapan1, dapan2;
	cin >> bt1;
	cout << bt1;
	cin >> dapan1;
	if (bt1.KiemTra(dapan1))
		cout << "Ban da tra loi dung!";
	else
		cout << "Ban da tra loi sai!!!";
	//Sinh ngau nhien
	cout << "\nNhap cap do de sinh bieu thuc: ";
	int level;
	cin >> level;
	bt2.SinhBieuThuc(level);
	cout << bt2;
	cin >> dapan2;
	if (bt2.KiemTra(dapan2))
		cout << "Ban da tra loi dung!";
	else
		cout << "Ban da tra loi sai!!!";
	//
	*/
	/*
	cout << "MSSV _ Demo cau b\n";
	BieuthucCong btc;
	cout << "Nhap cap do: ";
	int level;
	cin >> level;
	btc.SinhBieuThuc(level);
	cout << btc;
	*/

	/*
	cout << "MSSV -  Demo cau b \n";
	//Sinh ngau nhien cac cau hoi, hien thi cap do kho va so diem hien tai
	int level = 1;
	int socauhoi = 3; // so cau hoi o moi cap do
	int sodiem = 0;
	BieuthucSohoc bt;
	int traloi;
	do
	{
		cout << "Level " << level << "; Diem " << sodiem << endl;
		bt.SinhBieuThuc(level);
		cout << bt;
		cin >> traloi;
		if (bt.KiemTra(traloi))
		{
			sodiem++;
			if (sodiem >= socauhoi)
			{
				level++; sodiem = 0;
			}
		}
		else
		{
			sodiem--;
			if (sodiem < 0)
			{
				level--; sodiem = 0;
			}
		}

	} while (level>0 && level <= 5);
	if (level == 0)
		cout << "Ban da thua!!!\n";
	else
		cout << "Ban da chien thang!!!\n";

	*/
	cout << "Demo cau d\n";
	vector<BieuthucSohoc> dethi;
	int n1 = 10, n2 = 10, n3 = 10;
	int level = 5;
	//Sinh de thi
	dethi = sinhDethi_v2(5, 5, 5, 2);
	//Hien thi danh sach de:
	for (int i = 0;i < dethi.size();i++)	
	{
		cout << dethi[i] << endl;
	}
	//Tiep tuc bo sung phan cho thi va cham diem
}
