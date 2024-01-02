#include "framework.h"
#include "Effect.h"

Effect::Effect(wstring file, Vector2 maxFrame, float speed)
 : _maxFrame(maxFrame)
{
	_sprite = make_shared<Sprite>(file, _maxFrame);
	CreateAction(file, speed);
	_action->SetEndEvent(bind(&Effect::End, this));
}

Effect::~Effect()
{
}

void Effect::Update()
{
	if(!_isActive)
		return;

	_sprite->Update();
	_action->Update();
	_sprite->SetClipToAction(_action->GetCurClip());
}

void Effect::Render()
{
	if (!_isActive)
		return;

	_sprite->Render();
}

void Effect::CreateAction(wstring file, float speed)
{
	vector<Action::Clip> clips;
	float w = _sprite->GetHalfFrameSize().x;
	float h = _sprite->GetHalfFrameSize().y;

	Vector2 size = {w,h};

	for(int y = 0; y < _maxFrame.y; y++)
	{
		for(int x = 0; x<_maxFrame.x; x++)
		{
			clips.emplace_back(x * w, y * h, size, TextureManager::GetInstance()->Add(file));
		}
	}
	// size_t == unsinged int
	size_t t = file.find(L"Effect/", 0); // ex) Resource/ 제거(9)
	string temp = WstringToString(file.substr(t + 7, file.length())); // ex) Effect/ 제거 -> file_8x2.png
	_action = make_shared<Action>(clips, temp.substr(0, temp.length() - 4), Action::END, speed);
	// ex) fire_8x2
}

void Effect::Play(Vector2 pos)
{
	_isActive = true;
	_sprite->GetTransForm()->GetPos() = pos;
	_action->Play();
}

void Effect::Stop(Vector2 pos)
{
	_isActive = false;
	_action->Stop();
}
