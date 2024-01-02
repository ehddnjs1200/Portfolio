#pragma once
// AABB / OBB
// Axis Aligned Bounding Box
// ���ĵ� �ڽ����� �浹
// Oriented Bounding Box
// ȸ���� �ڽ����� �浹


class ColliderScene : public Scene
{
public:
	ColliderScene();
	virtual ~ColliderScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

	void Liner_Interpolation(); // ��������

private:
	shared_ptr<Collider> _rect;
	shared_ptr<Collider> _mouse;

	shared_ptr<Collider> _circle;
};

