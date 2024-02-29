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
	_ironclad->Update();
	_start->Update();
}

void StartScene::Render()
{
	_background->Render();
	_ironclad->Render();
}

void StartScene::PostRender()
{
	_start->PostRender();
}


void StartScene::init()
{
	_ironclad = make_shared<Ironclad>(3, 180, 5);
	_background = make_shared<Quad>(L"map1-1.jpg");
	_start = make_shared<Button>(L"StartB.png");
}

void StartScene::Setting()
{
	_background->GetTransForm()->SetPos(Vector2(CenterX, CenterY));
	_background->GetTransForm()->GetScale() *= 0.35f;

	_start->SetPosition(Vector2(CenterX, CenterY));
	_start->SetScale(Vector2(0.3f, 0.3f));

	_start->SetEvent(bind(&StartScene::NextScene, this));

	// bool endcontant = false
}

void StartScene::NextScene()
{
	SceneManager::GetInstace()->SetScene("Bettle");
}
