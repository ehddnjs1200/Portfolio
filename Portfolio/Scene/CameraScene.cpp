#include "framework.h"
#include "CameraScene.h"

CameraScene::CameraScene()
{
	Init();
	Setting();

	for (int i = 0; i < _deck.size(); i++)
		_deck2.emplace_back(make_shared<Card>(*_deck[i]));

	TurnStrat();
}

CameraScene::~CameraScene()
{

}

void CameraScene::Update()
{
	_backgrund->Update();
	_ironclad->Update();
	_NextTurn->Update();

	for (int i = 0; i < _monsters.size(); i++)
		_monsters[i]->Update();

	if (!_hand.empty())
	{
		hand2 = SelectCard(_hand, hand2);

		if (hand2 < _hand.size())
		{
			if (KeyDown(VK_LBUTTON))
			{
				_hand[hand2]->Cellact();
			}
			if (KeyUp(VK_LBUTTON))
			{
				if (_monsters[0]->GetCollider()->IsCollision(mousepos))
				{
					PlayerAttack(_hand[hand2], _ironclad, _monsters[0]);
					if (_hand[hand2]->GetChoice())
					{
						_discarded.emplace_back(make_shared<Card>(*_hand[hand2]));
						_hand.erase(_hand.begin() + hand2);
					}
				}
				else
					_hand[hand2]->UnCelled();

				hand2 = _hand.size();
			}
		}
	}

	if (!AllDead(_monsters[0]))
	{
		scene = 1;
		NextScene();
	}
	

	for (int i = 0; i < _hand.size(); i++)
	{
		_hand[i]->Update();
	}

	

	if (KeyDown('E'))
	{
		TurnEnd();
	}
}

void CameraScene::Render()
{
	_backgrund->Render();
	_ironclad->Render();
	for (int i = 0; i < _monsters.size(); i++)
		_monsters[i]->Render();


	for (int i = 0; i < _hand.size(); i++)
	{
		_hand[i]->Render();
	}
}

void CameraScene::PostRender()
{
	_NextTurn->PostRender();
}

void CameraScene::Init()
{
	_ironclad = make_shared<Ironclad>(3,180,5);
	_monsters.emplace_back(make_shared<GremlinNob>(86));
	_backgrund = make_shared<Map1>();

	_NextTurn = make_shared<Button>(L"buttonL.png");
}



void CameraScene::Setting()
{
	_allCard = make_shared<Card>()->SetIKA(_allCard);

	shared_ptr<Card> cardIKA0 = _allCard["IKA0"];
	for (int i = 0; i < 8; i++) {
		cardIKA0 = _allCard["IKA0"];
		if (cardIKA0) {
			_deck.emplace_back(make_shared<Card>(*cardIKA0));
		}
		else {
			// 예외 처리 또는 로그 기록 등을 추가할 수 있습니다.
		}
	}
	cardIKA0 = _allCard["IKA1"];
	if (cardIKA0) 
	{
		_deck.emplace_back(make_shared<Card>(*cardIKA0));
		_deck.emplace_back(make_shared<Card>(*cardIKA0));
	}

	_NextTurn->SetPosition(Vector2(CenterX + 400, CenterY - 230));
	_NextTurn->SetScale(Vector2(0.3f, 0.3f));

	_NextTurn->SetEvent(bind(&CameraScene::TurnEnd, this));

}

void CameraScene::ShuffleDeck()
{
	random_device rd;
	mt19937 gen(rd());
	shuffle(_deck2.begin(), _deck2.end(), gen);
}



void CameraScene::TurnStrat()
{
	ShuffleDeck();
	_ironclad->SetCost();
	Drow();

}

void CameraScene::TurnEnd()
{
	if (_hand.size() != 0)
	{
		for (int i = 0; i < _hand.size(); i++)
		{
			_discarded.emplace_back(make_shared<Card>(*_hand[i]));
		}
		_hand.erase(_hand.begin(), _hand.begin() + _hand.size());
	}


	MonsterTurn(_ironclad, _monsters[0]);

	if (!AllDead(_ironclad))
	{
		scene = 2;
		NextScene();
	}
	TurnStrat();
}

void CameraScene::Drow()
{
	int draw = _ironclad->GetDraws();
	
	if (_discarded.size() + _deck2.size() < draw)
		draw = _discarded.size() + _deck2.size();
	int b = 0;
	for (int i = 0; i < draw; i++)
	{
		if (_deck2.size() == 0)
		{
			for (int j = 0; j < _discarded.size(); j++)
				_deck2.emplace_back(make_shared<Card>(*_discarded[j]));

			_discarded.erase(_discarded.begin(), _discarded.begin() + _discarded.size());
		}

		if (_deck2.size() < _ironclad->GetDraws())
		{
			for (int j = 0; j < _deck2.size(); j++)
			{
				_hand.emplace_back(make_shared<Card>(*_deck2[j]));
				i++;
			}
			b = _deck2.size();
			_deck2.erase(_deck2.begin(), _deck2.begin() + _hand.size());

			for (int j = 0; j < _discarded.size(); j++)
				_deck2.emplace_back(make_shared<Card>(*_discarded[j]));
		}
		else
			_hand.emplace_back(make_shared<Card>(*_deck2[i]));

	}
	_deck2.erase(_deck2.begin(), _deck2.begin() + (draw - b));


	for (int i = 0; i < _hand.size(); i++)
	{
		int half = _hand.size() / 2;
		if (_hand.size() % 2 != 0)
		{
			if (i == half)
				_hand[i]->SetPosition(Vector2(CenterX, 0.0f));
			else if (i < half)
				_hand[i]->SetPosition(Vector2(CenterX - ((half - i) * 80), 0.0f));
			else
				_hand[i]->SetPosition(Vector2(CenterX + ((i - half) * 80), 0.0f));
		}

		if (_hand.size() % 2 == 0)
		{
			if (i == half - 1)
				_hand[i]->SetPosition(Vector2(CenterX - 40, 0.0f));
			else if (i == half)
				_hand[i]->SetPosition(Vector2(CenterX + 40, 0.0f));
			else if (i < half)
				_hand[i]->SetPosition(Vector2(CenterX - ((half - i) * 80) + 40, 0.0f));
			else
				_hand[i]->SetPosition(Vector2(CenterX + ((i - half + 1) * 80) - 40, 0.0f));
		}
	}

}

void CameraScene::NextScene()
{
	int a = 5;
	SceneManager::GetInstace()->SetScene("End");
}
