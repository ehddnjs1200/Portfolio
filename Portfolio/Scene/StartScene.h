#pragma once
class StartScene : public Scene
{
public:
	StartScene();
	virtual ~StartScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void init();
	void Setting();

	void NextScene();

private:
	shared_ptr<Quad> _background;
	shared_ptr<Button> _start;
	shared_ptr<Ironclad> _ironclad;
};

