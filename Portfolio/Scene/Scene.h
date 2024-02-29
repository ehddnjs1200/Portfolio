#pragma once
class Scene
{
public:
	Scene() {}
	virtual ~Scene() {}

	virtual void Init() {}
	virtual void Setting() {}
	virtual void Update() abstract;
	virtual void Render() abstract;
	virtual void PostRender() {}
	virtual void SceneTest() {}
	virtual void Reset() {}

	int scene = 1;

};

