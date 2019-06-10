#include "HumanBase.h"

HumanBase::HumanBase(string HoTen, bool GioiTinh)
{
	HumanBase::HoTen = HoTen;
	HumanBase::GioiTinh = GioiTinh;
}

string HumanBase::getHoTen()
{
	return HumanBase::HoTen;
}

bool HumanBase::NamGioi()
{
	return HumanBase::GioiTinh;
}

string HumanBase::toString()
{
	return HoTen + " - " + (GioiTinh ? "Nam" : "Nu");
}
