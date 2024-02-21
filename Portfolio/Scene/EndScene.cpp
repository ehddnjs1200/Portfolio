#include "framework.h"
#include "EndScene.h"

EndScene::EndScene()
{
	init(scene);
	Setting();
}

EndScene::~EndScene()
{
}

void EndScene::Update()
{
	_background->Update();
	_End->Update();
}

void EndScene::Render()
{
	_background->Render();
}

void EndScene::PostRender()
{
	_End->PostRender();
}

void EndScene::init(int scene)
{
	_background = make_shared<Quad>(L"Black.png");

	if (scene == 1)
		_End = make_shared<Button>(L"EndB.png");

	if (scene == 2)
		_End = make_shared<Button>(L"DieB.png");
}

void EndScene::Setting()
{
	_background->GetTransForm()->SetPos(Vector2(CenterX, CenterY));
	_End->SetPosition(Vector2(CenterX, CenterY));
	_End->SetScale(Vector2(0.3f, 0.3f));

	_End->SetEvent(bind(&EndScene::NextScene, this));
}

void EndScene::NextScene()
{
	int a = 5;
	SceneManager::GetInstace()->SetScene("Start");
}