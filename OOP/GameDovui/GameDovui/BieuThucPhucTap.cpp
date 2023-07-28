#include "BieuThucPhucTap.h"

BieuThucPhucTap::BieuThucPhucTap():BieuthucSohoc(5)
{
	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> dist_operator(0, 2);
	random_bt = dist_operator(generator);
}

bool BieuThucPhucTap::ktrdapan()
{
	int answer, result;
	cout << "Nhap dap an:";cin >> answer;
	switch (random_bt)
	{
	case 0:
		if (pheptoan == "+") result = a + b + b + a;
		else if (pheptoan == "*") result = a * b + b * a;
		else result = a - b + b - a;
		break;
	case 1:
		if (pheptoan == "+") result = (a + a) * (b + b);
		else if (pheptoan == "*") result = (a * a) * (b * b);
		else result = (a - a) * (b - b);
		break;
	case 2:
		if (pheptoan == "+") result = a + b - b + a;
		else if (pheptoan == "*") result = a * b - b * a;
		else result = a - b - b - a;
		break;
	}
	if (answer==result) return true;
	return false;
}

ostream& operator<<(ostream& os, BieuThucPhucTap& a)
{
	switch (a.random_bt)
	{
		case 0:
			os << a.a << a.pheptoan << a.b << "+" << a.b << a.pheptoan << a.a << "=?" << endl;
			break;
		case 1:
			os <<"(" <<a.a << a.pheptoan << a.a<<")" << "*" << "(" << a.b << a.pheptoan << a.b << ")" << "=?" << endl;
			break;
		case 2:
			os << a.a << a.pheptoan << a.b <<  "-" <<  a.b << a.pheptoan << a.a  << "=?" << endl;
			break;
	}
	return os;
}
