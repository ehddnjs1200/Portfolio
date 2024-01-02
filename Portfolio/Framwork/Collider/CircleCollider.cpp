#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(float radius)
	: _radius(radius)
{
	_type = ColType::CIRCLE;
	CreateVertices();
}

CircleCollider::~CircleCollider()
{
}

bool CircleCollider::IsCollision(Vector2 pos)
{
	float distance = GetTransForm()->_pos.Length(pos);

	return _radius >= distance;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> circle, bool isObb)
{
	float distance = GetWorldPos().Length(circle->GetWorldPos());

	return _radius + circle->_radius >= distance;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> rect, bool isObb)
{
	return rect->IsCollision(make_shared<CircleCollider>(*this), isObb);
}


void CircleCollider::CreateVertices()
{
// 라디안값 0 ~ 360 = 2파이
	_vertices.reserve(36);
	for(float i=0;i<37;i++) // 0~36 0 ~35
	{
	// 
		float x = cos(PI * (i/18)) * _radius;
		float y = sin(PI * (i/18)) * _radius;
		_vertices.emplace_back(x,y);
	}
	Collider::CreateData();
}