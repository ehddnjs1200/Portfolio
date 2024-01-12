#include "framework.h"
#include "Card.h"

Card::Card(wstring file, Card::Type type, Card::Rarity rarity, string name, int cost, int maxUpgrade, int upgrade, bool volatility, bool extinction)
	:_file(file), _type(type), _rarity(rarity), _name(name), _cost(cost), _maxUpgrade(maxUpgrade), _upgrade(upgrade), _volatility(volatility),_extinction(extinction)
{
	_card = make_shared<Quad>(_file);
	_card->GetTransForm()->GetScale() *= 0.3f;
	_card->GetTransForm()->SetPos(_pos);
	_col = make_shared<RectCollider>(_card->GetTextureSize() * 3.0f);
	_col->SetParent(_card->GetTransForm());
}

Card::Card(const Card& other)
	: _file(other._file),_type(other._type), _rarity(other._rarity),
	_name(other._name), _cost(other._cost),
	_maxUpgrade(other._maxUpgrade), _upgrade(other._upgrade)
	, _volatility(other._volatility),_extinction(other._extinction)
{
	_card = make_shared<Quad>(other._file);
	_card->GetTransForm()->GetScale() = other._card->GetTransForm()->GetScale();
	_card->GetTransForm()->SetPos(other._pos);
	_col = make_shared<RectCollider>(_card->GetTextureSize() * 3.0f);
	_col->SetParent(_card->GetTransForm());
}

Card::~Card()
{

}

void Card::Update()
{
	_card->Update();
	_col->Update();
}

void Card::Render()
{
	_card->Render();
	_col->Render();
}

void Card::SetPosition(Vector2 pos)
{
	_card->GetTransForm()->GetPos() = pos;
}

bool CompareFileNumbers(const Card::FileInfo& a, const Card::FileInfo& b) {
	return a.fileNumber < b.fileNumber;
}

void Card::ListFilesInFolder(const wstring& folderPath, vector<FileInfo>& filePaths)
{
	WIN32_FIND_DATA findFileData;
	HANDLE hFind = FindFirstFile((folderPath + L"\\*").c_str(), &findFileData);

	if (hFind == INVALID_HANDLE_VALUE) {
		wcerr << L"Error finding files in the folder." << endl;
		return;
	}

	do {
		if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			// 파일 이름을 문자열로 변환
			wstring fileName(findFileData.cFileName);

			// 파일 이름이 "0.png"부터 "31.png"까지인 경우에만 저장
			if (fileName.length() >= 5) {
				wistringstream iss(fileName);
				int fileNumber;
				if (iss >> fileNumber) {
					if (fileNumber >= 0 && fileNumber <= 31) {
						// 파일의 전체 경로와 파일명에서 추출한 숫자를 저장
						wstring filePath = folderPath + L"\\" + fileName;

						// 파일명과 확장자만 추출
						size_t dotPos = fileName.find_last_of(L".");
						if (dotPos != wstring::npos) {
							wstring fileOnly = fileName.substr(0, dotPos);
							wstring extension = fileName.substr(dotPos + 1);

							// 파일명과 확장자를 합쳐서 저장
							wstring fileWithExtension = fileOnly + L"." + extension;


							filePaths.push_back({ fileWithExtension, fileNumber });
						}
					}
				}
			}
		}
	} while (FindNextFile(hFind, &findFileData) != 0);

	FindClose(hFind);
}

map<string, shared_ptr<Card>> Card::SetIKA(map<string, shared_ptr<Card>>_allCard)
{
	wstring folderPath = L"Resource/Ironclad/Attack";
	vector<FileInfo> filePaths;
	Card::ListFilesInFolder(folderPath, filePaths);
	sort(filePaths.begin(), filePaths.end(), CompareFileNumbers);

	vector<wstring> file;

	for (const auto& fileInfo : filePaths) {
		file.emplace_back(L"Ironclad/Attack/" + fileInfo.filePath);
	}


	//wstring file, Type type, Rarity rarity, string name, int cost, int maxUpgrade, int upgrade, bool volatility, bool extinction
	_allCard.emplace("IKA0", make_shared<Card>(file[0], Card::Attack, Card::Common, "Strike", 1, 1, 0));
	_allCard.emplace("IKA1", make_shared<Card>(file[1], Card::Attack, Card::Common, "Bash", 2, 1, 0));
	_allCard.emplace("IKA2", make_shared<Card>(file[2], Card::Attack, Card::Common, "Anger", 0, 1, 0));
	_allCard.emplace("IKA3", make_shared<Card>(file[3], Card::Attack, Card::Common, "Body Slam", 1, 1, 0));
	_allCard.emplace("IKA4", make_shared<Card>(file[4], Card::Attack, Card::Common, "Clash", 0, 1, 0));
	_allCard.emplace("IKA5", make_shared<Card>(file[5], Card::Attack, Card::Common, "Cleave", 1, 1, 0));
	_allCard.emplace("IKA6", make_shared<Card>(file[6], Card::Attack, Card::Common, "Clothesline", 2, 1, 0));
	_allCard.emplace("IKA7", make_shared<Card>(file[7], Card::Attack, Card::Common, "Headbutt", 1, 1, 0));
	_allCard.emplace("IKA8", make_shared<Card>(file[8], Card::Attack, Card::Common, "Heavy Blade", 2, 1, 0));
	_allCard.emplace("IKA9", make_shared<Card>(file[9], Card::Attack, Card::Common, "Iron Wave", 1, 1, 0));
	_allCard.emplace("IKA10", make_shared<Card>(file[10], Card::Attack, Card::Common, "Perfected Strike", 2, 1, 0));
	_allCard.emplace("IKA11", make_shared<Card>(file[11], Card::Attack, Card::Common, "Pommel Strike", 1, 1, 0));
	_allCard.emplace("IKA12", make_shared<Card>(file[12], Card::Attack, Card::Common, "Sword Boomerang", 1, 1, 0));
	_allCard.emplace("IKA13", make_shared<Card>(file[13], Card::Attack, Card::Common, "Thunderclap", 1, 1, 0));
	_allCard.emplace("IKA14", make_shared<Card>(file[14], Card::Attack, Card::Common, "Twin Strike", 1, 1, 0));
	_allCard.emplace("IKA15", make_shared<Card>(file[15], Card::Attack, Card::Common, "Wild Strike", 1, 1, 0));

	_allCard.emplace("IKA16", make_shared<Card>(file[16], Card::Attack, Card::Special, "Blood for Blood", 4, 1, 0));
	_allCard.emplace("IKA17", make_shared<Card>(file[17], Card::Attack, Card::Special, "Carnage", 2, 1, 0, true));
	_allCard.emplace("IKA18", make_shared<Card>(file[18], Card::Attack, Card::Special, "Dropkick", 1, 1, 0));
	_allCard.emplace("IKA19", make_shared<Card>(file[19], Card::Attack, Card::Special, "Hemokinesis", 1, 1, 0));
	_allCard.emplace("IKA20", make_shared<Card>(file[20], Card::Attack, Card::Special, "Pummel", 1, 1, 0, false, true));
	_allCard.emplace("IKA21", make_shared<Card>(file[21], Card::Attack, Card::Special, "Rampage", 1, 1, 0));
	_allCard.emplace("IKA22", make_shared<Card>(file[22], Card::Attack, Card::Special, "Searing Blow", 2, 1, 0));
	_allCard.emplace("IKA23", make_shared<Card>(file[23], Card::Attack, Card::Special, "Sever Sou", 2, 1, 0));
	_allCard.emplace("IKA24", make_shared<Card>(file[24], Card::Attack, Card::Special, "Uppercut", 1, 1, 0));
	_allCard.emplace("IKA25", make_shared<Card>(file[25], Card::Attack, Card::Special, "Whirlwind", 6, 1, 0));
	_allCard.emplace("IKA26", make_shared<Card>(file[26], Card::Attack, Card::Special, "Reckless Charge", 0, 1, 0));

	_allCard.emplace("IKA27", make_shared<Card>(file[27], Card::Attack, Card::Rare, "Bludgeon", 3, 1, 0));
	_allCard.emplace("IKA28", make_shared<Card>(file[28], Card::Attack, Card::Rare, "Feed", 1, 1, 0, false, true));
	_allCard.emplace("IKA29", make_shared<Card>(file[29], Card::Attack, Card::Rare, "Fiend Fire", 1 ,1, 0, false, true));
	_allCard.emplace("IKA30", make_shared<Card>(file[30], Card::Attack, Card::Rare, "Immolate", 2, 1, 0));
	_allCard.emplace("IKA31", make_shared<Card>(file[31], Card::Attack, Card::Rare, "Reaper", 2, 1, 0, false, true));

	return _allCard;
}

//map<string, shared_ptr<Card>> Card::SetIKS(map<string, shared_ptr<Card>>_allCard)
//{
//	wstring folderPath = L"Resource/Ironclad/Skill";
//	vector<FileInfo> filePaths;
//	Card::ListFilesInFolder(folderPath, filePaths);
//	sort(filePaths.begin(), filePaths.end(), CompareFileNumbers);
//
//	vector<wstring> file;
//
//	for (const auto& fileInfo : filePaths) {
//		file.emplace_back(L"Ironclad/Skill/" + fileInfo.filePath);
//	}
//
//
//	//int cost, int power, int shield, int force, int agility,int draws, int weaken, int vulnerable, int maxUpgrade, int upgrade, int mWeaken, int mVulnerable, int injury, bool extinction = false
//	_allCard.emplace("IKS0", make_shared<Card>(file[0], Card::Skill, Card::Common, "Defend", 1, 1, 0));
//	_allCard.emplace("IKS1", make_shared<Card>(file[1], Card::Skill, Card::Common, "Armaments", 1, 1, 0));
//	_allCard.emplace("IKS2", make_shared<Card>(file[2], Card::Skill, Card::Common, "Flex", 0, 1, 0));
//	_allCard.emplace("IKS3", make_shared<Card>(file[3], Card::Skill, Card::Common, "Havoc Slam", 1, 1, 0));
//	_allCard.emplace("IKS4", make_shared<Card>(file[4], Card::Skill, Card::Common, "Shrug It Off", 1, 1, 0));
//	_allCard.emplace("IKS5", make_shared<Card>(file[5], Card::Skill, Card::Common, "True Grit", 1, 1, 0));
//	_allCard.emplace("IKS6", make_shared<Card>(file[6], Card::Skill, Card::Common, "Warcry", 0, 1, 0, false, true));
//	
//	_allCard.emplace("IKS7", make_shared<Card>(file[7], Card::Skill, Card::Special, "Battle Trance", 0,  1, 0));
//	_allCard.emplace("IKS8", make_shared<Card>(file[8], Card::Skill, Card::Special, "Dual Wield", 1, 1, 0));
//	_allCard.emplace("IKS9", make_shared<Card>(file[9], Card::Skill, Card::Special, "Bloodletting", 0, 1, 0));
//	_allCard.emplace("IKS10", make_shared<Card>(file[10], Card::Skill, Card::Special, "Burning Pact", 1, 1, 0));
//	_allCard.emplace("IKS11", make_shared<Card>(file[11], Card::Skill, Card::Special, "Disarm", 1, 1, 0, false, true));
//	_allCard.emplace("IKS12", make_shared<Card>(file[12], Card::Skill, Card::Special, "Entrench", 2, 1, 0));
//	_allCard.emplace("IKS13", make_shared<Card>(file[13], Card::Skill, Card::Special, "(Flame Barrier", 2, 1, 0));
//	_allCard.emplace("IKS14", make_shared<Card>(file[14], Card::Skill, Card::Special, "Ghostly Armor", 1, 1, 0, true));
//	_allCard.emplace("IKS15", make_shared<Card>(file[15], Card::Skill, Card::Special, "Infernal Blade", 1, 1, 0, false, true));
//	_allCard.emplace("IKS16", make_shared<Card>(file[16], Card::Skill, Card::Special, "Intimidate", 0, 1, 0, false, true));
//	_allCard.emplace("IKS17", make_shared<Card>(file[17], Card::Skill, Card::Special, "Power Through", 1, 1, 0));
//	_allCard.emplace("IKS18", make_shared<Card>(file[18], Card::Skill, Card::Special, "Rage", 0, 1, 0));
//	_allCard.emplace("IKS19", make_shared<Card>(file[19], Card::Skill, Card::Special, "Second Wind", 1, 1, 0));
//	_allCard.emplace("IKS20", make_shared<Card>(file[20], Card::Skill, Card::Special, "Seeing Red", 1, 1, 0));
//	_allCard.emplace("IKS21", make_shared<Card>(file[21], Card::Skill, Card::Special, "Sentinel", 1, 1, 0));
//	_allCard.emplace("IKS22", make_shared<Card>(file[22], Card::Skill, Card::Special, "Shockwave", 2, 1, 0));
//	_allCard.emplace("IKS23", make_shared<Card>(file[23], Card::Skill, Card::Special, "Spot Weakness", 1, 1, 0));
//	
//	_allCard.emplace("IKS24", make_shared<Card>(file[24], Card::Skill, Card::Rare, "Double Tap", 1, 1, 0));
//	_allCard.emplace("IKS25", make_shared<Card>(file[25], Card::Skill, Card::Rare, "Exhume", 1, 1, 0, false, true));
//	_allCard.emplace("IKS26", make_shared<Card>(file[26], Card::Skill, Card::Rare, "Impervious", 2, 1, 0,false, true));
//	_allCard.emplace("IKS27", make_shared<Card>(file[27], Card::Skill, Card::Rare, "Limit Break", 1, 1, 0,false, true));
//	_allCard.emplace("IKS28", make_shared<Card>(file[28], Card::Skill, Card::Rare, "Offering", 0, 1, 0, false, true));
//
//	return _allCard;
//}