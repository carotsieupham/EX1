#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
	int n, j;
	cout << "Nhap so luong phan tu trong mang:"; cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ":"; cin >> j;
		arr.push_back(j);
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "a) So luong gia tri nguyen khac nhau trong mang la: ";
	map<int, int> count;
	for (int i = 0; i < n; i++)
	{
		count[arr[i]]++;
	}
	cout << count.size() << endl;
	cout << "b) So lan xuat hien cua cac gia tri trong mang:" << endl;
	for (const auto& p : count) {
		cout << "Gia tri " << p.first << " xuat hien " << p.second << " lan." << endl;
	}
	cout << "c) In ra danh sách các giá trị khác nhau trong mảng, và các vị trí xuất hiện của chúng " << endl;
	map<int, vector<int>> list;
	for (int i = 0; i < n; i++)
	{
		list[arr[i]].push_back(i);
	}
	for (const auto& p : list) {
		cout << "Gia tri " << p.first << " xuat hien tai cac vi tri: ";
		for (auto &q: p.second)
		{
			cout << q<<" ";
		}
		cout << endl;
	}
};