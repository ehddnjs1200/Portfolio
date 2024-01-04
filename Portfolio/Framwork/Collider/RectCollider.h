#pragma once
class RectCollider : public Collider
{
private:
	struct ObbDesc
	{
		Vector2	_position;		// 위치
		Vector2	_direction[2];	// X,Y 방향벡터(11,12/21,22)
		float	_length[2];		// X,Y의 길이
	};
	
public:
	//RectCollider();
	RectCollider(Vector2 size);
	RectCollider(const RectCollider& other)
		: _size(other._size) {
		_type = other._type;
		CreateVertices();
	}
	virtual ~RectCollider();

	virtual void Update() override;

	// Collider을(를) 통해 상속됨
	virtual bool IsCollision(Vector2 pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> circle, bool isObb = false) override;
	virtual bool IsCollision(shared_ptr<RectCollider> rect, bool isObb = false) override;

	ObbDesc GetObb();

	// GJK 알고리즘 - 도형이라고 하기 애매한것들
	// 분리축개념(SAT알고리즘 - Separating Axis Theorem) - 꼭짓점이 딱알맞을경우(도형이라고 말할수있는것)
	float SepareateAxis(Vector2 separate, Vector2 e1, Vector2 e2);

	bool AABB(shared_ptr<RectCollider> rect);
	bool AABB(shared_ptr<CircleCollider> circle);

	bool OBB(shared_ptr<RectCollider> rect);
	bool OBB(shared_ptr<CircleCollider> circle);

	// size * 1.0f
	float Left()	{ return GetWorldPos().x - GetWorldHalfX(); }
	float Right()	{ return GetWorldPos().x + GetWorldHalfX(); }
	float Bottom()	{ return GetWorldPos().y - GetWorldHalfY(); }
	float Top()		{ return GetWorldPos().y + GetWorldHalfY(); }

	float GetWorldHalfX() {return _size.x * GetWorldScale().x; }
	float GetWorldHalfY() {return _size.y * GetWorldScale().y; }

private:
	void CreateVertices();
	Vector2 _size;
};

