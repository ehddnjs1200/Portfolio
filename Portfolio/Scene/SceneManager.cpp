#include "framework.h"
#include "SceneManager.h"

#include "Scene/StartScene.h"
#include "Scene/EndScene.h"
#include "Scene/CameraScene.h"

SceneManager* SceneManager::_instance = nullptr;

SceneManager::SceneManager()
{
	_sceneTable["Start"] = make_shared<StartScene>();
	_sceneTable["End"] = make_shared<EndScene>();
	_sceneTable["Bettle"] = make_shared<CameraScene>();

	_curScene = _sceneTable["Start"];
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update()
{
	// expired : nullptr
	// lock : Get
	if (!_curScene.expired())
		_curScene.lock()->Update();
}

void SceneManager::Render()
{
	// assert : 디버깅하는데 문제가있을 시 에러 검출용
	// 단점 : 디버그모드에서만 확인이 가능(빌드하고 바로 직후만 확인가능)

	// if(a ==0)
	//	???

	// if : 거짓이면 그냥 무시
	// assert : 거짓이면 에러/경고
	assert(!_curScene.expired());
	_curScene.lock()->Render();
}

void SceneManager::PostRender()
{
	assert(!_curScene.expired());
	_curScene.lock()->PostRender();
}

void SceneManager::SetScene(string name)
{
	if (_sceneTable.count(name) == 0)
		return;

	_curScene = _sceneTable[name];
	
	if (name == "Bettle")
	{
		_curScene.lock()->SceneTest();
	}

	//_curScene.lock()->Init();
	//_curScene.lock()->Setting();
}

void SceneManager::NextBettle()
{
	_sceneTable.erase("Bettle");
	_sceneTable["Bettle"] = make_shared<CameraScene>();
}
