#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	// WorldPos = matrix(41,42,43)
	// ���忡�� ������Ʈ�� ���� ��ǥ��
	// (0,0,0) �������� ���� ��ǥ
	// LocalPos = pos
	// �������ġ, �θ������Ʈ�� ���� �ڽ� �������� ��ǥ��
	// �θ��� position�� �������� ���� ���� pos

	// ex) ���� ��ǥ �������� Rect(10,10), Circle(15,10)
	// Rect(�θ�), Circle(�ڽ�)
	// ���� ��ǥ�� Rect(10,10), Circle(5,0)

	_rect = make_shared<RectCollider>(Vector2(50.0f, 50.0f));
	//_rect->GetTransForm()->_pos = {CenterX, CenterY};
	_rect->GetLocalPos() = Vector2(CenterX, CenterY);
	//_rect->GetWorldPos() = Vector2(CenterX, CenterY);

	_mouse = make_shared<RectCollider>(Vector2(50.0f, 50.0f));
	//_mouse->GetTransForm()->_pos = mousepos;
	_mouse->GetLocalPos() = mousepos;

	_circle = make_shared<CircleCollider>(50.0f);
	//_circle->GetTransForm()->_pos = { CenterX + 100.0f, CenterY };
	_circle->GetLocalPos() = Vector2(CenterX + 100.0f, CenterY);
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	_mouse->GetTransForm()->_pos = mousepos;

	// ��������
	//Liner_Interpolation();

	if(KeyPress('Q'))
		_mouse->GetTransForm()->_angle -= 5.0f * DELTATIME;
	if(KeyPress('E'))
		_mouse->GetTransForm()->_angle += 5.0f * DELTATIME;

	if (KeyPress('A'))
		_mouse->GetTransForm()->_scale.x += 10.0f * DELTATIME;
	if (KeyPress('D'))
		_mouse->GetTransForm()->_scale.x -= 10.0f * DELTATIME;

	if(KeyPress('W'))
		_mouse->GetTransForm()->_scale.y += 10.0f * DELTATIME;
	if(KeyPress('S'))
		_mouse->GetTransForm()->_scale.y -= 10.0f * DELTATIME;

	bool isObb = true;

	if(_rect->IsCollision(_mouse, isObb))
		_rect->SetRed();
	else
		_rect->SetGreen();

	if(_circle->IsCollision(_mouse, isObb))
		_circle->SetRed();
	else
		_circle->SetGreen();

	//Vector2 a =	_rect->GetWorldPos();
	//Vector2 b =	_rect->GetWorldPos();

	_rect->Update();
	_mouse->Update();
	_circle->Update();

	//Vector2 c = _rect->GetWorldPos();
	//Vector2 d = _rect->GetWorldPos();

}

void ColliderScene::Render()
{
	_rect->Render();
	_mouse->Render();
	_circle->Render();
}

void ColliderScene::Liner_Interpolation()
{
	// 1. ��������
	//Vector2 moveVector = mousepos - _mouse->GetTransForm()->_pos;
	//moveVector.Normalize();
	//if(_mouse->GetTransForm()->_pos != mousepos)
	//	_mouse->GetTransForm()->_pos += moveVector * DELTATIME * 50.0f;

	// 2. LERP �Լ�(��������)	
	Vector2 moveVector = LERP(_mouse->GetTransForm()->_pos, mousepos, DELTATIME * 50.0f);
	_mouse->GetTransForm()->_pos = moveVector;
}
