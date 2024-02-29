#pragma once
class SceneManager
{
private:
	SceneManager();
	~SceneManager();

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new SceneManager();
	}
	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}
	static SceneManager* GetInstace()
	{
		if (_instance != nullptr)
			return _instance;
	}

	void Update();
	void Render();
	void PostRender();

	void SetScene(string name);

	void NextBettle();


private:
	static SceneManager* _instance;
	unordered_map<string, shared_ptr<Scene>> _sceneTable;
	weak_ptr<Scene> _curScene;
};

