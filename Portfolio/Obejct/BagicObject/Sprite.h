#pragma once
class Sprite : public Quad
{
public:
	Sprite(wstring file, Vector2 maxFrame = Vector2{1,1});
	virtual ~Sprite();

	virtual void Update() override;
	virtual void Render() override;

	void SetClipToAction(Action::Clip clip);
	Vector2 GetHalfFrameSize();


protected:
	virtual void CreateVertices() override;

private:
	void CreateShader();
	void CreateBuffer();

private:
	Vector2 _maxFrame;
	shared_ptr<FrameBuffer> _frameBuffer;
	shared_ptr<ActionBuffer> _actionBuffer;
};

