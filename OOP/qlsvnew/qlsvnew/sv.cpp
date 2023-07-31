#include "sv.h"
string sv::get_familyname()
{
	return this->hodem;
}
string sv::get_name() {
	return this->ten;
}
float sv::TinhDiemQT() {
	if (bv <= 5) {
		return (10 - bv * 2) * 0.2 + DiemTH * 0.3 + DiemGK * 0.5;
	}
	else
		return 0;
}
void sv::hienthiTTSV(int& index)
{
	gotoXY(1, index );
	cout <<  hodem + " " + ten ;
	gotoXY(31,index);
	cout <<   mssv ;
	gotoXY(48, index );
	cout  <<bv ;
	gotoXY(59, index );
	cout  << DiemTH ;
	gotoXY(74, index );
	cout  << DiemGK;
	gotoXY(90, index );
	cout  << TinhDiemQT();
	index++;
}
void sv::ghifile(ofstream& ofs)
{
	ofs << mssv << endl;
	ofs << hodem << endl;
	ofs << ten << endl;
	ofs << bv << endl;
	ofs << DiemTH << endl;
	ofs << DiemGK << endl;
}
void sv::docfile(ifstream& ifs)
{
	getline(ifs, mssv);
	getline(ifs, hodem);
	getline(ifs, ten);
	ifs >> bv;
	ifs >> DiemTH;
	ifs >> DiemGK;
	ifs.ignore();
}
istream& operator>>(istream& is, sv& sv) {
	cin.ignore();
	cout << "Nhap ho va ten dem: "; getline(is, sv.hodem);
	cout << "Nhap ten:";getline(is, sv.ten);
	cout << "Nhap ma so sinh vien: "; getline(is, sv.mssv);
	cout << "Nhap so buoi vang: "; is >> sv.bv;
	cout << "Nhap diem thuc hanh: "; is >> sv.DiemTH;
	cout << "Nhap diem giua ki: "; is >> sv.DiemGK;
	return is;
}
ostream& operator<<(ostream& os, sv& sv) {
	os << sv.mssv << endl;
	os << sv.bv << endl;
	os << sv.DiemTH << endl;
	os << sv.DiemGK << endl;
	return os;
}

bool trungten(sv sv1, sv sv2)
{
	if (!(sv1.get_name()).compare(sv2.get_name())) return true;
	return false;
}
void box(int x, int y, int h, int w)
{
	if (h <= 1 || w <= 1)return;
	
	for (int ix = x;ix <= x + w;ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <=y+h; iy++)
	{
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
		gotoXY(x + 30, iy);cout << char(179);
		gotoXY(x + 43, iy);cout << char(179);
		gotoXY(x + 53, iy);cout << char(179);
		gotoXY(x + 68, iy);cout << char(179);
		gotoXY(x + 83, iy);cout << char(179);
	}
	gotoXY(x+30, y);cout << char(194);
	gotoXY(x+30, y+h);cout << char(193);
	gotoXY(x+43, y);cout << char(194);
	gotoXY(x+43, y + h);cout << char(193);
	gotoXY(x + 53, y);cout << char(194);
	gotoXY(x + 53, y + h);cout << char(193);
	gotoXY(x + 68, y);cout << char(194);
	gotoXY(x + 68, y + h);cout << char(193);
	gotoXY(x + 83, y);cout << char(194);
	gotoXY(x + 83, y + h);cout << char(193);
	gotoXY(x, y);cout << char(218);
	gotoXY(x + w, y);cout << char(191);
	gotoXY(x, y + h);cout << char(192);
	gotoXY(x + w, y + h);cout << char(217);
}
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}