#pragma once

class Ironclad : public Character
{
public:
	Ironclad(int cost, int maxHp, int draws);
	virtual ~Ironclad();

	virtual void Update() override;
	virtual void Render() override;
	void Init();
	void Setting();


	int GetCost() { return _cost; }
	int GetDraws() { return _draws; }
	void SetCost() { _cost = _maxCost; }
	void UsingCost(int cost) { _cost -= cost; }

	void SetMaxHp(int cost) { _maxHp += cost; }

private:

	int _cost;
	int _maxCost;
	int _maxHp;
	int _draws;
};

