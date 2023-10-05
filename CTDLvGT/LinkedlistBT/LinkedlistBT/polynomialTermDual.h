#pragma once
class polynomialTermDual
{
private:
	int heso;
	int somu;
	polynomialTermDual* next,*prev;
public:
	polynomialTermDual(int heso, int somu);
	int getheso();
	int getsomu();
	polynomialTermDual* getpointernext();
	polynomialTermDual* getpointerprev();

	void setheso(int heso);
	void setsomu(int somu);
	void setpointernext(polynomialTermDual* p);
	void setpointerprev(polynomialTermDual* p);

};

