#include "framework.h"
#include "StartScene.h"


StartScene::StartScene()
{
	init();
	Setting();
}

StartScene::~StartScene()
{
}

void StartScene::Update()
{
	_background->Update();
	_start->Update();
}

void StartScene::Render()
{
	_background->Render();
}

void StartScene::PostRender()
{
	_start->PostRender();
}


void StartScene::init()
{
	_background = make_shared<Quad>(L"Black.png");
	_start = make_shared<Button>(L"StartB.png");
}

void StartScene::Setting()
{
	_background->GetTransForm()->SetPos(Vector2(CenterX, CenterY));
	_start->SetPosition(Vector2(CenterX, CenterY));
	_start->SetScale(Vector2(0.3f, 0.3f));

	_start->SetEvent(bind(&StartScene::NextScene, this));
}

void StartScene::NextScene()
{
	int a = 5;
	SceneManager::GetInstace()->SetScene("Bettle");
}
