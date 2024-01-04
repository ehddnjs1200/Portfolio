#include "framework.h"
#include "CameraScene.h"

CameraScene::CameraScene()
{
	Init();
	Setting();

	
}

CameraScene::~CameraScene()
{
}

void CameraScene::Update()
{

	_ironclad->Update();
	_gremlinNob->Update();

	//Drow();


	//_deck[2]->SetPosition(Vector2(CenterX, CenterY));

	_deck[0]->Update();
	_deck[1]->Update();
	//_deck[2]->Update();

	//while (!AllDead(_ironclad) && !AllDead(_gremlinNob))
	//{
	//	

	//}


}

void CameraScene::Render()
{
	_ironclad->Render();
	_gremlinNob->Render();



	_deck[0]->Render();
	_deck[1]->Render();
	//_deck[2]->Render();
}

void CameraScene::PostRender()
{
}

void CameraScene::Init()
{
	_ironclad = make_shared<Ironclad>();
	_gremlinNob = make_shared<GremlinNob>();
    _allCard = make_shared<Card>();
}



void CameraScene::Setting()
{

	_allCard->SetIKA();

	for (int i = 0; i < 2; i++) {
		shared_ptr<Card> cardIKA0 = _allCard->GetCard("IKA0");
		if (cardIKA0) {
			_deck.emplace_back(make_shared<Card>(*cardIKA0));
		}
		else {
			// 예외 처리 또는 로그 기록 등을 추가할 수 있습니다.
		}
	}
	auto ptr0 = _deck[0].get();
	auto ptr1 = _deck[1].get();
	//_deck[0]->SetPosition(Vector2(CenterX, CenterY));
	//_deck[1]->SetPosition(Vector2(CenterX, 0));
	_deck[0]->IsActive()->SetPos(Vector2(CenterX, 0));
	_deck[1]->IsActive()->SetPos(Vector2(CenterX, CenterY));
	//_deck[1]->SetPosition(Vector2(CenterX, 0));
	//_deck.emplace_back(make_shared<Card>(_allCard->GetAllCard()["IKA1"].get()));

}

void CameraScene::ShuffleDeck()
{
	random_device rd;
	mt19937 gen(rd());
	shuffle(_deck.begin(), _deck.end(), gen);
}



void CameraScene::Drow()
{
	//int a = 0;
	//for (int i = 0; i < _ironclad->GetDraws(); i++)
	//{
	//	if (_deck.size() == 0)
	//	{
	//		for (int j = 0; j < _discarded.size(); j++)
	//		{
	//			_deck.emplace_back(_discarded[j]);
	//		}
	//	}

	//	if (!_deck[i]->IsActive())
	//	{
	//		_deck[i]->Draw();
	//		_hand.emplace_back(_deck[i]);
	//		a++;
	//	}
	//}
	//_deck.erase(_deck.begin(), _deck.begin() + a);

	_deck[0]->Draw();
	_deck[1]->Draw();
	//_deck[2]->Draw();


	//_deck[0]->SetPosition();

}

void CameraScene::UsingCard(shared_ptr<Character> enemy, shared_ptr<Card> card)
{
	if (enemy->GetVulnerable() > 0 && _ironclad->GetWeaken() > 0)
		enemy->SetHp(enemy->GetHp() - (((card->GetPower() + _ironclad->GetForce()) * 1.5f) * 0.75));
	else if (enemy->GetVulnerable() > 0)
		enemy->SetHp(enemy->GetHp() - ((card->GetPower() + _ironclad->GetForce()) * 1.5f));
	else if (_ironclad->GetWeaken() > 0)
		enemy->SetHp(enemy->GetHp() - ((card->GetPower() + _ironclad->GetForce()) * 0.75));
	else
		enemy->SetHp(enemy->GetHp() - (card->GetPower() + _ironclad->GetForce()));


	if (card->GetmVulnerable()>0)
		_ironclad->SetVulnerable(_ironclad->GetVulnerable() + card->GetmVulnerable());

	if (card->GetmWeaken()>0)
		_ironclad->SetWeaken(_ironclad->GetWeaken() + card->GetmWeaken());

}
