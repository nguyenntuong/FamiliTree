#pragma once
#include<vector>
#include<iostream>
#include "Human.h"
using namespace std;
enum class Quanhe
{
	Cha,
	Me,
	AnhChiEm,
	VoChong,
	ConCai
};
enum class CayQuanHe
{
	OngBa,
	ChaMe,
	CoChu,
	VoChong,
	ConChau,
	ConCai,
	AnhChiEm,
	None
};
// Lớp quản lý các thao tác trên cây gia đình
class FamilyTree
{
private:
	vector<Human*>* FTree;

	// Đệ quy tìm các mối quan hệ gia đình
	void recursiveTracking(Human* h,Human* h2,vector<Human*> tracking, vector<vector<Human*>>* manageTracking);
	// Tính toán điểm quan hệ từ đó suy ra mức độ quan hệ
	int caculateFamilyPoint(vector<Human*> track);
public:
	FamilyTree();

	void add(Human* human);
	Human* getHuman(size_t index);
	vector<Human*>* getAllHuman();
	// Tạo mối quan hệ giữa các cá thể
	void makeRelationShip(Human* human1, Human* human2,Quanhe qh);
	void makeRelationShip(size_t human1, size_t human2,Quanhe qh);

	// Lấy ra mối quan hệ giữa các cá thể
	CayQuanHe getRelationShip(size_t human1, size_t human2);
	CayQuanHe getRelationShip(Human* human1, Human* human2);

	// In ra mối quan hệ
	static string PrintQH(CayQuanHe cqh);
};

