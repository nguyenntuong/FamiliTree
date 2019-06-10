#pragma once
#include "applib.h"
using namespace std;
class App
{
public:
	static App* Instance();
private:
	static App* app;
public:
	App();
	void Run();
private:
	FamilyTree* FTree;
	void Pause(string message="");
	void Clear();
	void FetchData();
	void PrintListHuman();
};

