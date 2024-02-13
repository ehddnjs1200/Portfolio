#include "framework.h"
#include "Ironclad.h"


Ironclad::Ironclad(int cost, int maxHp, int draws)
	:_cost(cost), _maxHp(maxHp), _draws(draws)
{
	Init();
	Setting();
}

Ironclad::~Ironclad()
{
}

void Ironclad::Update()
{
	_character->Update();
	_hpBar->Update();
}

void Ironclad::Render()
{
	_character->Render();
	_hpBar->Render();
}

void Ironclad::Init()
{
	_character = make_shared<Quad>(L"Ironclad/Ironclad.png");
}

void Ironclad::Setting()
{
	SetPos(Vector2(CenterX - 240, CenterY - 10), 0.8f);
	_hp = _maxHp;
	_hpBar = make_shared<HealthBar>(_maxHp, _hp,30);
}
