#include "framework.h"
#include "Action.h"

Action::Action(vector<Clip> clips, string name, Type type, float speed)
 : _clips(clips)
 , _type(type)
 , _speed(speed)
 , _actionName(name)
 , _isPlay(true)
 , _curClipNum(0)
 , _time(0.0f)
{
}

Action::~Action()
{
}

void Action::Update()
{
	if(!_isPlay)
		return;

	_time += DELTATIME;
	if(_time > _speed)
	{
		_time = 0.0f;

		switch (_type)
		{
		case Type::END:
		{
			_curClipNum++;
			if(_curClipNum >= _clips.size())
				Stop();
			break;
		}
		case Type::LOOP:
		{
			_curClipNum++;
			if(_curClipNum >= _clips.size())
				_curClipNum %= _clips.size();
			break;
		}
		default:
			break;
		}
	}
}

void Action::Play()
{
	_isPlay = true;
	_curClipNum = 0;
	_time = 0.0f;
}

void Action::Pause()
{
	_isPlay = false;
}

void Action::Stop()
{
	_isPlay = false;
	_curClipNum = 0;

	if(_event)
		_event(); // delete
}

void Action::Reset()
{
	_isPlay = false;
	_curClipNum = 0;
}
