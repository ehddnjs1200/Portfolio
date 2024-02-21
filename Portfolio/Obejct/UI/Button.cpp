#include "framework.h"
#include "Button.h"

Button::Button(wstring file)
{
	_quad = make_shared<Quad>(file, L"WVPVertexShader", L"ButtonPS");
	_col = make_shared<RectCollider>(_quad->GetTextureSize());
	_col->SetParent(_quad->GetTransForm());

	_buttonBuffer = make_shared<ButtonBuffer>();
	_buttonBuffer->data.state = 0;
	_buttonBuffer->data.hovered = 0.3f;
	_buttonBuffer->data.clicked = 0.5f;

}

Button::~Button()
{
}

void Button::Update()
{
	SetState();
	_quad->Update();
	_col->Update();
}

void Button::PostRender()
{
	{
		float offSetX = _quad->GetTextureSize().x * 0.5f;
		float offSetY = _quad->GetTextureSize().y * 0.5f;
		float sizeX = _quad->GetTextureSize().x;
		float sizeY = _quad->GetTextureSize().y;

		float left = sizeX + offSetX;
		float right = sizeX + offSetX;
		float top = sizeY + offSetY;
		float bottom = sizeY + offSetY;
		RECT rect = { left, top, right, bottom };
	}

	_buttonBuffer->SetPsBuffer(0);
	_quad->Render();
	_col->Render();

	ImGui::SliderFloat("HoverColor", &_buttonBuffer->data.hovered, 0.0f, 1.0f);
	ImGui::SliderFloat("ClickColor", &_buttonBuffer->data.clicked, 0.0f, 1.0f);
}

void Button::SetPosition(Vector2 pos)
{
	_quad->GetTransForm()->GetPos() = pos;
}

void Button::SetScale(Vector2 scale)
{
	_quad->GetTransForm()->GetScale() = scale;
}


void Button::SetState()
{
	if (_col->IsCollision(mousepos))
	{
		_state = HOVER;
		if (KeyPress(VK_LBUTTON))
			_state = CLICK;

		if (KeyUp(VK_LBUTTON))
		{
			if (_callback != nullptr)
				_callback();
		}
	}
	else
		_state = NONE;

	switch (_state)
	{
	case Button::NONE:
		_buttonBuffer->data.state = 0;
		break;
	case Button::HOVER:
		_buttonBuffer->data.state = 1;
		break;
	case Button::CLICK:
		_buttonBuffer->data.state = 2;
		break;
	default:
		break;
	}
}