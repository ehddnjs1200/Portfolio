#pragma once

// FPS를 구할때 사용
// Frame Per Second
// 초당 프레임
// 성능이 다른 컴퓨터일경우 Update의 횟수가 다르기때문에 같은 시간이여도 움직이는 값이 다를수있기 때문에
// 컴퓨터의 주파수를 통해 공통된 평균값을 구해 움직이는 값에 더해줘 성능이 다른 컴퓨터여도 동일하게 움직일수 있게 해줌

// 0.000?씩 더하고 곱하면
// 10 * Timer(1초프레임)

class Timer
{
private:
	Timer();
	~Timer();

public:
	static void Create()
	{
		if(_instance == nullptr)
			_instance = new Timer();
	}

	static void Delete()
	{
		if(_instance !=nullptr)
			delete _instance;
	}

	static Timer* GetInstance()
	{
		if(_instance != nullptr)
			return _instance;
	}

	void Update();

	double GetElasedTime() {return _timeElased;}
	int GetFPS() {return _frameRate;}

private:
	static Timer* _instance;

	double _timeScale;		// 프레임크기
	double _timeElased;		// 딱 한 프레임만큼 경과된 시간

	// long long
	__int64 _curTime;		// 현재시간
	__int64 _lastTime;		// 마지막 시간
	__int64 _periodFrequyency;	// 주파수

	int _frameRate;		// 프레임 속도
	int _frameCount;	// 프레임 수

	double _oneSecCount;	// 1초마다 갱신해야되는 시간
	double _runTime;		// 속도

	double _lockFPS;		// 고정 FPS
};

