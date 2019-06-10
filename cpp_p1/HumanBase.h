#pragma once
#include<string>
using namespace std;
// Lớp cơ sở cho Human
class HumanBase
{
protected:
	// Họ tên
	string HoTen;
	// Giới tính
	bool GioiTinh;
public:
	// Hàm khởi tạo cho Base
	HumanBase(string HoTen, bool GioiTinh);

	string getHoTen();
	bool NamGioi();

	// In ra thông tin Human
	string toString();
};

