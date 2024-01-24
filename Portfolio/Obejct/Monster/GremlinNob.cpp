#include "framework.h"
#include "GremlinNob.h"

GremlinNob::GremlinNob()
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

}

void GremlinNob::Render()
{
	_character->Render();
	_col->Render();
}

void GremlinNob::Init()
{
	_character = make_shared<Quad>(L"Monster/Gremlin Nob.png");
	_col = make_shared<RectCollider>(_character->GetTextureSize());
	_col->SetParent(_character->GetTransForm());
}

void GremlinNob::Setting()
{
	SetHp(86);
	SetPos(Vector2(CenterX + 240, CenterY + 40), 0.8f);
}

void GremlinNob::GetInfuriating()
{
	SetForce(_force + 1);
}

void GremlinNob::SkullStrike(shared_ptr<Character> enemy)
{
	if (enemy->GetVulnerable() > 0 && this->GetWeaken() > 0)
		enemy->SetHp(enemy->GetHp() - (((6 + this->GetForce()) * 1.5f) * 0.75));
	else if (enemy->GetVulnerable() > 0)
		enemy->SetHp(enemy->GetHp() - ((6 + this->GetForce()) * 1.5f));
	else if (this->GetWeaken() > 0)
		enemy->SetHp(enemy->GetHp() - ((6 + this->GetForce()) * 0.75));
	else
		enemy->SetHp(enemy->GetHp() - (6 + this->GetForce()));

	enemy->SetVulnerable(2);
}

void GremlinNob::Strike(shared_ptr<Character> enemy)
{
	if (enemy->GetVulnerable() > 0 && this->GetWeaken() > 0)
		enemy->SetHp(enemy->GetHp() - (((6 + this->GetForce()) * 1.5f) * 0.75));
	else if (enemy->GetVulnerable() > 0)
		enemy->SetHp(enemy->GetHp() - ((6 + this->GetForce()) * 1.5f));
	else if (this->GetWeaken() > 0)
		enemy->SetHp(enemy->GetHp() - ((6 + this->GetForce()) * 0.75));
	else
		enemy->SetHp(enemy->GetHp() - (6 + this->GetForce()));
}
