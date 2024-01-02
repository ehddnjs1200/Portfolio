#include "framework.h"
#include "Vector2.h"

Vector2::Vector2()
: Float2()
{
}

Vector2::Vector2(float x, float y)
: XMFLOAT2(x,y)
{
}

Vector2::~Vector2()
{
}

Vector2 Vector2::operator+(const Vector2& value) const
{
	/*Vector2 result;
	result.x = this->x + value.x;
	result.y = this->y + value.y;
	return result;*/

	return Vector2(this->x + value.x, this->y + value.y);
}

Vector2& Vector2::operator+=(const Vector2& value)
{
	//Vector2 result;
	//result.x = this->x + value.x;
	//result.y = this->y + value.y;
	//return result;

	this->x = this->x + value.x;
	this->y = this->y + value.y;

	return *this;
}

Vector2 Vector2::operator-(const Vector2& value) const
{
	return Vector2(this->x - value.x, this->y - value.y);
}

Vector2 Vector2::operator*(const Vector2& value) const
{
	return Vector2(this->x * value.x, this->y * value.y);
}

Vector2 Vector2::operator/(const Vector2& value) const
{
	return Vector2(this->x / value.x, this->y / value.y);
}

Vector2 Vector2::operator*(const float& value) const
{
	return Vector2(this->x * value, this->y * value);
}

Vector2& Vector2::operator*=(const float& value)
{
	this->x *= value;
	this->y *= value;

	return *this;
}

bool Vector2::operator!=(const Vector2 value) const
{
	return (x != value.x) && (y != value.y);
}

float Vector2::Length() const
{
	// ������, �����ϳ��� ���̸� �Ǽ��� ���Ѵ�.
	return sqrt(x * x + y* y);
}

float Vector2::Length(Vector2 value) const
{
	float tempX = value.x - x;
	float tempY = value.y - y;

	return sqrt(tempX * tempX + tempY * tempY);
	//return sqrtf(tempX * tempX + tempY * tempY); // �������� �Ǽ�
}

float Vector2::Angle() const
{
	// tan -> atan(arc)
	// atan, atan2 ���������� ��Ÿ���� ���ϴ� �Լ�
	// atan : -90~90�� ����(����)������ ��ȯ
	// atan2 : -180~180�� ����(����)������ ��ȯ

	return atan2(y,x);
}

float Vector2::Angle(const Vector2& value) const
{
	// ������ ���ذ����� ���콺�� ������ ���ϱ�
	// �������� anlge�� ���콺�� angle�� �����Ͽ� ������ ����(���콺�� �󸶸�ŭ �̵��ߴ����� �˱�����)
	float mouseDot = this->Dot(value);

	// cos������ ���ϰ�
	float cos = mouseDot / (this->Length() * value.Length());

	// �������Ѵ�.
	return acos(cos);
}

void Vector2::Normalize()
{
	float length = this->Length();
	x = x / length;
	y = y / length;
}

float Vector2::Dot(const Vector2& value) const
{
	return x * value.x + y * value.y;
}

float Vector2::Cross(const Vector2& value) const
{
	return x * value.x - y * value.y;
}
