#pragma once
#include<vector>
#include<iostream>
#include "Human.h"
using namespace std;
enum class Quanhe
{
	Cha,
	Me,
	Anh,
	Em,
	VoChong,
	ConCai
};
enum class CayQuanHe
{
	Ong,
	Ba,
	Cha,
	Me,
	Co,
	Chu,
	Vo,
	Chong,
	Con,
	Anh,
	Chi,
	Em,
	None
};
class FamilyTree
{
private:
	vector<Human*>* FTree;
public:
	FamilyTree();

	void add(Human* human);
	Human* getHuman(size_t index);
	void makeRelationShip(Human* human1, Human* human2,Quanhe qh);
	void makeRelationShip(size_t human1, size_t human2,Quanhe qh);

	CayQuanHe getRelationShip(size_t human1, size_t human2);
	CayQuanHe getRelationShip(Human* human1, Human* human2);

	static string PrintQH(CayQuanHe cqh);
};

