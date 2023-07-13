#pragma once
class phanSo
{
private:
	int mau, tu;
public:
	phanSo(int tu, int mau);
	void input(int mau,int tu);
	void print();
	phanSo add( phanSo& b);
	void minimum();
};

