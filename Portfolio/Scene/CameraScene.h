#pragma once

class CameraScene : public Scene
{
public:
	CameraScene();
	virtual ~CameraScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void Init();
	void Setting();

	void ShuffleDeck();

	bool AllDead(shared_ptr<Character> player)
	{
		if (player->GetHp() == 0)
			return false;
		return true;
	}

	void TurnStrat();
	
	void TurnEnd();

	void Drow();

private:
	shared_ptr<Ironclad> _ironclad;
	vector<shared_ptr<GremlinNob>> _monsters;
	map<string, shared_ptr<Card>>_allCard;
	vector<shared_ptr<Card>> _deck;
	vector<shared_ptr<Card>> _deck2;
	vector<shared_ptr<Card>> _hand;
	vector<shared_ptr<Card>> _discarded;
	shared_ptr<Map1> _backgrund;

	int a = 0;
	int hand2;
};

