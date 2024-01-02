#pragma once
// AABB / OBB
// Axis Aligned Bounding Box
// 정렬된 박스끼리 충돌
// Oriented Bounding Box
// 회전된 박스끼리 충돌


class ColliderScene : public Scene
{
public:
	ColliderScene();
	virtual ~ColliderScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

	void Liner_Interpolation(); // 선형보간

private:
	shared_ptr<Collider> _rect;
	shared_ptr<Collider> _mouse;

	shared_ptr<Collider> _circle;
};

