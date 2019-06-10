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
	case Quanhe::Anh:
		human1->addAnh(human2);
		break;
	case Quanhe::Em:
		human1->addEm(human2);
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
	case Quanhe::Anh:
		FamilyTree::getHuman(human1)->addAnh(FamilyTree::getHuman(human2));
		break;
	case Quanhe::Em:
		FamilyTree::getHuman(human1)->addEm(FamilyTree::getHuman(human2));
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
	vector<Human*> humanTRacking;
	Human* h1 = FamilyTree::getHuman(human1);
	Human* h2 = FamilyTree::getHuman(human2);
	

	return FamilyTree::getRelationShip(h1, h2);
}

CayQuanHe FamilyTree::getRelationShip(Human * human1, Human * human2)
{
	if (human1->LaAnh(human2)) {
		return CayQuanHe::Anh;
	}
	if (human1->LaEm(human2)) {
		return CayQuanHe::Em;
	}
	if (human1->LaCon(human2)) {
		return CayQuanHe::Con;
	}
	if (human1->LaChaMe(human2)) {
		if (human1->NamGioi())
			return CayQuanHe::Cha;
		else
			return CayQuanHe::Me;
	}
	if (human1->LaVoChong(human2)) {
		if (human1->NamGioi())
			return CayQuanHe::Chong;
		else
			return CayQuanHe::Vo;
	}
	return CayQuanHe::None;
}

string FamilyTree::PrintQH(CayQuanHe cqh)
{
	string tmp = "";
	switch (cqh)
	{
	case CayQuanHe::Ong:
		tmp = "Ong";
		break;
	case CayQuanHe::Ba:
		tmp = "Ba";
		break;
	case CayQuanHe::Cha:
		tmp = "Cha";
		break;
	case CayQuanHe::Me:
		tmp = "Me";
		break;
	case CayQuanHe::Vo:
		tmp = "Vo";
		break;
	case CayQuanHe::Chong:
		tmp = "Chong";
		break;
	case CayQuanHe::Con:
		tmp = "Con";
		break;
	case CayQuanHe::Co:
		tmp = "Co";
		break;
	case CayQuanHe::Chu:
		tmp = "Chu";
		break;
	case CayQuanHe::Anh:
		tmp = "Anh";
		break;
	case CayQuanHe::Chi:
		tmp = "Chi";
		break;
	case CayQuanHe::Em:
		tmp = "Em";
		break;
	case CayQuanHe::None:
		tmp = "Khong co quan he";
		break;
	default:
		break;
	}
	return tmp;
}
