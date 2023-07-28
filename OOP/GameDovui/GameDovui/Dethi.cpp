#include "Dethi.h"

void Dethi::sinhDethi(int n1, int n2, int n3, int level)
{
	for (int i = 0; i < n1; i++)
	{
		BieuThucCong* btc = new BieuThucCong(level);
		dethi.push_back(*btc);
	}
	for (int i = 0; i < n2; i++)
	{
		BieuThucTru* btt = new BieuThucTru(level);
		dethi.push_back(*btt);
	}
	for (int i = 0; i < n3; i++)
	{
		BieuThucNhan* btn = new BieuThucNhan(level);
		dethi.push_back(*btn);
	}
}

void Dethi::start()
{
	int correct = 0;
	for (int i = 0; i < dethi.size(); i++)
	{
		cout << "Cau " << i + 1 << ":";
		cout << dethi[i];
		if (dethi[i].ktrdapan()) {
			correct++;
		}
	}
	cout << "Diem dat duoc: " << correct << endl;
}
