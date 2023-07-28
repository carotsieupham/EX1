#include "BieuthucTru.h"

void BieuthucTru::SinhBieuThuc(int level)
{
	BieuthucSohoc::SinhBieuThuc(level);
	pheptoan = '-';
}

istream& operator>>(istream& in, BieuthucTru& bt)
{
	// TODO: insert return statement here
	return in;
}
