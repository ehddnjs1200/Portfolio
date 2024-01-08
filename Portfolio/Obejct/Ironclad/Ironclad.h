#pragma once

class Ironclad : public Character
{
public:
	Ironclad();
	virtual ~Ironclad();

	virtual void Update() override;
	virtual void Render() override;
	void Init();
	void Setting();

	int GetDraws() { return _draws; }
	int SetCost(int cost) { return _cost + cost; }

private:

	int _cost = 3;
	int _maxHp = 80;
	int _draws = 5;
};

