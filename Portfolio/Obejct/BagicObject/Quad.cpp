#include "framework.h"
#include "Quad.h"

Quad::Quad(wstring file, wstring vs, wstring ps)
{
    _texture = TextureAdd(file);
    _vertexShader = ShaderManager::GetInstance()->AddVS(vs);
    _pixelShader = ShaderManager::GetInstance()->AddPS(ps);
	CreateBuffer();
	
    _transform = make_shared<Transform>();
}

Quad::Quad(wstring file, float size, wstring ps)
{
    _size = size;
    _texture = TextureAdd(file);
    CreateShader(ps);
    CreateBuffer();

    _transform = make_shared<Transform>();
}

Quad::~Quad()
{
}

void Quad::Update()
{
    _transform->Update();
}

void Quad::Render()
{
    _transform->SetWorldBuffer(0);

    _vertexBuffer->Set(0);
    _indexBuffer->Set();

    DEVICE_CONTEXT->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    _vertexShader->Set();
    _pixelShader->Set();

    _texture->Set(0);
    //SAMPLER->SetState();
    AlphaBlendState->SetState();

    DEVICE_CONTEXT->DrawIndexed(_indicies.size(), 0, 0);
}

void Quad::CreateVertices()
{
    VertexUV v;

    // 1280 720
    // 640 360
    if (_size == 0)
        halfsize.x = _texture->GetSize().x;
    else
    {
        halfsize.x = _texture->GetSize().x;
        halfsize.x /= _size;
    }
        halfsize.y = _texture->GetSize().y;
    {
        v.pos = XMFLOAT3(-halfsize.x, halfsize.y, 0.0f);
        v.uv = { 0.0f, 0.0f };
        _vertices.emplace_back(v);

        // 오른쪽 위
        v.pos = XMFLOAT3(halfsize.x, halfsize.y, 0.0f);
        v.uv = { 1.0f, 0.0f };
        _vertices.emplace_back(v);

        // 왼쪽 아래
        v.pos = XMFLOAT3(-halfsize.x, -halfsize.y, 0.0f);
        v.uv = { 0.0, 1.0f };
        _vertices.emplace_back(v);

        // 오른쪽 아래
        v.pos = XMFLOAT3(halfsize.x, -halfsize.y, 0.0f);
        v.uv = { 1.0f, 1.0f };
        _vertices.emplace_back(v);

        _indicies.emplace_back(0);     // 왼쪽 위
        _indicies.emplace_back(1);     // 오른쪽 위
        _indicies.emplace_back(2);     // 왼쪽 아래

        _indicies.emplace_back(1);     // 오른쪽 위
        _indicies.emplace_back(3);     // 오른쪽 아래
        _indicies.emplace_back(2);     // 왼쪽 아래
    }
}

void Quad::CreateBuffer()
{
	CreateVertices();
	UINT stride = sizeof(VertexUV);

	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), stride, _vertices.size());
	_indexBuffer = make_shared<IndexBuffer>(_indicies.data(), stride, _indicies.size());
}

void Quad::CreateShader(wstring ps)
{
    _vertexShader = make_shared<VertexShader>(L"WVPVertexShader");
    _pixelShader = make_shared<PixelShader>(ps);
}



