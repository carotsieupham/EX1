#include "CauhoiTN.h"
void CauhoiTN :: nhap() {
	
	cout << "Nhap cau hoi:";
	getline(cin,noidung);
	cout << "Nhap dap an A: ";
	getline(cin, cauA);
	cout << "Nhap dap an B: ";
	getline(cin, cauB);
	cout << "Nhap dap an dung(A/B)";
	getline(cin,dapan);
}
void CauhoiTN::docfile(ifstream& ifs) {
	getline(ifs, noidung);
	getline(ifs, cauA);
	getline(ifs, cauB);
	getline(ifs, dapan);
}
void CauhoiTN::ghifile(ofstream& ofs) {
	ofs << noidung << endl;
	ofs << cauA << endl;
	ofs << cauB << endl;
	ofs << dapan << endl;
}
bool CauhoiTN::kiemtra() {
	string userdapan;
	xuat();
	cout << "Dap an cua ban la(A/B): ";getline(cin,userdapan);
	if (!dapan.compare(userdapan) )return true;
	return false;
}
void CauhoiTN::xuat() {
	cout <<noidung << endl;
	cout << "A. " << cauA <<"\t";
	cout << "B. " << cauB << endl;
}
bool giongnhau(CauhoiTN cau1, CauhoiTN cau2) {
	if (!(cau1.noidung).compare(cau2.noidung)) {
		return true;
	}
	return false;
}




