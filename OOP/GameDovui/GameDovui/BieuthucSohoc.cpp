#include "BieuthucSohoc.h"

istream& operator>>(istream& is, BieuthucSohoc& a)
{	
	cout << "Nhap bieu thuc:";
	is >> a.a ;
	cin.ignore();
	getline(is, a.pheptoan);
	is >> a.b;
	return is;
}

ostream& operator<<(ostream& os, BieuthucSohoc& a)
{
	os << a.a << a.pheptoan << a.b << "= ? " << endl;
	return os;
}

BieuthucSohoc::BieuthucSohoc()
{
	a = b = 0;
	pheptoan = "+";
}

BieuthucSohoc::BieuthucSohoc(int n)
{
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> dist10(1, 10); // Phân phối ngẫu nhiên từ 1 đến 10
    uniform_int_distribution<int> dist100(1, 100); // Phân phối ngẫu nhiên từ 1 đến 100

    if (n <= 3) {
        a = dist10(generator);
        b = dist10(generator);
    }
    else {
        a = dist100(generator);
        b = dist100(generator);
    }

    uniform_int_distribution<int> dist_operator(0, 2); // Phân phối ngẫu nhiên từ 0 đến 2

    if (n == 1) {
        pheptoan = '+';
    }
    else if (n == 2 || n == 4) {
        int random_operator = dist_operator(generator);
        if (random_operator == 0) {
            pheptoan = '+';
        }
        else {
            pheptoan = '-';
        }
    }
    else {
        int random_operator = dist_operator(generator);
        if (random_operator == 0) {
            pheptoan = '+';
        }
        else if (random_operator == 1) {
            pheptoan = '-';
        }
        else {
            pheptoan = '*';
        }
    }
}

bool BieuthucSohoc::ktrdapan()
{
	int answer,result;
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
