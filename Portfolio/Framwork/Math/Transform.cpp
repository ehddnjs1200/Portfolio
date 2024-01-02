#include "framework.h"
#include "Transform.h"

Transform::Transform()
: _pos(Vector2())
, _scale({1.0f,1.0f})
, _angle(float())
{
	_worldBuffer = make_shared<MatrixBuffer>();
	_srt = XMMatrixIdentity(); // 단일행렬(항등행렬)
	_parent = nullptr;
}

Transform::~Transform()
{
}

void Transform::Update()
{
	XMMATRIX S = XMMatrixScaling(_scale.x, _scale.y, 1);
	XMMATRIX R = XMMatrixRotationZ(_angle);
	XMMATRIX T = XMMatrixTranslation(_pos.x, _pos.y, 0);

	_srt = S * R * T;

	if (_parent != nullptr)
		_srt *= _parent->GetSRT();

	_worldBuffer->Set(_srt);
	_worldBuffer->Update();
}

void Transform::SetWorldBuffer(int slot)
{
	_worldBuffer->SetVsBuffer(slot);
}
