#pragma once
class EffectManager
{
private:
	EffectManager();
	~EffectManager();

public:
	static void Create()
	{
		if(_instance == nullptr)
			_instance = new EffectManager();
	}

	static void Delete()
	{
		if(_instance)
			delete _instance;
	}

	static EffectManager* GetInstance()
	{
		if(_instance)
			return _instance;
	}

public:
	void Add(wstring effctFile, Vector2 maxFrame, float speed , UINT poolCount = 10);
	void Play(string effect, Vector2 pos);
	void Stop(string effect, Vector2 pos);
	
	void Update();
	void Render();

private:
	static EffectManager* _instance;
	unordered_map<string, vector<shared_ptr<Effect>>> _effectMap;
};

