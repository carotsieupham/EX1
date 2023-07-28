#include "BieuthucSohoc.h"
#include "BieuThucCong.h"
#include "BieuThucNhan.h"
#include "BieuThucTru.h"
#include "BieuThucPhanso.h"
#include "Dethi.h"
#include"BieuThucPhucTap.h"
int main() {
	//CAU A
	/*cout << "Cau a" << endl;
	BieuthucSohoc a(3);
	cout << a;
	if (a.ktrdapan()) {
		cout << "Ban tra loi dung" << endl;
	}
	else
	{
		cout << "Ban tra loi sai" << endl;
	}
	BieuthucSohoc b;
	cin >> b;
	cout << b;
	if (b.ktrdapan()) {
		cout << "Ban tra loi dung" << endl;
	}
	else
	{
		cout << "Ban tra loi sai" << endl;
	}*/
	//CAU B
	//cout << "Cau b" << endl;
	//int level = 1;
	//int correct = 0;
	//int correct_streak=0;
	//while (true) {
	//	BieuthucSohoc bieuthuc(level);
	//	cout << bieuthuc;
	//	if (bieuthuc.ktrdapan()) {
	//		cout << "Ban tra loi dung" << endl;
	//		correct++;
	//		correct_streak++;
	//		if (correct_streak == 3) {
	//			level++;
	//			correct_streak = 0;
	//		}
	//	}
	//	else {
	//		cout << "Ban tra loi sai" << endl;
	//		if (level > 1) {
	//			level--;
	//		}
	//		correct_streak = 0;
	//	}
	//	cout << "Cap do kho: Level " << level << endl;
	//	cout << "Diem hien tai: " << correct << endl;
	//	bool is_continue;
	//	cout << "Ban co muon tiep tuc(1/0):";cin >> is_continue;
	//	if (!is_continue) {
	//		cout << "Bye Bye"<<endl;
	//		break;
	//	}
	//}
	// CAU C
	// cout<<"Cau c"<<endl;
	//BieuThucCong bieuthuc1(1);
	//BieuThucTru bieuthuc2(1);
	//BieuThucNhan bieuthuc3(1);
	//cout << "Bieu thuc cong:" << bieuthuc1;
	//cout << "Bieu thuc tru:" << bieuthuc2;
	//cout << "Bieu thuc nhan:" << bieuthuc3;
	//CAU D
	/*cout << "Cau d" << endl;
	Dethi dt;
	dt.sinhDethi(5, 5, 5, 1);
	dt.start();*/
	//CAU E
	cout << "Cau e" << endl;
	BieuThucPhucTap btpt;
	cout << btpt;
	if (btpt.ktrdapan()) {
		cout << "Ban tra loi dung" << endl;
	}
	else cout << "Ban tra loi sai" << endl;
	//CAU F
	/*cout << "Cau f" << endl;
	BieuThucPhanso btps(5);
	cout << btps;
	if (btps.ktrdapan()) {
		cout << "Ban tra loi dung" << endl;
	}
	else cout << "Ban tra loi sai" << endl;*/
}