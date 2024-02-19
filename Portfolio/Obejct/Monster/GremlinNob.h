#pragma once
class GremlinNob : public Character
{
public:
	GremlinNob(int maxHp);
	virtual ~GremlinNob();


	virtual void Update() override;
	virtual void Render() override;

	void Init();
	void Setting();

	int Pattern() { return _pattern; }

	void GetInfuriating();
	void SkullStrike(shared_ptr<Character> enemy);
	void Strike(shared_ptr<Character> enemy);

	void Attack(int pattern, shared_ptr<Character> enemy);

private:

	int _maxHp;
	int _pattern = 2;
};

