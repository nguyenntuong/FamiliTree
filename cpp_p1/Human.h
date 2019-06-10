#pragma once
#include<string>
#include<vector>
#include "HumanBase.h"
using namespace std;
class Human : public HumanBase
{
private:
	Human* Cha;
	Human* Me;
	vector<Human*>* Anh;
	vector<Human*>* Em;
	Human* VoChong;
	vector<Human*>* ConCai;
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
	void addAnh(Human* Anh);
	void addEm(Human* Em);
	bool HasRelation(Human* human);
	Human* LaAnh(Human* human);
	Human* LaEm(Human* human);
	Human* LaCon(Human* human);
	Human* LaVoChong(Human* human);
	Human* LaChaMe(Human* human);
};

