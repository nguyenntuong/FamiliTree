#include "FamilyTree.h"

FamilyTree::FamilyTree()
{
	FamilyTree::FTree = new vector<Human*>();
}

void FamilyTree::add(Human* human) {
	FamilyTree::FTree->push_back(human);
}

Human* FamilyTree::getHuman(size_t index)
{
	if (index < 0 || index >= FamilyTree::FTree->size())
		return NULL;
	else
		return FamilyTree::FTree->at(index);
}

vector<Human*>* FamilyTree::getAllHuman()
{
	return FamilyTree::FTree;;
}

void FamilyTree::makeRelationShip(Human* human1, Human* human2, Quanhe qh)
{
	switch (qh)
	{
	case Quanhe::Cha:
		human1->setCha(human2);
		break;
	case Quanhe::Me:
		human1->setMe(human2);
		break;
	case Quanhe::AnhChiEm:
		human1->addAnhEm(human2);
		break;
	case Quanhe::VoChong:
		human1->setVoChong(human2);
		break;
	default:
		break;
	}
}

void FamilyTree::makeRelationShip(size_t human1, size_t human2, Quanhe qh)
{
	if (human2 == -1)
		return;
	switch (qh)
	{
	case Quanhe::Cha:
		FamilyTree::getHuman(human1)->setCha(FamilyTree::getHuman(human2));
		break;
	case Quanhe::Me:
		FamilyTree::getHuman(human1)->setMe(FamilyTree::getHuman(human2));
		break;
	case Quanhe::AnhChiEm:
		FamilyTree::getHuman(human1)->addAnhEm(FamilyTree::getHuman(human2));
		break;
	case Quanhe::VoChong:
		FamilyTree::getHuman(human1)->setVoChong(FamilyTree::getHuman(human2));
		break;
	case Quanhe::ConCai:
		FamilyTree::getHuman(human1)->addCon(FamilyTree::getHuman(human2));
		break;
	default:
		break;
	}
}

CayQuanHe FamilyTree::getRelationShip(size_t human1, size_t human2)
{
	if (human1 < 0 || human1 >= FamilyTree::FTree->size() || human2 < 0 || human2 >= FamilyTree::FTree->size())
		CayQuanHe::None;
	vector<vector<Human*>>* humanTRacking=new vector<vector<Human*>>();
	Human* h1 = FamilyTree::getHuman(human1);
	Human* h2 = FamilyTree::getHuman(human2);
	FamilyTree::recursiveTracking(h1, h2, vector<Human*>(), humanTRacking);
	vector<Human*> minimunRelation=humanTRacking->at(0);
	for (size_t i = 1; i < humanTRacking->size(); i++)
	{
		if (humanTRacking->at(i).size() < minimunRelation.size()) {
			minimunRelation = humanTRacking->at(i);
		}
	}
	int p = FamilyTree::caculateFamilyPoint(minimunRelation);
	if (p == 0) {
		if (h1->LaVoChong(h2))
			return CayQuanHe::VoChong;
		else
			return CayQuanHe::AnhChiEm;
	}
	else if (p == 1) {
		if (h2->LaChaMe(h1)||h2->LaChaMe(h1->getVoChong())) {
			return CayQuanHe::ChaMe;
		}
		else {
			return CayQuanHe::CoChu;
		}
	}
	else if(p>=2)
	{
		return CayQuanHe::OngBa;
	}
	else {
		return CayQuanHe::ConChau;
	}
	return CayQuanHe::None;
}

void FamilyTree::recursiveTracking(Human * h, Human * h2, vector<Human*> tracking, vector<vector<Human*>>* manageTracking)
{
	tracking.push_back(h);
	if (h->HasRelation(h2))
	{
		tracking.push_back(h2);
		manageTracking->push_back(tracking);
	}
	else {
		for (size_t i = 0; i < h->getAllRelation()->size(); i++)
		{
			bool hasTrack = false;
			for (size_t j = 0; j < tracking.size(); j++)
			{
				if (tracking[j] == h->getAllRelation()->at(i)) {
					hasTrack = true;
				}
			}
			if (hasTrack) {
				continue;
			}
			FamilyTree::recursiveTracking(h->getAllRelation()->at(i), h2, tracking,manageTracking);
		}
	}
}

int FamilyTree::caculateFamilyPoint(vector<Human*> track)
{
	int p = 0;
	for (size_t i = 1; i < track.size(); i++)
	{
		CayQuanHe cqh= FamilyTree::getRelationShip(track.at(i-1),
			track.at(i)
			);
		switch (cqh)
		{
		case CayQuanHe::ChaMe:
			p--;
			break;
		case CayQuanHe::VoChong:
			break;
		case CayQuanHe::ConCai:
			p++;
			break;
		case CayQuanHe::AnhChiEm:
			break;
		default:
			break;
		}
	}
	return p;
}

CayQuanHe FamilyTree::getRelationShip(Human * human1, Human * human2)
{
	if (human1->LaAnhChiEm(human2)) {
		return CayQuanHe::AnhChiEm;
	}
	if (human1->LaCon(human2)) {
		return CayQuanHe::ConCai;
	}
	if (human1->LaChaMe(human2)) {
		return CayQuanHe::ChaMe;
	}
	if (human1->LaVoChong(human2)) {
		return CayQuanHe::VoChong;
	}
	return CayQuanHe::None;
}

string FamilyTree::PrintQH(CayQuanHe cqh)
{
	string tmp = "";
	switch (cqh)
	{
	case CayQuanHe::OngBa:
		tmp = "Ong Ba";
		break;
	case CayQuanHe::ChaMe:
		tmp = "Cha Me";
		break;
	case CayQuanHe::VoChong:
		tmp = "Vo Chong";
		break;
	case CayQuanHe::ConCai:
		tmp = "Con Cai";
		break;
	case CayQuanHe::CoChu:
		tmp = "Co Chu";
		break;
	case CayQuanHe::AnhChiEm:
		tmp = "Anh Chi Em";
		break;
	case CayQuanHe::ConChau:
		tmp = "Con Chau";
		break;
	case CayQuanHe::None:
		tmp = "Khong co quan he";
		break;
	default:
		break;
	}
	return tmp;
}
