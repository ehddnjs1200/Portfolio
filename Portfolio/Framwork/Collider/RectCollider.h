#pragma once
class RectCollider : public Collider
{
private:
	struct ObbDesc
	{
		Vector2	_position;		// ��ġ
		Vector2	_direction[2];	// X,Y ���⺤��(11,12/21,22)
		float	_length[2];		// X,Y�� ����
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

	// Collider��(��) ���� ��ӵ�
	virtual bool IsCollision(Vector2 pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> circle, bool isObb = false) override;
	virtual bool IsCollision(shared_ptr<RectCollider> rect, bool isObb = false) override;

	ObbDesc GetObb();

	// GJK �˰��� - �����̶�� �ϱ� �ָ��Ѱ͵�
	// �и��ళ��(SAT�˰��� - Separating Axis Theorem) - �������� ���˸������(�����̶�� ���Ҽ��ִ°�)
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

