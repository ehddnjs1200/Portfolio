#pragma once
class Action
{
public:
	struct Clip
	{
		Vector2 startPos;
		Vector2 size;
		shared_ptr<SRV> texture;

		Clip(Vector2 startPos, Vector2 size, shared_ptr<SRV> texture)
			: startPos(startPos), size(size), texture(texture)
		{}

		Clip(float x, float y , Vector2 size, shared_ptr<SRV> texture)
			: startPos(Vector2(x,y)), size(size), texture(texture)
		{}
	};

	enum Type
	{
		END,
		LOOP
	};

	Action(vector<Clip> clips, string name = "", Type type = LOOP, float speed = 0.1f);
	~Action();

	void Update();

	void Play();
	void Pause();
	void Stop();
	void Reset();

	bool IsPlay() {return _isPlay;}
	Clip GetCurClip() {return _clips[_curClipNum]; }
	Action::Type GetType() { return _type;}

	void SetEndEvent(CallBack event) {_event = event;}

private:
	vector<Clip> _clips;
	Type _type;
	float _speed;
	string _actionName;

	bool _isPlay;		// ���� �ִϸ��̼��� ������������
	UINT _curClipNum;	// ������ Ŭ����ȣ
	float _time;		// ���ǵ�� ��

	CallBack _event = nullptr;
};

