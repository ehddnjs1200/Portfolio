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
	virtual void SceneTest() override;

	void Init();

	void Setting();

	void ShuffleDeck();

	bool AllDead(shared_ptr<Character> player)
	{
		if (player->GetHp() <= 0)
			return false;

		return true;
	}

	bool AllDead(vector<shared_ptr<GremlinNob>> player)
	{
		for (int i = 0; i < player.size(); i++)
		{
			if (player[i]->GetHp() <= 0)
				return false;
		}
		return true;
	}

	void TurnStrat();
	
	void TurnEnd();

	void Drow();

	void NextScene();

	void NextMonster();

private:
	shared_ptr<Ironclad> _ironclad;
	vector<shared_ptr<GremlinNob>> _monsters;
	map<string, shared_ptr<Card>>_allCard;
	vector<shared_ptr<Card>> _deck;
	vector<shared_ptr<Card>> _deck2;
	vector<shared_ptr<Card>> _hand;
	vector<shared_ptr<Card>> _discarded;
	shared_ptr<Map1> _backgrund;

	shared_ptr<Button> _NextTurn;

	int a = 0;
	int hand2;
};

