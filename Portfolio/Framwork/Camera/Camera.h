#pragma once
class Camera
{
private:
	Camera();
	~Camera();

public:
	static void Create()
	{
		if(_instance == nullptr)
			_instance = new Camera();
	}

	static void Delete()
	{
		if(_instance != nullptr)
			delete _instance;
	}

	static Camera* GetInstance()
	{
		if(_instance != nullptr)
			return _instance;
	}

	void Update();
	void PostRender(); // imgui

	void SetViewPort(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);
	void SetViewBuffer() {_viewBuffer->SetVsBuffer(1); }
	void SetProjectionBuffer(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);

	void SetTarget(shared_ptr<Transform> transform) {_target = transform;}
	void SetLeftBottom(Vector2 value) {_leftBottom = value; }
	void SetRightTop(Vector2 value) {_rightTop = value;}

	void StartShake(float magnitude, float duration = 1.0f, float reduceDamping = 1.0f);

private:
	void FreeMode();	// 카메라가 자유분방하게
	void FollowMode();  // 캐릭터를 따라다니게

	void Shake();	// 흔딜림

private:
	static Camera* _instance;

	shared_ptr<Transform> _transform;		// 카메라의 SRT(setWolrdBuffer)

	float _speed = 200.0f;

	shared_ptr<Transform> _target;			// 누구를 따라다니게 할것인가(collider -> SetParent)
	Vector2 _offset = { CenterX, CenterY };				// 카메라의 현재 위치

	// 화면을 넘겨갈때 언제쯤 카메라를 옮기기위한 비교값
	Vector2 _leftBottom = {0,0};
	Vector2 _rightTop = {0,0};

	// -----shake----
	float _duration = 1.0f; // 진동이 지속되는 시간
	float _reduceDamping = 1.0f; // 진동 줄이기
	float _magnitude = 0.0f; // 진동 규모

	Vector2 _originPos = {0,0};

	shared_ptr<MatrixBuffer> _viewBuffer;
	shared_ptr<MatrixBuffer> _projectionBuffer;
};

