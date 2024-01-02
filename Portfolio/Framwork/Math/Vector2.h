#pragma once
class Vector2 : public Float2
{
public:
	Vector2();
	Vector2(float x, float y);
	virtual ~Vector2();

	Vector2 operator+ (const Vector2& value) const; // a + b
	Vector2& operator+= (const Vector2& value); // a += b -> a = a + b
	Vector2 operator- (const Vector2& value) const;
	Vector2 operator* (const Vector2& value) const;
	Vector2 operator/ (const Vector2& value) const;

	Vector2 operator* (const float& value) const;
	Vector2& operator*= (const float& value);

	bool operator != (const Vector2 value) const;

	float Length() const;
	float Length(Vector2 value) const;
	float Angle() const;
	float Angle(const Vector2& value) const;

	// ����ȭ(������ ���� ���� ���͸� ��ȯ)
	void Normalize();

	// ����
	float Dot(const Vector2& value) const;

	// ����
	float Cross(const Vector2& value) const;


};

