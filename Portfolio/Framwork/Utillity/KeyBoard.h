#pragma once

// 4 * 4  256byte
// 0~255
#define KEYMAX 255

class KeyBoard
{
private:
	enum
	{
		NONE,
		DOWN,	// 키보드를 누를떄 실행, 계속 누르고 있는 경우에 실행
		UP,		// 누른 키에서 손을 땔 경우 실행
		PRESS	// 키보드를 누를때 실행, 입력할수 있는 키보드를 눌렀을 때에만 반응
	};


	KeyBoard();
	~KeyBoard();

public:
	static void Create()
	{
		if(_instance == nullptr)
			_instance = new KeyBoard();
	}

	static void Delete()
	{
		if(_instance != nullptr)
			delete _instance;
	}

	static KeyBoard* GetInstance()
	{
		if(_instance != nullptr)
			return _instance;
	}

	void Update();

	bool KEYDOWN(int key) {return _mapState[key] == DOWN;}
	bool KEYUP(int key) {return _mapState[key] == UP;}
	bool KEYPRESS(int key) {return _mapState[key] == PRESS;}

private:
	static KeyBoard* _instance;

	byte _curState[KEYMAX] = {}; // 현재의 값
	byte _oldState[KEYMAX] = {}; // 과거의 값
	byte _mapState[KEYMAX] = {}; // 최종값
};

