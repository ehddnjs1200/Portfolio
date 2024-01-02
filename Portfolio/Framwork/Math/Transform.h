#pragma once

// SRT�� ���� ��ȯ����� ����
// worldBuffer ����
class Transform
{
public:
	Transform();
	~Transform();
	
	void Update();
	void SetWorldBuffer(int slot = 0);

	XMMATRIX GetSRT() {return _srt;}
	void SetParent(shared_ptr<Transform> parent)
	{
		_parent = parent;
	}

	void SetPos(Vector2 pos) { _pos = pos; }
	void SetScale(Vector2 scale) { _scale = scale; }
	void SetAngle(float angle) { _angle = angle; }

	float& GetAngle() { return _angle; }
	Vector2& GetPos() {return _pos;}
	Vector2& GetScale() {return _scale;}

	Vector2 GetWorldPos()
	{
	// 11 12 13 14
	// 21 22 23 24
	// 31 32 33 34
	// 41 42 43 44
	
	// 41(x), 42(y), 43(z), 44(a) =? Position
	// 11 22 33 44 => Scale
	// 11 12 13 => X����(translate)
	// 21 22 23 => Y����
	// 31 32 33 => Z����

	// pos / worldPos
	// Pos : ���� �������ִ� ��ǥ
	// WorldPos : Buffer�־ Update�Ұ�� ����

		XMFLOAT4X4 matrix;
		XMStoreFloat4x4(&matrix, _srt);
		return Vector2(matrix._41, matrix._42);
	}

	Vector2 GetWorldScale()
	{
		if(_parent)
			return Vector2(_scale.x * _parent->GetScale().x, _scale.y * _parent->GetScale().y);
		return _scale;
	}
public:
	Vector2	_pos;
	Vector2	_scale;
	float	_angle;

private:
	shared_ptr<MatrixBuffer>	_worldBuffer;
	XMMATRIX _srt;
	shared_ptr<Transform> _parent;
};

