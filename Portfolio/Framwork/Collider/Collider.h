#pragma once

class RectCollider;
class CircleCollider;

class Collider
{
public:
	enum class ColType
	{
		NONE,
		CIRCLE,
		RECT
	};

	Collider();
	virtual ~Collider();

	virtual void Update();
	virtual void Render();

	// 충돌 세가지
	virtual bool IsCollision(Vector2 pos) abstract;
	virtual bool IsCollision(shared_ptr<CircleCollider> circle, bool isObb = false) abstract;
	virtual bool IsCollision(shared_ptr<RectCollider> rect, bool isObb = false) abstract;

	bool IsCollision(shared_ptr<Collider> collider, bool isObb = false);

	shared_ptr<Transform> GetTransForm() {return _transform;}
	//Vector2 GetCenter() {return _transform->GetPos();}
	Vector2 GetWorldPos() {return _transform->GetWorldPos(); }
	Vector2 GetWorldScale() {return _transform->GetWorldScale(); }
	Vector2& GetLocalPos() {return _transform->GetPos(); }

	void SetGreen() {_colorBuffer->SetColor(GREEN); }
	void SetRed() {_colorBuffer->SetColor(RED); }

	void SetParent(shared_ptr<Transform> trans) { _transform->SetParent(trans); }
	
// 내 자식 불러용도기떄문에
protected:
	virtual void CreateData(); // Rect, Circle
	vector<Vertex>				_vertices;
	ColType _type = ColType::NONE;

private:

	shared_ptr<VertexShader>	_vertexShader;
	shared_ptr<PixelShader>		_pixelShader;

	shared_ptr<VertexBuffer>	_vertexBuffer;
	shared_ptr<ColorBuffer>		_colorBuffer;

	shared_ptr<Transform>		_transform;


};

