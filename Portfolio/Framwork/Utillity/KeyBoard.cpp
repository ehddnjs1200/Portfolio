#include "framework.h"
#include "KeyBoard.h"

KeyBoard* KeyBoard::_instance = nullptr;

KeyBoard::KeyBoard()
{
}

KeyBoard::~KeyBoard()
{
}

void KeyBoard::Update()
{
	// memory copy
	// cur�� �޸𸮰��� old�� �޸𸮿� ����
	memcpy(_oldState, _curState, sizeof(_oldState));

	// ������ ������ ����
	// 256(KEYMAX)�� ����Ű ���¸� ������ ���ۿ� ����
	GetKeyboardState(_curState);

	for(int i =0; i < KEYMAX; i++)
	{
		// GeyAsyncKeyState(vk_code) & 0x8000
		// 0(0x0000) : ������ �������� ����, ȣ������� �ȴ��� ����
		// 0x8000	 : ������ �������� ����, ȣ������� ���� ����
		// 0x8001	 : ������ �������� �ְ�, ȣ������� ���� ����
		// 1(0x1000) : ������ �������� �ְ�, ȣ������� �ȴ��� ����
		byte key = _curState[i] & 0x80;
		
		// Ű�ǰ��� �����ϸ� 1, ������ 0�� ��ȯ
		_curState[i] = key ? 1 : 0;

		// cur�� old ������ 1 ������ 0 �� ����
		int cur = _curState[i];
		int old = _oldState[i];

		// ������ �������� ����, ���� ������ ���
		if(cur == 1 && old == 0)
			_mapState[i] = DOWN;
		// ������ �������� �ְ�, ���� �ȴ����� ���
		if(cur == 0 && old == 1)
			_mapState[i] = UP;
		// ������ �������� �ְ�, ������ ������ ���
		if(cur == 1 && old == 1)
			_mapState[i] = PRESS;
		// ������ �������� ����, ������ �ȴ����� ���
		if(cur == 0 && old == 0)
			_mapState[i] = NONE;
	}
}
