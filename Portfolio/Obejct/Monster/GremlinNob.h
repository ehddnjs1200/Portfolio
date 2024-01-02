#pragma once
class GremlinNob : public Character
{
public:
	GremlinNob();
	virtual ~GremlinNob();


	virtual void Update() override;
	virtual void Render() override;

	void Init();
	void Setting();

	void GetInfuriating();
	void SkullStrike(shared_ptr<Character> enemy);
	void Strike(shared_ptr<Character> enemy);

private:


};

