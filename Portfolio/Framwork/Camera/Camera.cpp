#include "framework.h"
#include "Camera.h"

Camera* Camera::_instance = nullptr;

Camera::Camera()
{
	_transform = make_shared<Transform>();
	_viewBuffer = make_shared<MatrixBuffer>();
	_projectionBuffer = make_shared<MatrixBuffer>();
}

Camera::~Camera()
{
}

void Camera::Update()
{
	if(_target == nullptr)
		FreeMode();
	else
		FollowMode();

	Shake();

	// world 0 view 1
	// quad-> setworlbuffer()있을경우에는 0외에 써야하고
	// Quad가 없을때는 0써도됨
	_transform->SetWorldBuffer(1);

	_transform->Update();
}

void Camera::PostRender()
{
	ImGui::Text("CameraInfo");
	ImGui::Text("CamX : %.1f, CamY : %.1f", mousepos.x, _transform->GetPos().y);
}

void Camera::SetViewPort(UINT width, UINT height)
{
	D3D11_VIEWPORT vp;
	vp.Width = width;
	vp.Height = height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;

	DEVICE_CONTEXT->RSSetViewports(1, &vp);
}

void Camera::SetProjectionBuffer(UINT width, UINT height)
{
	XMMATRIX projection = XMMatrixOrthographicOffCenterLH(WIN_STARTX, width, WIN_STARTY, height, -1.0f, 1.0f);
	_projectionBuffer->Set(projection);
	_projectionBuffer->SetVsBuffer(2);
}

void Camera::StartShake(float magnitude, float duration, float reduceDamping)
{
	_duration = duration;
	_reduceDamping = reduceDamping;
	_magnitude = magnitude;

	//_originPos = _transform->GetPos();
}

void Camera::FreeMode()
{
	if (KeyPress(VK_RBUTTON))
	{
		if (KeyPress('W'))
			_transform->GetPos().y -= _speed * DELTATIME;
		if (KeyPress('S'))
			_transform->GetPos().y += _speed * DELTATIME;
		if (KeyPress('A'))
			_transform->GetPos().x += _speed * DELTATIME;
		if (KeyPress('D'))
			_transform->GetPos().x -= _speed * DELTATIME;
	}
}

void Camera::FollowMode()
{
	Vector2 targetPos = _target->GetPos() - _offset;

	// 카메라의 위치와 화면의 끝을 비교하며 카메라의 위치를 바꿔줌
	if(targetPos.x < _leftBottom.x)
		targetPos.x = _leftBottom.x;
	if(targetPos.x > _rightTop.x - WIN_WIDTH)
		targetPos.x = _rightTop.x - WIN_WIDTH;
	if(targetPos.y < _leftBottom.y)
		targetPos.y = _leftBottom.y;
	if(targetPos.y > _rightTop.y - WIN_HEIGHT)
		targetPos.y = _rightTop.y -WIN_HEIGHT;

	// 선형보간(LERP)
	_transform->GetPos() = LERP(_transform->GetPos(), targetPos * -1, DELTATIME * _speed);
}

void Camera::Shake()
{
	if(_duration <= 0.0f)
		return;

	_duration -= DELTATIME;
	_magnitude -= DELTATIME * _reduceDamping;

	if (_magnitude < 0.0f)
	{
		_magnitude = 0.0f;
		_duration = 0.0f;
		return;
	}


	float minT = -_magnitude * ((float)rand() / (float)RAND_MAX);
	float maxT = +_magnitude * ((float)rand() / (float)RAND_MAX);

	
	_transform->GetPos() += Vector2(minT, maxT);
	//_transform->GetPos() = _originPos + Vector2(minT, maxT);

	//if(_duration <= 0.0f)
	//	_transform->GetPos() = _originPos;

}
