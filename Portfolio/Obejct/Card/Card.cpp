#include "framework.h"
#include "Card.h"

Card::Card(wstring file, Type type, Rarity rarity, string name, int cost, int power, int shield, int force, int agility, int draws, int weaken, int vulnerable, int maxUpgrade, int upgrade, int mWeaken, int mVulnerable, int injury, int combo, int multi, int loss, bool volatility, bool extinction, bool isActive)
	:_type(type), _rarity(rarity), _name(name), _cost(cost), _power(power), _shield(shield), _force(force), _agility(agility), _draws(draws), _weaken(weaken), _vulnerable(vulnerable), _maxUpgrade(maxUpgrade), _upgrade(upgrade), _mWeaken(mWeaken), _mVulnerable(mVulnerable), _injury(injury), _combo(combo), _multi(multi), _loss(loss), _volatility(volatility), _extinction(extinction), _isActive(isActive)
{
	_card = make_shared<Quad>(file);
	_card->GetTransForm()->GetScale() *= 0.5f;

	_col = make_shared<RectCollider>(_card->GetTextureSize());
	_col->SetParent(_card->GetTransForm());
}

Card::Card(const Card& other)
	: _type(other._type), _rarity(other._rarity),
	_name(other._name), _cost(other._cost), _power(other._power),
	_shield(other._shield), _force(other._force), _agility(other._agility),
	_draws(other._draws), _weaken(other._weaken), _vulnerable(other._vulnerable),
	_maxUpgrade(other._maxUpgrade), _upgrade(other._upgrade),
	_mWeaken(other._mWeaken), _mVulnerable(other._mVulnerable),
	_injury(other._injury), _combo(other._combo), _multi(other._multi),
	_loss(other._loss), _volatility(other._volatility),
	_extinction(other._extinction), _isActive(other._isActive){

	_card = make_shared<Quad>(*other._card);
	_col = make_shared<RectCollider>(*other._col);
	// 복사 생성자에서 _allCard를 초기화하면서 새로운 shared_ptr을 생성
	for (const auto& entry : other._allCard) {
		_allCard[entry.first] = make_shared<Card>(*entry.second);
	}
}

Card::~Card()
{

}

void Card::Update()
{
	//_card->GetTransForm()->GetPos() = _pos;
	_card->GetTransForm()->SetPos(_pos);
	//_card->Update();
	//_col->Update();
}

void Card::Render()
{
	_card->Render();
	_col->Render();
}

void Card::SetPosition(Vector2 pos)
{
	_pos = pos;
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

map<string, shared_ptr<Card>> Card::SetIKA()
{
	wstring folderPath = L"Resource/Ironclad/Attack";
	vector<FileInfo> filePaths;
	Card::ListFilesInFolder(folderPath, filePaths);
	sort(filePaths.begin(), filePaths.end(), CompareFileNumbers);

	vector<wstring> file;

	for (const auto& fileInfo : filePaths) {
		file.emplace_back(L"Ironclad/Attack/" + fileInfo.filePath);
	}
	shared_ptr<Card> newCard = make_shared<Card>(file[0], Card::Attack, Card::Common, "Strike", 1, 6, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0);
	_allCard["IKA0"] = newCard;


	//int cost, int power, int shield, int force, int agility,int draws, int weaken, int vulnerable, int maxUpgrade, int upgrade, int mWeaken, int mVulnerable, int injury, bool extinction = false
	_allCard.emplace("IKA0", make_shared<Card>(file[0], Card::Attack, Card::Common, "Strike", 1, 6, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA1", make_shared<Card>(file[1], Card::Attack, Card::Common, "Bash", 2, 8, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA2", make_shared<Card>(file[2], Card::Attack, Card::Common, "Anger", 0, 6, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA3", make_shared<Card>(file[3], Card::Attack, Card::Common, "Body Slam", 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA4", make_shared<Card>(file[4], Card::Attack, Card::Common, "Clash", 0, 14, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA5", make_shared<Card>(file[5], Card::Attack, Card::Common, "Cleave", 1, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 3, 0));
	_allCard.emplace("IKA6", make_shared<Card>(file[6], Card::Attack, Card::Common, "Clothesline", 2, 12, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA7", make_shared<Card>(file[7], Card::Attack, Card::Common, "Headbutt", 1, 9, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA8", make_shared<Card>(file[8], Card::Attack, Card::Common, "Heavy Blade", 2, 14, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA9", make_shared<Card>(file[9], Card::Attack, Card::Common, "Iron Wave", 1, 5, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA10", make_shared<Card>(file[10], Card::Attack, Card::Common, "Perfected Strike", 2, 6, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA11", make_shared<Card>(file[11], Card::Attack, Card::Common, "Pommel Strike", 1, 6, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA12", make_shared<Card>(file[12], Card::Attack, Card::Common, "Sword Boomerang", 1, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 3, 2, 0));
	_allCard.emplace("IKA13", make_shared<Card>(file[13], Card::Attack, Card::Common, "Thunderclap", 1, 4, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 3, 0));
	_allCard.emplace("IKA14", make_shared<Card>(file[14], Card::Attack, Card::Common, "Twin Strike", 1, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 1, 0));
	_allCard.emplace("IKA15", make_shared<Card>(file[15], Card::Attack, Card::Common, "Wild Strike", 1, 12, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0));

	_allCard.emplace("IKA16", make_shared<Card>(file[16], Card::Attack, Card::Special, "Blood for Blood", 4, 18, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA17", make_shared<Card>(file[17], Card::Attack, Card::Special, "Carnage", 2, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, true));
	_allCard.emplace("IKA18", make_shared<Card>(file[18], Card::Attack, Card::Special, "Dropkick", 1, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA19", make_shared<Card>(file[19], Card::Attack, Card::Special, "Hemokinesis", 1, 15, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 2));
	_allCard.emplace("IKA20", make_shared<Card>(file[20], Card::Attack, Card::Special, "Pummel", 1, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 0, 0, false, true));
	_allCard.emplace("IKA21", make_shared<Card>(file[21], Card::Attack, Card::Special, "Rampage", 1, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA22", make_shared<Card>(file[22], Card::Attack, Card::Special, "Searing Blow", 2, 12, 0, 0, 0, 0, 0, 0, 60, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA23", make_shared<Card>(file[23], Card::Attack, Card::Special, "Sever Sou", 2, 16, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA24", make_shared<Card>(file[24], Card::Attack, Card::Special, "Uppercut", 1, 13, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA25", make_shared<Card>(file[25], Card::Attack, Card::Special, "Whirlwind", 6, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0));
	_allCard.emplace("IKA26", make_shared<Card>(file[26], Card::Attack, Card::Special, "Reckless Charge", 0, 7, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0));

	_allCard.emplace("IKA27", make_shared<Card>(file[27], Card::Attack, Card::Rare, "Bludgeon", 3, 32, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0));
	_allCard.emplace("IKA28", make_shared<Card>(file[28], Card::Attack, Card::Rare, "Feed", 1, 10, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, false, true));
	_allCard.emplace("IKA29", make_shared<Card>(file[29], Card::Attack, Card::Rare, "Fiend Fire", 1, 7, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, false, true));
	_allCard.emplace("IKA30", make_shared<Card>(file[30], Card::Attack, Card::Rare, "Immolate", 2, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 3, 0));
	_allCard.emplace("IKA31", make_shared<Card>(file[31], Card::Attack, Card::Rare, "Reaper", 2, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 3, 0, false, true));

	return _allCard;
}