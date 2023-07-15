#include "sv.h"
string sv::get_name()
{
	return this->ht;
}
float sv::TinhDiemQT() {
	if (bv <= 5) {
		return (10 - bv * 2) * 0.2 + DiemTH * 0.3 + DiemGK * 0.5;
	}
	else
		return 0;
}
void sv::hienthiTTSV()
{
	cout << setw(28) << left << ht << "\t";
	cout <<"|"<< setw(10) << left << mssv << "\t";
	cout << "|" << setw(10) << left << bv << "\t";
	cout << "|" << setw(10) << left << DiemTH << "\t";
	cout << "|" << setw(10) << left << DiemGK << "\t";
	cout <<  "|" <<setw(15) << left << TinhDiemQT();
}
void sv::ghifile(ofstream& ofs)
{
	ofs << mssv << endl;
	ofs << ht << endl;
	ofs << bv << endl;
	ofs << DiemTH << endl;
	ofs << DiemGK << endl;
}
void sv::docfile(ifstream& ifs)
{
	getline(ifs, mssv);
	getline(ifs, ht);
	ifs >> bv;
	ifs >> DiemTH;
	ifs >> DiemGK;
	ifs.ignore();
}
istream& operator>>(istream& is, sv& sv) {
	cin.ignore();
	cout << "Nhap ho ten: "; getline(is, sv.ht);
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