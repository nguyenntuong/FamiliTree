#include "App.h"
// Singleton
App* App::app = new App();

// Lấy App ra để chạy trong main
App* App::Instance()
{
	return app;
}

App::App() {
	// Khởi tạo cây gia đình
	App::FTree = new FamilyTree();
}

// Hàm chạy chính cho chương trình
void App::Run()
{
	App::Clear();
	// Load dữ liệu từ file text lên
	App::FetchData();
	while (true)
	{
		App::Clear();
		App::PrintListHuman();
		int h1 = 0; // Số hiệu Index của người thứ nhất
		int h2 = 0; // Số hiệu Index của người thứ hai
		cout << "TIM MOI QUAN HE GIUA NGUOI THU 2 VA NGUOI THU 1." << endl;
		cout << "Nhap Index cua nguoi thu nhat (-1 de thoat): ";
		cin >> h1;
		if (h1 < 0)
			break;
		cout << "Nhap Index cua nguoi thu hai (-1 de thoat): ";
		cin >> h2;
		if (h2 < 0)
			break;
		cout << FTree->getHuman(h2)->toString()
			<< " la "
			// Lấy mối quan hệ giữa h2 và h1
			<< FamilyTree::PrintQH(App::FTree->getRelationShip(h1, h2))
			<< " cua "
			<< FTree->getHuman(h1)->toString()
			<< endl;
		App::Pause("Phim bat ky de quay lai !");
	}	
	App::Pause();
}

// Load dữ liệu từ file text
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
			App::FTree->makeRelationShip(i, anhi[x], Quanhe::AnhChiEm);
		}
		for (size_t x = 0; x < emi.size(); x++)
		{
			App::FTree->makeRelationShip(i, emi[x], Quanhe::AnhChiEm);
		}
		App::FTree->makeRelationShip(i, vochong, Quanhe::VoChong);
		for (size_t x = 0; x < concaii.size(); x++)
		{
			App::FTree->makeRelationShip(i, concaii[x], Quanhe::ConCai);
		}
	}
}

// In ra toàn bộ danh sách thành viên
void App::PrintListHuman()
{
	cout << "DANH SACH THANH VIEN:" << endl;
	for (size_t i = 0; i < App::FTree->getAllHuman()->size(); i++)
	{
		cout << "Index: " << i << endl;
		cout << App::FTree->getAllHuman()->at(i)->toString() << endl;
		cout << endl;
	}
	cout << endl;
}

// Tạm dừng chương trình 
void App::Pause(string message)
{
	cout << endl;
	cout << message << endl;
	system("pause");
}

// Xoá màng hình
void App::Clear()
{
	system("cls");
}

