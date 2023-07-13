#include<iostream>
#include <math.h>

using namespace std;
int main()
{
	int i, j ;			// khai báo 2 biến nguyên i, j
	int *p, *q ;		// khai báo 2 con trỏ nguyên p, q
	p = &i;			// cho p trỏ tới i 
	q = &j;			// cho q trỏ tới j
	cout << &i ;		// hỏi địa chỉ biến i
	cout << q ;		// hỏi địa chỉ biến j (thông qua q)
	i = 2;			// gán i bằng 2
	*q = 5;			// gán j bằng 5 (thông qua q)
	i++ ; cout << i ;	// tăng i và hỏi i, i = 3
	(*q)++ ; cout << j ;	// tăng j (thông qua q) và hỏi j, j = 6
	(*p) = (*q) * 2 + 1;	// gán lại i (thông qua p)
	cout << i ;		// 13 


}
