#pragma once
class Card
{
public:

	struct FileInfo {
		wstring filePath;
		int fileNumber;  // 파일명에서 추출한 숫자
	};

	enum Type
	{
		Attack,
		Skill,
		Power
	};

	enum Rarity
	{
		Common,
		Special,
		Rare
	};
	Card() {};
	Card(wstring file,Type type, Rarity rarity, string name, int cost, int power, int shield, int force, int agility,int draws, int weaken, int vulnerable, int maxUpgrade, int upgrade, int mWeaken, int mVulnerable, int injury,int combo,int multi, int loss, bool volatility = false, bool extinction = false, bool _isActive = false);
	Card(const Card& other);
	~Card();

	void Update();
	void Render();

	void SetPosition(Vector2 pos);

	void ListFilesInFolder(const wstring& folderPath, vector<FileInfo>& filePaths);

	map<string, shared_ptr<Card>> SetIKA(map<string, shared_ptr<Card>>_allCard);

	shared_ptr<Transform> IsActive() { return _card->GetTransForm(); }

	void Draw() { _isActive = true; }

	int GetPower() { return _power; }
	int GetShield() { return _shield; }
	int GetForce() { return _force; }
	int GetAgility() { return _agility; }
	int GetWeaken() { return _weaken; }
	int GetVulnerable() { return _vulnerable; }
	int GetDraws() { return _draws; }
	int GetmWeaken() { return _mWeaken; }
	int GetmVulnerable() { return _mVulnerable; }

private:

	shared_ptr<Quad> _card;
	shared_ptr<Collider> _col;

	Type _type = Type::Attack;
	Rarity _rarity = Rarity::Common;

	Vector2 _pos = { 0,0 };
	wstring _file;
	string _name;
	int _cost;
	int _power;
	int _shield;
	int _force;
	int _agility;
	int _draws;
	int _weaken;
	int _vulnerable;
	int _maxUpgrade;
	int _upgrade;
	int _mWeaken;
	int _mVulnerable;
	int _injury;
	int _combo;
	int _multi;
	int _loss;
	bool _volatility = false;
	bool _extinction = false;

	bool _isActive = false;
};

