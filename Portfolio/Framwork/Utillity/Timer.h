#pragma once

// FPS�� ���Ҷ� ���
// Frame Per Second
// �ʴ� ������
// ������ �ٸ� ��ǻ���ϰ�� Update�� Ƚ���� �ٸ��⶧���� ���� �ð��̿��� �����̴� ���� �ٸ����ֱ� ������
// ��ǻ���� ���ļ��� ���� ����� ��հ��� ���� �����̴� ���� ������ ������ �ٸ� ��ǻ�Ϳ��� �����ϰ� �����ϼ� �ְ� ����

// 0.000?�� ���ϰ� ���ϸ�
// 10 * Timer(1��������)

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

	double _timeScale;		// ������ũ��
	double _timeElased;		// �� �� �����Ӹ�ŭ ����� �ð�

	// long long
	__int64 _curTime;		// ����ð�
	__int64 _lastTime;		// ������ �ð�
	__int64 _periodFrequyency;	// ���ļ�

	int _frameRate;		// ������ �ӵ�
	int _frameCount;	// ������ ��

	double _oneSecCount;	// 1�ʸ��� �����ؾߵǴ� �ð�
	double _runTime;		// �ӵ�

	double _lockFPS;		// ���� FPS
};

