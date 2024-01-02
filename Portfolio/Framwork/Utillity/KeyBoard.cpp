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
	// cur의 메모리값을 old의 메모리에 복사
	memcpy(_oldState, _curState, sizeof(_oldState));

	// 현제의 값으로 실행
	// 256(KEYMAX)개 가상키 상태를 지정된 버퍼에 복사
	GetKeyboardState(_curState);

	for(int i =0; i < KEYMAX; i++)
	{
		// GeyAsyncKeyState(vk_code) & 0x8000
		// 0(0x0000) : 이전에 누른적이 없고, 호출시점에 안눌린 상태
		// 0x8000	 : 이전에 누른적이 없고, 호출시점에 눌린 상태
		// 0x8001	 : 이전에 누른적이 있고, 호출시점에 눌린 상태
		// 1(0x1000) : 이전에 누른적이 있고, 호출시점에 안눌린 상태
		byte key = _curState[i] & 0x80;
		
		// 키의값이 존재하면 1, 없으면 0을 반환
		_curState[i] = key ? 1 : 0;

		// cur과 old 있으면 1 없으면 0 이 대입
		int cur = _curState[i];
		int old = _oldState[i];

		// 이전에 누른적이 없고, 현제 눌러진 경우
		if(cur == 1 && old == 0)
			_mapState[i] = DOWN;
		// 이전에 누른적이 있고, 현제 안눌러진 경우
		if(cur == 0 && old == 1)
			_mapState[i] = UP;
		// 이전에 누른적이 있고, 현제도 눌러진 경우
		if(cur == 1 && old == 1)
			_mapState[i] = PRESS;
		// 이전에 누른적이 없고, 현제도 안눌려진 경우
		if(cur == 0 && old == 0)
			_mapState[i] = NONE;
	}
}
