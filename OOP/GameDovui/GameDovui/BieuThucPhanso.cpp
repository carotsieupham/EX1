#include "BieuThucPhanso.h"

BieuThucPhanso::BieuThucPhanso(int level):BieuthucSohoc(level)
{

}

bool BieuThucPhanso::ktrdapan()
{
	Fraction answer, result;
	cout << "Nhap dap an:";cin >> answer;
	if (pheptoan == "+") {
		result = a + b;
	}
	else if (pheptoan == "-") {
		result = a - b;
	}
	else result = a * b;
	if (answer == result) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& os, BieuThucPhanso& a)
{
	os << "(" <<rutgon(a.a) << a.pheptoan << rutgon(a.b) << ")=?" << endl;
	return os;
}
