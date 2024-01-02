#pragma once
class FilterScene : public Scene
{
public:
	FilterScene();
	virtual ~FilterScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender();

private:
	shared_ptr<Quad> _background;
	shared_ptr<FilterBuffer> _fileterBuffer;
};

