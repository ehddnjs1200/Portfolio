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
	Card(wstring file, Card::Type type, Card::Rarity rarity, string name, int cost, int maxUpgrade, int upgrade, int combo = 1, int multi = 1, bool volatility = false, bool extinction = false);
	Card(const Card& other);
	~Card();

	void Update();
	void Render();

	void SetPosition(Vector2 pos);

	void SetChoice();

	void Cellact();

	void UnCelled();

	void ListFilesInFolder(const wstring& folderPath, vector<FileInfo>& filePaths);

	map<string, shared_ptr<Card>> SetIKA(map<string, shared_ptr<Card>>_allCard);

	//map<string, shared_ptr<Card>> SetIKS(map<string, shared_ptr<Card>> _allCard);

	shared_ptr<Collider> GetCollider() { return _col; }

	shared_ptr<Transform> IsActive() { return _card->GetTransForm(); }

	Vector2 GetPos() { return _pos; }

	wstring GetFile() { return _file; }
	Type GetType() { return _type; }
	Rarity GetRarity() { return _rarity; }
	string GetName() { return _name; }
	int GetCost() { return _cost; }
	int GetCombo() { return _combo; }
	int GetMulti() { return _multi; }
	int GetMaxUg() { return _maxUpgrade; }
	int GetUg() { return _upgrade; }
	bool GetVolatility() { return _volatility; }
	bool GetExtinction()  { return _extinction; }
	bool GetChoice() { return  _choice; }

private:

	shared_ptr<Quad> _card;
	shared_ptr<Collider> _col;

	Type _type = Type::Attack;
	Rarity _rarity = Rarity::Common;

	Vector2 _pos = { 0,0 };
	wstring _file;
	string _name;
	int _cost = 0;
	int _maxUpgrade = 1;
	int _upgrade = 0;
	int _combo = 0;
	int _multi = 0;
	bool _volatility = false;
	bool _extinction = false;

	bool _choice = false;
};

