#include "polynomialTermDual.h"

polynomialTermDual::polynomialTermDual(int heso, int somu)
{
	this->heso = heso;
	this->somu = somu;
}

int polynomialTermDual::getheso()
{
	return this->heso;
}

int polynomialTermDual::getsomu()
{
	return this->heso;
}

polynomialTermDual* polynomialTermDual::getpointernext()
{
	return this->next;
}

polynomialTermDual* polynomialTermDual::getpointerprev()
{
	return this->prev;
}


void polynomialTermDual::setheso(int heso)
{
	this->heso = heso;
}

void polynomialTermDual::setsomu(int somu)
{
	this->somu = somu;
}

void polynomialTermDual::setpointernext(polynomialTermDual* p)
{
	this->next = p;
}

void polynomialTermDual::setpointerprev(polynomialTermDual* p)
{
	this->prev = p;

}
