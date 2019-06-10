#pragma once
#include<string>
#include<vector>
#include "HumanBase.h"
using namespace std;
// Lớp dẫn xuất từ HumanBase
class Human : public HumanBase
{
private:
	// Cha của đối tượng
	Human* Cha;
	// Mẹ của đối tượng
	Human* Me;
	// Danh sách Anh em của đối tượng, (Anh Em nói chung)
	vector<Human*>* AnhEm;
	// Vợ chồng 
	Human* VoChong;
	// Con cái
	vector<Human*>* ConCai;
	// Tổng các mối quan hệ của đối tượng
	vector<Human*>* AllRelation;
public:
	Human(string HoTen,bool GioiTinh);

	void setCha(Human* Cha);
	Human* getCha();
	void setMe(Human* Me);
	Human* getMe();
	void setVoChong(Human* VoChong);
	Human* getVoChong();
	void addCon(Human* con);
	void addAnhEm(Human* Anh);
	vector<Human*>* getAllRelation();
	// Kiểm tra các mối quan hệ
	bool HasRelation(Human* human);
	Human* LaAnhChiEm(Human* human);
	Human* LaCon(Human* human);
	Human* LaVoChong(Human* human);
	Human* LaChaMe(Human* human);
};

