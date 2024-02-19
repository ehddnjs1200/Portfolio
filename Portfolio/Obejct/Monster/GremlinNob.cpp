#include "framework.h"
#include "GremlinNob.h"

GremlinNob::GremlinNob(int maxHp)
	:_maxHp(maxHp)
{
	Init();
	Setting();
}

GremlinNob::~GremlinNob()
{
}

void GremlinNob::Update()
{
	_character->Update();
	_col->Update  ();
	if (GetVulnerable() >0)
		SetVulnerable(GetVulnerable() - 1);

	if (GetWeaken() > 0)
		SetWeaken(GetWeaken() - 1);

	_hpBar->Update();
}

void GremlinNob::Render()
{
	_character->Render();
	//_col->Render();
	_hpBar->Render();
}

void GremlinNob::Init()
{
	_character = make_shared<Quad>(L"Monster/Gremlin Nob.png");
	_col = make_shared<RectCollider>(_character->GetTextureSize());
	_col->SetParent(_character->GetTransForm());
}

void GremlinNob::Setting()
{
	SetPos(Vector2(CenterX + 310, CenterY-10), 0.8f);

	_hp = _maxHp;
	_hpBar = make_shared<HealthBar>(Vector2(CenterX + 310, CenterY - 180),_maxHp, _hp, 30);

}

void GremlinNob::GetInfuriating()
{
	SetForce(_force + 1);
}

void GremlinNob::SkullStrike(shared_ptr<Character> enemy)
{
	int damage;
	if (enemy->GetVulnerable() > 0 && this->GetWeaken() > 0)
		damage = (((6 + this->GetForce()) * 1.5f) * 0.75);
	else if (enemy->GetVulnerable() > 0)
		damage = ((6 + this->GetForce()) * 1.5f);
	else if (this->GetWeaken() > 0)
		damage = ((6 + this->GetForce()) * 0.75);
	else
		damage =(6 + this->GetForce());

	enemy->GetDemage(damage);
	enemy->SetVulnerable(2);
}

void GremlinNob::Strike(shared_ptr<Character> enemy)
{
	int damage;
	if (enemy->GetVulnerable() > 0 && this->GetWeaken() > 0)
		damage = (((6 + this->GetForce()) * 1.5f) * 0.75);
	else if (enemy->GetVulnerable() > 0)
		damage = ((6 + this->GetForce()) * 1.5f);
	else if (this->GetWeaken() > 0)
		damage = ((6 + this->GetForce()) * 0.75);
	else
		damage = (6 + this->GetForce());

	enemy->GetDemage(damage);
}

void GremlinNob::Attack(int pattern, shared_ptr<Character> enemy)
{
	if (pattern == 1)
		SkullStrike(enemy);
	if (pattern == 2)
		Strike(enemy);

}
