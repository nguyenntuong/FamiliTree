#include "Human.h"

Human::Human(string HoTen,bool GioiTinh):HumanBase(HoTen,GioiTinh)
{
	Human::Cha = NULL;
	Human::Me = NULL;
	Human::VoChong = NULL;
	Human::Anh = new vector<Human*>();
	Human::Em = new vector<Human*>();
	Human::ConCai = new vector<Human*>();
	Human::AllRelation = new vector<Human*>();
}

void Human::setCha(Human* Cha)
{
	Human::Cha = Cha;
	Human::AllRelation->push_back(Human::Cha);
}

Human* Human::getCha()
{
	return Human::Cha;
}

void Human::setMe(Human* Me)
{
	Human::Me = Me; 
	Human::AllRelation->push_back(Human::Me);
}

Human* Human::getMe()
{
	return Human::Me;
}

void Human::setVoChong(Human* VoChong)
{
	Human::VoChong = VoChong;
	Human::AllRelation->push_back(Human::VoChong;
}

Human* Human::getVoChong()
{
	return Human::VoChong;
}

void Human::addCon(Human* con)
{
	Human::ConCai->push_back(con);
	Human::AllRelation->push_back(con);
}

void Human::addAnh(Human* Anh)
{
	Human::Anh->push_back(Anh);
	Human::AllRelation->push_back(Anh);
}

void Human::addEm(Human* Em)
{
	Human::Em->push_back(Em);
	Human::AllRelation->push_back(Em);
}

bool Human::HasRelation(Human * human)
{
	for (size_t i = 0; i < Human::AllRelation->size(); i++)
	{
		if (Human::AllRelation->at(i) == human) {
			return true;
		}
	}
	return false;
}

Human* Human::LaAnh(Human* human)
{
	for (size_t i = 0; i < Human::Em->size(); i++)
	{
		if (Human::Em->at(i) == human)
			return human;
	}
	return NULL;
}

Human* Human::LaEm(Human* human)
{
	for (size_t i = 0; i < Human::Anh->size(); i++)
	{
		if (Human::Anh->at(i) == human)
			return human;
	}
	return NULL;
}

Human* Human::LaCon(Human* human)
{
	if (Human::Cha == human)
		return Human::Cha;
	if (Human::Me == human)
		return Human::Me;
	return NULL;
}

Human * Human::LaVoChong(Human * human)
{
	if (Human::VoChong == human)
		return Human::VoChong;
	return NULL;
}

Human * Human::LaChaMe(Human * human)
{
	for (size_t i = 0; i < Human::ConCai->size(); i++)
	{
		if (Human::ConCai->at(i) == human)
			return human;
	}
	return NULL;
}
