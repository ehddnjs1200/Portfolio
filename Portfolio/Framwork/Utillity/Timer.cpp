#include "framework.h"
#include "Timer.h"

Timer* Timer::_instance = nullptr;

Timer::Timer()
: _timeScale(double())
, _timeElased(double())
, _curTime(long long())
, _lastTime(long long())
, _periodFrequyency(__int64())
, _frameRate(int())
, _frameCount(int())
, _oneSecCount(double())
, _runTime(double())
, _lockFPS(double())
{
	// 1초동안 cpu의 진동수를 반환하는 함수(주파를수를 변수에 저장함)
	// time.h -> clock() : 시간을 구하긴하지만 정밀하게 나오진않음(초당 1,000번의 측정을 통해 1ms의 시간을 측정할수있음)
	// winodw.h -> QueryPerformanceFrequency() : 초당 10,000,000번의 측정을 통해 0.1us(마이크로세컨드)의 시간까지 측정할수있음
	// __int64 == long long == reinterpret_cast<LARGE_INTEGER*>
	QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequyency);

	// 마지막 진동수 구하기
	// 타이머의 CPU의 진동수를 얻는 함수
	QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime); // 0 

	// 0.0 ~ 1.0
	_timeScale = 1.0f / (double)_periodFrequyency;
}

Timer::~Timer()
{
}

void Timer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime); // 현재 진동수

	if(_lockFPS != 0)
	{
		// 한프레임동안 경과된 시간 < 1초당 계산하기위한 고정 FPS
		while(_timeElased < (1.0f / _lockFPS))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			// 한프레임만큼 경과된 시간
			_timeElased = (_curTime - _lastTime) * _timeScale;
		}
	}
	else
	{
		_timeElased = (_curTime - _lastTime) * _timeScale;
	}

	_lastTime = _curTime;

	_frameCount++;
	// 1초마다 갱신해야하는 시간 + 딱 한프레임만큼 경과된시간
	_oneSecCount += _timeElased;

	// 1초마다 얼마나 업데이트가 되었는지
	if(_oneSecCount >= 1)
	{
		// 프레임 속도 = 프레임 수
		_frameRate = _frameCount;
		_frameCount = 0;
		_oneSecCount = 0;
	}

	// 속도 + 딱 한프레임만큼 경과된 시간
	_runTime += _timeElased;
}
