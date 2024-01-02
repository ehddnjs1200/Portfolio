#pragma once
class CircleCollider : public Collider
{
public:
	CircleCollider(float radius);
	virtual ~CircleCollider();

	virtual bool IsCollision(Vector2 pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> circle, bool isObb = false) override;
	virtual bool IsCollision(shared_ptr<RectCollider> rect, bool isObb = false) override;

	float GetRadius() {return _radius * GetWorldScale().x;}

private:
	void CreateVertices();
	float _radius;
};

