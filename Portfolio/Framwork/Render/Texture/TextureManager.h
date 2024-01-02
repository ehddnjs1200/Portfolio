#pragma once
class TextureManager
{
private:
	TextureManager();
	~TextureManager();

public:
	static void Create()
	{
		if(_instance == nullptr)
			_instance = new TextureManager();
	}
	static void Delete()
	{
		if(_instance != nullptr)
			delete _instance;
	}
	static TextureManager* GetInstance()
	{
		if(_instance !=	nullptr)
			return  _instance;
	}

	shared_ptr<SRV> Add(wstring file);

private:
	static TextureManager* _instance;

	map<wstring, shared_ptr<SRV>> _textureMapping;
};

