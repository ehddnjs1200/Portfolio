#pragma once
static int SelectCard(vector<shared_ptr<Card>> _hand, int hand2)
{
	if (!_hand.empty())
	{
		int selectCard = _hand.size();
		for (int i = _hand.size() - 1; i > -1; i--)
		{
			if (_hand[i]->GetCollider()->IsCollision(mousepos))
			{
				if (selectCard == _hand.size())
				{
					selectCard = i;
					_hand[selectCard]->GetCollider()->SetRed();
					_hand[selectCard]->Cellact();
				}
				else
				{
					if (selectCard < i)
					{
						_hand[i]->GetCollider()->SetRed();
						_hand[i]->Cellact();
						_hand[selectCard]->GetCollider()->SetGreen();
						_hand[selectCard]->UnCelled();
						selectCard = i;
					}
					else
					{
						_hand[i]->GetCollider()->SetGreen();
						_hand[i]->UnCelled();
					}
				}
				if (KeyDown(VK_LBUTTON))
					hand2 = selectCard;
			}
			else
			{
				if (hand2 != i)
				{
					_hand[i]->GetCollider()->SetGreen();
					_hand[i]->UnCelled();
				}
			}
		}
	}
	return hand2;
}

static void PlayerAttack(shared_ptr<Card> card, shared_ptr<Ironclad> player, shared_ptr<Character> monster)
{
	for (int i = 0; i < card->GetCombo(); i++)
		UsingCard(card, player, monster);
}


static void MonsterTurn(shared_ptr<Ironclad> player, shared_ptr<GremlinNob> monster)
{
	// 시드를 생성
	random_device rd;
	// 랜덤 네너레이터 생성
	mt19937 gen(rd());
	// 원하는 분포를 선택
	uniform_int_distribution<int> dis(1, monster->Pattern()); // 주어진 범위에서 균일하게 선택

	// 랜덤한 수 생성
	int random_number = dis(gen);


	monster->Attack(random_number, player);

}