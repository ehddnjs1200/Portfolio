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
	// 1�ʵ��� cpu�� �������� ��ȯ�ϴ� �Լ�(���ĸ����� ������ ������)
	// time.h -> clock() : �ð��� ���ϱ������� �����ϰ� ����������(�ʴ� 1,000���� ������ ���� 1ms�� �ð��� �����Ҽ�����)
	// winodw.h -> QueryPerformanceFrequency() : �ʴ� 10,000,000���� ������ ���� 0.1us(����ũ�μ�����)�� �ð����� �����Ҽ�����
	// __int64 == long long == reinterpret_cast<LARGE_INTEGER*>
	QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequyency);

	// ������ ������ ���ϱ�
	// Ÿ�̸��� CPU�� �������� ��� �Լ�
	QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime); // 0 

	// 0.0 ~ 1.0
	_timeScale = 1.0f / (double)_periodFrequyency;
}

Timer::~Timer()
{
}

void Timer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime); // ���� ������

	if(_lockFPS != 0)
	{
		// �������ӵ��� ����� �ð� < 1�ʴ� ����ϱ����� ���� FPS
		while(_timeElased < (1.0f / _lockFPS))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			// �������Ӹ�ŭ ����� �ð�
			_timeElased = (_curTime - _lastTime) * _timeScale;
		}
	}
	else
	{
		_timeElased = (_curTime - _lastTime) * _timeScale;
	}

	_lastTime = _curTime;

	_frameCount++;
	// 1�ʸ��� �����ؾ��ϴ� �ð� + �� �������Ӹ�ŭ ����Ƚð�
	_oneSecCount += _timeElased;

	// 1�ʸ��� �󸶳� ������Ʈ�� �Ǿ�����
	if(_oneSecCount >= 1)
	{
		// ������ �ӵ� = ������ ��
		_frameRate = _frameCount;
		_frameCount = 0;
		_oneSecCount = 0;
	}

	// �ӵ� + �� �������Ӹ�ŭ ����� �ð�
	_runTime += _timeElased;
}
