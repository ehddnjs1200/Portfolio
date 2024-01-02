#pragma once
class Quad
{
public:
	Quad() {}
	Quad(wstring file, wstring ps = L"WVPPixelShader");

	virtual ~Quad();

	virtual void Update();
	virtual void Render();

	shared_ptr<Transform> GetTransForm() {return _transform;}
	Vector2 GetTextureSize()
	{ return Vector2(_texture->GetSize().x * _transform->GetScale().x,
	                 _texture->GetSize().y * _transform->GetScale().y);
	}

protected:
	virtual void CreateVertices();

private:
	void CreateShader(wstring ps);
	void CreateBuffer();

protected:
	vector<VertexUV> _vertices;
	vector<UINT> _indicies;

	shared_ptr<VertexBuffer>	_vertexBuffer;
	shared_ptr<IndexBuffer>		_indexBuffer;

	shared_ptr<VertexShader>	_vertexShader;
	shared_ptr<PixelShader>		_pixelShader;

	shared_ptr<Transform> _transform;
	shared_ptr<SRV> _texture;

};

