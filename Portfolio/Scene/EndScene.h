#pragma once
class EndScene : public Scene
{
public:
	EndScene();
	virtual ~EndScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void init(int scene);
	void Setting();

	void NextScene();

private:
	shared_ptr<Quad> _background;
	shared_ptr<Button> _End;
};


