#include "framework.h"
#include "Card.h"

Card::Card(wstring file, Type type, Rarity rarity, string name, int cost, int power, int shield, int force, int agility, int draws, int weaken, int vulnerable, int maxUpgrade, int upgrade, int mWeaken, int mVulnerable, int injury, int combo, int multi, int loss, bool volatility, bool extinction, bool isActive)
	:_type(type), _rarity(rarity), _name(name), _cost(cost), _power(power), _shield(shield), _force(force), _agility(agility), _draws(draws), _weaken(weaken), _vulnerable(vulnerable), _maxUpgrade(maxUpgrade), _upgrade(upgrade), _mWeaken(mWeaken), _mVulnerable(mVulnerable), _injury(injury), _combo(combo), _multi(multi), _loss(loss), _volatility(volatility), _extinction(extinction), _isActive(isActive)
{
	_card = make_shared<Quad>(file);
	_col = make_shared<RectCollider>(_card->GetTextureSize());
	_col->SetParent(_card->GetTransForm());
}

Card::~Card()
{

}

void Card::Update()
{
	//if (!_isActive)
	//	return;

	//_card->Update();
	//_col->Update();
}

void Card::Render()
{
	if (!_isActive)
		return;

	_card->Render();
	_col->Render();
}

void Card::SetPosition(Vector2 pos, float scale)
{
	_card->GetTransForm()->GetPos() = pos;
	_card->GetTransForm()->GetScale() *= scale;
}