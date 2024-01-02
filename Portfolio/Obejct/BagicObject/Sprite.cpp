#include "framework.h"
#include "Sprite.h"

Sprite::Sprite(wstring file, Vector2 maxFrame)
	: _maxFrame(maxFrame)
{
	_texture = TextureAdd(file);
	CreateShader();
	CreateBuffer();

	_transform = make_shared<Transform>();
}

Sprite::~Sprite()
{
}

void Sprite::Update()
{
	//_transform->Update();
	Quad::Update();
}

void Sprite::Render()
{
	_frameBuffer->SetPsBuffer(0);
	_actionBuffer->SetPsBuffer(0);

	Quad::Render();
}

void Sprite::SetClipToAction(Action::Clip clip)
{
	_actionBuffer->_data.size = clip.size;
	_actionBuffer->_data.startPos = clip.startPos;
}

Vector2 Sprite::GetHalfFrameSize()
{
	Vector2 temp;
	temp.x = _texture->GetSize().x / _maxFrame.x;
	temp.y = _texture->GetSize().y / _maxFrame.y;

	return temp;
}

void Sprite::CreateVertices()
{
	Vector2 halfSize = _texture->GetSize();
	halfSize.x /= _frameBuffer->_data.maxFrame.x;
	halfSize.y /= _frameBuffer->_data.maxFrame.y;

	{
		_vertices.emplace_back(-halfSize.x, halfSize.y, 0.0f, 0.0f); // 왼쪽 위
		_vertices.emplace_back(halfSize.x, halfSize.y, 1.0f, 0.0f);  // 오른쪽 위
		_vertices.emplace_back(-halfSize.x, -halfSize.y, 0.0f, 1.0f);  // 왼쪽 아래
		_vertices.emplace_back(halfSize.x, -halfSize.y, 1.0f, 1.0f);  // 오른쪽 아래
	}

	_indicies.emplace_back(0);     // 왼쪽 위
	_indicies.emplace_back(1);     // 오른쪽 위
	_indicies.emplace_back(2);     // 왼쪽 아래

	_indicies.emplace_back(1);     // 오른쪽 위
	_indicies.emplace_back(3);     // 오른쪽 아래
	_indicies.emplace_back(2);     // 왼쪽 아래
}

void Sprite::CreateShader()
{
	_vertexShader = make_shared<VertexShader>(L"Sprite/SpriteVS");
	_pixelShader = make_shared<PixelShader>(L"Sprite/SpritePS");
}

void Sprite::CreateBuffer()
{
	_frameBuffer = make_shared<FrameBuffer>();
	_frameBuffer->_data.maxFrame.x = _maxFrame.x;
	_frameBuffer->_data.maxFrame.y = _maxFrame.y;
	
	_actionBuffer = make_shared<ActionBuffer>();
	/*_actionBuffer->_data.maxSize = _texture->GetSize();*/
	_actionBuffer->_data.maxSize.x = _texture->GetSize().x;
	_actionBuffer->_data.maxSize.y = _texture->GetSize().y;

	CreateVertices();
	UINT stride = sizeof(VertexUV);

	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), stride, _vertices.size());
	_indexBuffer = make_shared<IndexBuffer>(_indicies.data(), stride, _indicies.size());

}
