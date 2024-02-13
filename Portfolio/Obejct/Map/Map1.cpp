#include "framework.h"
#include "Map1.h"

Map1::Map1()
{
	Init();
	Setting();
}

Map1::~Map1()
{
}

void Map1::Update()
{
	backgrund1->Update();
	//backgrund2->Update();
}

void Map1::Render()
{
	backgrund1->Render();
	//backgrund2->Render();
}

void Map1::Init()
{
	backgrund1 = make_shared<Quad>(L"map1-1.jpg");
	//backgrund2 = make_shared<Quad>(L"map1-2.png");
}

void Map1::Setting()
{
	backgrund1->GetTransForm()->SetPos(Vector2(CenterX, CenterY));
	//backgrund2->GetTransForm()->SetPos(Vector2(CenterX, CenterY));

	backgrund1->GetTransForm()->GetScale() *= 0.35f;
	//backgrund2->GetTransForm()->GetScale() *= 0.35f;
}
