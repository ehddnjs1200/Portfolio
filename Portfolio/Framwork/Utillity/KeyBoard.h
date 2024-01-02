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
		DOWN,	// Ű���带 ������ ����, ��� ������ �ִ� ��쿡 ����
		UP,		// ���� Ű���� ���� �� ��� ����
		PRESS	// Ű���带 ������ ����, �Է��Ҽ� �ִ� Ű���带 ������ ������ ����
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

	byte _curState[KEYMAX] = {}; // ������ ��
	byte _oldState[KEYMAX] = {}; // ������ ��
	byte _mapState[KEYMAX] = {}; // ������
};

