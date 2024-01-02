#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector2 size)
  : _size(size)
{
	_type = ColType::RECT;
	CreateVertices();
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
	Collider::Update();
}

bool RectCollider::IsCollision(Vector2 pos)
{
	if(pos.x > Left() && pos.x < Right() && pos.y < Top() && pos.y > Bottom())
		return true;

	return false;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> circle, bool isObb)
{
	if(isObb)
		return OBB(circle);
	else
		return AABB(circle);
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> rect, bool isObb)
{
	if(isObb)
		return OBB(rect);
	else
		return AABB(rect);
}

RectCollider::ObbDesc RectCollider::GetObb()
{
	ObbDesc obbDesc;

	obbDesc._position = GetWorldPos();

	XMFLOAT4X4 world;
	XMStoreFloat4x4(&world, GetTransForm()->GetSRT());
	obbDesc._direction[0] = {world._11, world._12}; // X의 방향벡터
	obbDesc._direction[1] = {world._21, world._22}; // Y의 방향벡터
	obbDesc._direction[0].Normalize();
	obbDesc._direction[1].Normalize();

	obbDesc._length[0] = GetWorldHalfX();
	obbDesc._length[1] = GetWorldHalfY();

	return obbDesc;
}

float RectCollider::SepareateAxis(Vector2 separate, Vector2 e1, Vector2 e2)
{
	// 두벡터간의 새로운 벡터를만든다? -> 외적
	// e1 = X방향벡터
	// e2 = Y방향벡터

	float r1 = abs(separate.Dot(e1));
	float r2 = abs(separate.Dot(e2));

	return r1 + r2;
}

bool RectCollider::AABB(shared_ptr<RectCollider> rect)
{
	if (this->Left() <= rect->Right() &&
		this->Right() >= rect->Left() &&
		this->Top() >= rect->Bottom() &&
		this->Bottom() <= rect->Top()
		)
		return true;

	return false;
}

bool RectCollider::AABB(shared_ptr<CircleCollider> circle)
{
	// 사각형의 4방향을 전부 체킹
	if (circle->GetWorldPos().x > Left() && circle->GetWorldPos().x < Right() ||
		circle->GetWorldPos().y > Bottom() && circle->GetWorldPos().y < Top())
	{
		// 원의 반지름 만큼 사각형을 키운다음 사각형에 딱붙어있는지 확인
		if (circle->GetWorldPos().x > Left() - circle->GetRadius() &&
			circle->GetWorldPos().x < Right() + circle->GetRadius() &&
			circle->GetWorldPos().y > Bottom() - circle->GetRadius() &&
			circle->GetWorldPos().y < Top() + circle->GetRadius())

			return true;
	}

	// 모서리 체킹
	// 1.
	//Vector2 edges[4];
	//// x , y 
	//// x(L,R), y(B,T)
	//edges[0] = Vector2{Left(), Top()};
	//edges[1] = Vector2{Left(), Bottom()};
	//edges[2] = Vector2{Right(), Top()};
	//edges[3] = Vector2{Right(), Bottom()};

	//for(auto edge : edges)
	//	if(circle->IsCollision(edge))
	//		return true;

	// 2.
	if (circle->IsCollision(Vector2(Left(), Top())))
		return true;
	if (circle->IsCollision(Vector2(Left(), Bottom())))
		return true;
	if (circle->IsCollision(Vector2(Right(), Top())))
		return true;
	if (circle->IsCollision(Vector2(Right(), Bottom())))
		return true;

	return false;
}

bool RectCollider::OBB(shared_ptr<RectCollider> rect)
{
	ObbDesc obbA = GetObb();
	ObbDesc obbB = rect->GetObb();

	// obbA(가만히있는 사각형) 가로와 세로의 단위 벡터
	Vector2 obbA_X		= obbA._direction[0];		// X방향벡터
	Vector2 obbA_X_L	= obbA_X * obbA._length[0];	// X방향벡터 * X의 길이
	Vector2 obbA_Y		= obbA._direction[1];		// Y방향벡터
	Vector2 obbA_Y_L	= obbA_Y * obbA._length[1]; // Y방향벡터 * Y의 길이

	// obbB(마우스에 붙인 사각형) 가로와 세로의 단위 벡터
	Vector2 obbB_X		= obbB._direction[0];
	Vector2 obbB_X_L	= obbB_X * obbB._length[0];
	Vector2 obbB_Y		= obbB._direction[1];
	Vector2 obbB_Y_L	= obbB_Y * obbB._length[1];

	// obbA의 중점과 obbB의 중점사이의 벡터
	Vector2 distance = obbA._position - obbB._position;

	// obbA의 가로 세로
	float lenghtA = obbA_X_L.Length(); // obbA_X의 길이
	float lenghtB = SepareateAxis(obbA_X, obbB_X_L, obbB_Y_L);
	float lenght = abs(distance.Dot(obbA_X)); // 직교화
	if(lenght > lenghtA + lenghtB)
		return false;

	lenghtA = obbA_Y_L.Length();
	lenghtB = SepareateAxis(obbA_Y, obbB_X_L, obbB_Y_L);
	lenght = abs(distance.Dot(obbA_Y));
	if(lenght > lenghtA + lenghtB)
		return false;

	// obbB 가로 세로
	lenghtA = obbB_X_L.Length();
	lenghtB = SepareateAxis(obbB_X, obbA_X_L, obbA_Y_L);
	lenght = abs(distance.Dot(obbB_Y));
	if (lenght > lenghtA + lenghtB)
		return false;

	lenghtA = obbB_Y_L.Length();
	lenghtB = SepareateAxis(obbB_Y, obbA_X_L, obbA_Y_L);
	lenght = abs(distance.Dot(obbB_Y));
	if (lenght > lenghtA + lenghtB)
		return false;

	return true;
}

bool RectCollider::OBB(shared_ptr<CircleCollider> circle)
{
	ObbDesc obbA = GetObb();

	// 사각형의 가로세로 단위벡터
	Vector2 obbA_X = obbA._direction[0];
	Vector2 obbA_X_L = obbA_X * obbA._length[0];
	Vector2 obbA_Y = obbA._direction[1];
	Vector2 obbA_Y_L = obbA_Y * obbA._length[1];

	// 원투영
	Vector2 circlePos = circle->GetWorldPos();
	Vector2 distance = circlePos - obbA._position;

	// 대각선
	float diagonal = sqrt(obbA._length[0] * obbA._length[0] + obbA._length[1] * obbA._length[1]);
	if(distance.Length() > circle->GetRadius() + diagonal)
		return false;

	// 사각형이 회전했을 경우 원과 출동을 체킹
	// X 랑 원
	float lenghtA = obbA_X_L.Length();
	float lenghtB = circle->GetRadius();
	float lenght = abs(distance.Dot(obbA_X));
	if(lenght > lenghtA + lenghtB)
		return false;

	lenghtA = obbA_Y_L.Length();
	lenghtB = circle->GetRadius();
	lenght = abs(distance.Dot(obbA_Y));
	if(lenght > lenghtA + lenghtB)
		return false;

	return true;
}

void RectCollider::CreateVertices()
{
	//Vector2 halfSize = _size;
	//halfSize.x = _size.x * 0.5f;
	//halfSize.y = _size.y * 0.5f;
	_vertices.reserve(5);

	_vertices.emplace_back(-_size.x, -_size.y);	// 왼쪽아래
	_vertices.emplace_back(_size.x, -_size.y);		// 오른쪽 아래
	_vertices.emplace_back(_size.x, _size.y);		// 오른쪽 위
	_vertices.emplace_back(-_size.x, _size.y);		// 왼쪽 위
	_vertices.emplace_back(-_size.x, -_size.y);	// 왼쪽 아래

	Collider::CreateData();
}