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
	// 제곱근, 벡터하나의 길이를 실수로 구한다.
	return sqrt(x * x + y* y);
}

float Vector2::Length(Vector2 value) const
{
	float tempX = value.x - x;
	float tempY = value.y - y;

	return sqrt(tempX * tempX + tempY * tempY);
	//return sqrtf(tempX * tempX + tempY * tempY); // 제곱근을 실수
}

float Vector2::Angle() const
{
	// tan -> atan(arc)
	// atan, atan2 두점사이의 세타값을 구하는 함수
	// atan : -90~90의 라디안(파이)값으로 반환
	// atan2 : -180~180의 라디안(파이)값으로 반환

	return atan2(y,x);
}

float Vector2::Angle(const Vector2& value) const
{
	// 내적을 통해가지고 마우스의 각도를 구하기
	// 지팡이의 anlge과 마우스의 angle을 내적하여 각도를 구함(마우스가 얼마만큼 이동했는지를 알기위해)
	float mouseDot = this->Dot(value);

	// cos각도를 구하고
	float cos = mouseDot / (this->Length() * value.Length());

	// 비율정한다.
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
