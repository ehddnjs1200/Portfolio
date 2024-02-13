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

	int GetDraws() { return _draws; }
	int SetCost(int cost) { return _cost + cost; }

	void SetMaxHp(int cost) { _maxHp += cost; }

private:

	int _cost;
	int _maxHp;
	int _draws;
};

