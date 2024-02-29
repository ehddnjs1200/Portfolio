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
	// assert : ������ϴµ� ���������� �� ���� �����
	// ���� : ����׸�忡���� Ȯ���� ����(�����ϰ� �ٷ� ���ĸ� Ȯ�ΰ���)

	// if(a ==0)
	//	???

	// if : �����̸� �׳� ����
	// assert : �����̸� ����/���
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
