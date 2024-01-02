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
	void FreeMode();	// ī�޶� �����й��ϰ�
	void FollowMode();  // ĳ���͸� ����ٴϰ�

	void Shake();	// �����

private:
	static Camera* _instance;

	shared_ptr<Transform> _transform;		// ī�޶��� SRT(setWolrdBuffer)

	float _speed = 200.0f;

	shared_ptr<Transform> _target;			// ������ ����ٴϰ� �Ұ��ΰ�(collider -> SetParent)
	Vector2 _offset = { CenterX, CenterY };				// ī�޶��� ���� ��ġ

	// ȭ���� �Ѱܰ��� ������ ī�޶� �ű������ �񱳰�
	Vector2 _leftBottom = {0,0};
	Vector2 _rightTop = {0,0};

	// -----shake----
	float _duration = 1.0f; // ������ ���ӵǴ� �ð�
	float _reduceDamping = 1.0f; // ���� ���̱�
	float _magnitude = 0.0f; // ���� �Ը�

	Vector2 _originPos = {0,0};

	shared_ptr<MatrixBuffer> _viewBuffer;
	shared_ptr<MatrixBuffer> _projectionBuffer;
};

