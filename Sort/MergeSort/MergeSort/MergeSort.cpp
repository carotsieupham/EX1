// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;c
void merge(int a[], int l, int m, int r) {
	vector<int> x(a + l, a + m + 1);
	vector<int> y(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	while (i < x.size() && j < y.size()) {
		if (x[i] <= y[j]) {
			a[l] = x[i];++l;++i;
		}
		else {
			a[l] = y[j];++l;++j;
		}
	}
	while (i < x.size())
	{
		a[l] = x[i];++l;++i;
	}
	while (j < y.size())
	{
		a[l] = y[j];++l;++j;
	}
};
void mergesort(int a[], int l, int r) {
	if (l >= r) return;
	int m = (l + r) / 2;
	mergesort(a, l, m);
	mergesort(a, m + 1, r);
	merge(a, l, m, r);
};
int main(){
	int a[] = {6,5,12,10,9,1};
	mergesort(a, 0, 5);
	for (int i = 0;i < 6;i++) {
		cout << a[i] << " ";
	}
}