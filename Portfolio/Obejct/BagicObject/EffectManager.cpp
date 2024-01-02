#include "framework.h"
#include "EffectManager.h"

EffectManager* EffectManager::_instance = nullptr;

EffectManager::EffectManager()
{
}

EffectManager::~EffectManager()
{
}

void EffectManager::Add(wstring effctFile, Vector2 maxFrame, float speed, UINT poolCount)
{
	size_t t = effctFile.find(L"Effect/", 0); // ex) Resource/ 제거(9)
	string temp = WstringToString(effctFile.substr(t + 7, effctFile.length())); // ???.png
	temp = temp.substr(0, temp.size()-4); // .png를 자른다.

	if(_effectMap.count(temp) > 0)
		return;

	vector<shared_ptr<Effect>> e;
	e.reserve(poolCount);

	for(int i=0;i<poolCount;i++)
	{
		shared_ptr<Effect> effect = make_shared<Effect>(effctFile, maxFrame, speed);
		e.push_back(effect);
	}
	_effectMap[temp] = e;
}

void EffectManager::Play(string effect, Vector2 pos)
{
	if(_effectMap.count(effect) == 0)
		return;

	for(auto effect : _effectMap[effect])
	{
		if(effect->_isActive == false)
		{
			effect->Play(pos);
			return;
		}
	}
}

void EffectManager::Stop(string effect, Vector2 pos)
{
	if (_effectMap.count(effect) == 0)
		return;

	for (auto effect : _effectMap[effect])
	{
		if (effect->_isActive == false)
		{
			effect->Stop(pos);
			return;
		}
	}
}

void EffectManager::Update()
{
	for(auto effect : _effectMap)
	{
		for(auto effectS : effect.second)
		{
			effectS->Update();
		}
	}
}

void EffectManager::Render()
{
	for (auto effect : _effectMap)
	{
		for (auto effectS : effect.second)
		{
			effectS->Render();
		}
	}
}
