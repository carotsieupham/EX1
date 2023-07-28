#include "BieuthucNhan.h"

void BieuthucNhan::SinhBieuThuc(int level)
{
	BieuthucSohoc::SinhBieuThuc(level);
	pheptoan = '*';
}

istream& operator>>(istream& in, BieuthucNhan& bt)
{
	// TODO: insert return statement here
	return in;
}
