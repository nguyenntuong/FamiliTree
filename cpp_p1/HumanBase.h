#pragma once
#include<string>
using namespace std;
class HumanBase
{
protected:
	string HoTen;
	bool GioiTinh;
public:
	HumanBase(string HoTen, bool GioiTinh);

	string getHoTen();
	bool NamGioi();

	string toString();
};

