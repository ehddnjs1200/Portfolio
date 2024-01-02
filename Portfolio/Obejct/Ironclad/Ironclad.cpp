#include "framework.h"
#include "Ironclad.h"


Ironclad::Ironclad()
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
}

void Ironclad::Render()
{
	_character->Render();
}

void Ironclad::Init()
{
	_character = make_shared<Quad>(L"Ironclad/Ironclad.png");
}

void Ironclad::Setting()
{
	SetPos(Vector2(CenterX-240, CenterY), 0.8f);
}
