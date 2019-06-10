#include "App.h"

App* App::app = new App();

App* App::Instance()
{
	return app;
}

App::App() {
	App::FTree = new FamilyTree();
}

void App::Run()
{
	App::Clear();
	App::FetchData();
	cout << FamilyTree::PrintQH(App::FTree->getRelationShip(6, 1)) << endl;
	App::Pause();
}

void App::FetchData() {
	ifstream readfile;
	readfile.open("input.txt", ios::in);
	if (!readfile.is_open()) {
		App::Pause("Khong the mo file!");
		return;
	}
	vector<vector<string>> allLine;
	while (!readfile.eof())
	{
		char tmp[255];
		readfile.getline(tmp, 255);
		allLine.push_back(Utils::Split(tmp, ',', true));
	}
	readfile.close();
	for (size_t i = 0; i < allLine.size(); i++)
	{
		App::FTree->add(new Human(allLine[i][0], (allLine[i][1] == "1" ? true : false)));
	}
	for (size_t i = 0; i < allLine.size(); i++)
	{
		vector<string> current = allLine[i];
		int cha, me, vochong;
		vector<int> anhi, emi, concaii;
		cha = current[2] == "" ? -1 : stoi(current[2]);
		me = current[3] == "" ? -1 : stoi(current[3]);
		vector<string> anh = Utils::Split(current[4], ';', false);
		for (size_t x = 0; x < anh.size(); x++)
		{
			if (anh[x] == "")
				continue;
			anhi.push_back(stoi(anh[x]));
		}
		vector<string> em = Utils::Split(current[5], ';', false);
		for (size_t x = 0; x < em.size(); x++)
		{
			if (em[x] == "")
				continue;
			emi.push_back(stoi(em[x]));
		}
		vochong = current[6] == "" ? -1 : stoi(current[6]);
		vector<string> concai = Utils::Split(current[7], ';', false);
		for (size_t x = 0; x < concai.size(); x++)
		{
			if (concai[x] == "")
				continue;
			concaii.push_back(stoi(concai[x]));
		}
		App::FTree->makeRelationShip(i, cha, Quanhe::Cha);
		App::FTree->makeRelationShip(i, me, Quanhe::Me);
		for (size_t x = 0; x < anhi.size(); x++)
		{
			App::FTree->makeRelationShip(i, anhi[x], Quanhe::Anh);
		}
		for (size_t x = 0; x < emi.size(); x++)
		{
			App::FTree->makeRelationShip(i, emi[x], Quanhe::Em);
		}
		App::FTree->makeRelationShip(i, vochong, Quanhe::VoChong);
		for (size_t x = 0; x < concaii.size(); x++)
		{
			App::FTree->makeRelationShip(i, concaii[x], Quanhe::ConCai);
		}
	}
}

void App::Pause(string message)
{
	cout << message << endl;
	system("pause");
}

void App::Clear()
{
	system("cls");
}

