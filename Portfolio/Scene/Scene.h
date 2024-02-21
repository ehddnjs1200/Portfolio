#pragma once
class Scene
{
public:
	Scene() {}
	virtual ~Scene() {}

	virtual void Init() {}
	virtual void Update() abstract;
	virtual void Render() abstract;
	virtual void PostRender() {}

	int scene = 1;
};

