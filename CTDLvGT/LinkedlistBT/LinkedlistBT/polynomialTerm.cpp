#include "polynomialTerm.h"

polynomialTerm::polynomialTerm(int heso, int somu)
{
	this->heso = heso;
	this->somu = somu;
}

int polynomialTerm::getheso()
{
	return this->heso;
}

int polynomialTerm::getsomu()
{
	return this->somu;
}

polynomialTerm* polynomialTerm::getpointer()
{
	return this->p;
}

void polynomialTerm::setheso(int heso)
{
	this->heso = heso;
}

void polynomialTerm::setsomu(int somu)
{
	this->somu = somu;

}

void polynomialTerm::setpointer(polynomialTerm* p)
{
	this->p = p;
}

