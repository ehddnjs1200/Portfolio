#pragma once
class Button
{
public:
	enum State
	{
		NONE,
		HOVER,
		CLICK
	};

	Button(wstring file);
	~Button();

	void Update();
	void PostRender();

	void SetPosition(Vector2 pos);
	void SetScale(Vector2 scale);
	void SetState();

	void SetEvent(CallBack callback) { _callback = callback; }

private:
	shared_ptr<Quad> _quad;
	shared_ptr<RectCollider> _col;

	State _state;

	shared_ptr<ButtonBuffer> _buttonBuffer;

	CallBack _callback;
};

