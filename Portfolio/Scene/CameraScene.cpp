#include "framework.h"
#include "CameraScene.h"

CameraScene::CameraScene()
{
	Init();
	Setting();

	for (int i = 0; i < _deck.size(); i++)
		_deck2.emplace_back(make_shared<Card>(*_deck[i]));

}

CameraScene::~CameraScene()
{
}

void CameraScene::Update()
{

	_ironclad->Update();
	_gremlinNob->Update();

	//bool a = false;
	//vector<Card> s;

	//if (_hand[i]->GetCollider()->IsCollision(mousepos))
	//{
	//	s -> ? ? ? ;
	//	if (s[0]->GetCollider()->IsCollision(mousepos) && s[1]->GetCollider()->IsCollision(mousepos)
	//	{
	//		s[1]->RED
	//	}
	//	else
	//	{
	//		s[0]->Green
	//	}
	//}
	if (KeyDown('Q'))
	{
		ShuffleDeck();
		Drow();
		
	}
		for (int i = 0; i < _hand.size(); i++)
	{
		_hand[i]->Update();
	}

	if (!_hand.empty())
	{
		; a = _hand.size();
		for (int i = _hand.size() - 1; i > -1; i--)
		{
			if (_hand[i]->GetCollider()->IsCollision(mousepos))
			{
				if (a == _hand.size())
				{
					a = i;
					_hand[a]->GetCollider()->SetRed();
					_hand[a]->Cellact();
				}
				else
				{
					if (a < i)
					{
						_hand[i]->GetCollider()->SetRed();
						_hand[i]->Cellact();
						_hand[a]->GetCollider()->SetGreen();
						_hand[a]->UnCelled();
						a = i;
					}
					else
					{
						_hand[i]->GetCollider()->SetGreen();
						_hand[i]->UnCelled();
					}	
				}
				if (KeyDown(VK_LBUTTON))
				{
					_hand[a]->Cellact();
				}
				if (KeyUp(VK_LBUTTON))
				{
					_hand[a]->UnCelled();
				}
			}
			else
			{
				_hand[i]->GetCollider()->SetGreen();
				_hand[i]->UnCelled();
			}
		}
		/*while (KeyDown(VK_LBUTTON))
		{
			_hand[a]->Cellact();
			if (KeyUp(VK_LBUTTON))
			{
				_hand[a]->UnCelled();
				break;
			}
		}*/

		

	}
		
		//if (_hand[1]->GetCollider()->IsCollision(mousepos))
		//{

		//	_hand[1]->GetCollider()->SetRed();
		//}	

		//else
		//	_hand[1]->GetCollider()->SetGreen();
	



	if (KeyDown('E'))
	{
		if (_hand.size() != 0)
		{
			for (int i = 0; i < _hand.size(); i++)
			{
				_discarded.emplace_back(make_shared<Card>(*_hand[i]));
			}
			_hand.erase(_hand.begin(), _hand.begin() + _hand.size());
		}
	}
	
	


	//while (!AllDead(_ironclad) && !AllDead(_gremlinNob))
	//{
		//UsingCard(_deck2[2], _ironclad, _gremlinNob);
		//_discarded.emplace_back(make_shared<Card>(*_deck2[2]));
	//}


}

void CameraScene::Render()
{
	_ironclad->Render();
	_gremlinNob->Render();


	for (int i = 0; i < _hand.size(); i++)
	{
		_hand[i]->Render();
	}

}

void CameraScene::PostRender()
{
}

void CameraScene::Init()
{
	_ironclad = make_shared<Ironclad>();
	_gremlinNob = make_shared<GremlinNob>();
	
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
}

void CameraScene::ShuffleDeck()
{
	random_device rd;
	mt19937 gen(rd());
	shuffle(_deck2.begin(), _deck2.end(), gen);
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
		_hand[i]->SetPosition(Vector2(300.0f + (i * 80), 0.0f));

}
